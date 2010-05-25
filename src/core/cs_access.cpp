/* ChanServ core functions
 *
 * (C) 2003-2010 Anope Team
 * Contact us at team@anope.org
 *
 * Please read COPYING and README for further details.
 *
 * Based on the original code of Epona by Lara.
 * Based on the original code of Services by Andy Church.
 *
 *
 */
/*************************************************************************/

#include "module.h"

class AccessListCallback : public NumberList
{
 protected:
	User *u;
	ChannelInfo *ci;
	bool SentHeader;
 public:
	AccessListCallback(User *_u, ChannelInfo *_ci, const std::string &numlist) : NumberList(numlist), u(_u), ci(_ci), SentHeader(false)
	{
	}

	~AccessListCallback()
	{
		if (SentHeader)
			notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_LIST_FOOTER, ci->name.c_str());
		else
			notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_NO_MATCH, ci->name.c_str());
	}

	virtual void HandleNumber(unsigned Number)
	{
		if (Number > ci->GetAccessCount())
			return;

		if (!SentHeader)
		{
			SentHeader = true;
			notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_LIST_HEADER, ci->name.c_str());
		}

		DoList(u, ci, Number - 1, ci->GetAccess(Number - 1));
	}

	static void DoList(User *u, ChannelInfo *ci, unsigned Number, ChanAccess *access)
	{
		if (ci->HasFlag(CI_XOP))
		{
			const char *xop = get_xop_level(access->level);
			notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_LIST_XOP_FORMAT, Number + 1, xop, access->nc->display);
		}
		else
			notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_LIST_AXS_FORMAT, Number + 1, access->level, access->nc->display);
	}
};

class AccessViewCallback : public AccessListCallback
{
 public:
	AccessViewCallback(User *_u, ChannelInfo *_ci, const std::string &numlist) : AccessListCallback(_u, _ci, numlist)
	{
	}

	void HandleNumber(unsigned Number)
	{
		if (Number > ci->GetAccessCount())
			return;

		if (!SentHeader)
		{
			SentHeader = true;
			notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_LIST_HEADER, ci->name.c_str());
		}

		DoList(u, ci, Number - 1, ci->GetAccess(Number - 1));
	}

	static void DoList(User *u, ChannelInfo *ci, unsigned Number, ChanAccess *access)
	{
		char timebuf[64];
		struct tm tm;

		memset(&timebuf, 0, sizeof(timebuf));
		if (ci->c && u->Account() && nc_on_chan(ci->c, u->Account()))
			snprintf(timebuf, sizeof(timebuf), "Now");
		else if (access->last_seen == 0)
			snprintf(timebuf, sizeof(timebuf), "Never");
		else
		{
			tm = *localtime(&access->last_seen);
			strftime_lang(timebuf, sizeof(timebuf), u, STRFTIME_DATE_TIME_FORMAT, &tm);
		}

		if (ci->HasFlag(CI_XOP))
		{
			const char *xop = get_xop_level(access->level);
			notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_VIEW_XOP_FORMAT, Number + 1, xop, access->nc->display, access->creator.c_str(), timebuf);
		}
		else
			notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_VIEW_AXS_FORMAT, Number + 1, access->level, access->nc->display, access->creator.c_str(), timebuf);
	}
};

class AccessDelCallback : public NumberList
{
	User *u;
	ChannelInfo *ci;
	unsigned Deleted;
	std::string Nicks;
	bool Denied;
 public:
	AccessDelCallback(User *_u, ChannelInfo *_ci, const std::string &numlist) : NumberList(numlist), u(_u), ci(_ci), Deleted(0), Denied(false)
	{
	}

	~AccessDelCallback()
	{
		if (Denied && !Deleted)
			notice_lang(Config.s_ChanServ, u, ACCESS_DENIED);
		else if (!Deleted)
			notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_NO_MATCH, ci->name.c_str());
		else
		{
			Alog() << Config.s_ChanServ << ": " << u->GetMask() << " (level " << get_access(u, ci) << ") deleted access of user" << (Deleted == 1 ? " " : "s ") << Nicks << " on " << ci->name;

			if (Deleted == 1)
				notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_DELETED_ONE, ci->name.c_str());
			else
				notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_DELETED_SEVERAL, Deleted, ci->name.c_str());
		}
	}

	void HandleNumber(unsigned Number)
	{
		if (Number > ci->GetAccessCount())
			return;

		ChanAccess *access = ci->GetAccess(Number - 1);

		if (get_access(u, ci) <= access->level && !u->Account()->HasPriv("chanserv/access/modify"))
		{
			Denied = true;
			return;
		}

		++Deleted;
		if (!Nicks.empty())
			Nicks += ", " + std::string(access->nc->display);
		else
			Nicks = access->nc->display;
		
		FOREACH_MOD(I_OnAccessDel, OnAccessDel(ci, u, access->nc));

		ci->EraseAccess(Number - 1);
	}
};

class CommandCSAccess : public Command
{
 public:
	CommandCSAccess() : Command("ACCESS", 2, 4)
	{
	}

	CommandReturn Execute(User *u, const std::vector<ci::string> &params)
	{
		const char *chan = params[0].c_str();
		ci::string cmd = params[1];
		const char *nick = params.size() > 2 ? params[2].c_str() : NULL;
		const char *s = params.size() > 3 ? params[3].c_str() : NULL;

		ChannelInfo *ci = cs_findchan(chan);
		NickAlias *na = NULL;
		NickCore *nc;
		ChanAccess *access;

		unsigned i;
		int level = 0, ulev;
		bool is_list = cmd == "LIST" || cmd == "VIEW";

		/* If LIST, we don't *require* any parameters, but we can take any.
		 * If DEL, we require a nick and no level.
		 * Else (ADD), we require a level (which implies a nick). */
		if (is_list || cmd == "CLEAR" ? 0 : (cmd == "DEL" ? (!nick || s) : !s))
			this->OnSyntaxError(u, cmd);
		/* We still allow LIST in xOP mode, but not others */
		else if ((ci->HasFlag(CI_XOP)) && !is_list)
		{
			if (ModeManager::FindChannelModeByName(CMODE_HALFOP))
				notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_XOP_HOP, Config.s_ChanServ);
			else
				notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_XOP, Config.s_ChanServ);
		}
		else if ((
				 (is_list && !check_access(u, ci, CA_ACCESS_LIST) && !u->Account()->HasCommand("chanserv/access/list"))
				 ||
				 (!is_list && !check_access(u, ci, CA_ACCESS_CHANGE) && !u->Account()->HasPriv("chanserv/access/modify"))
				))
			notice_lang(Config.s_ChanServ, u, ACCESS_DENIED);
		else if (cmd == "ADD")
		{
			if (readonly)
			{
				notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_DISABLED);
				return MOD_CONT;
			}

			level = atoi(s);
			ulev = get_access(u, ci);

			if (level >= ulev && !u->Account()->HasPriv("chanserv/access/modify"))
			{
				notice_lang(Config.s_ChanServ, u, ACCESS_DENIED);
				return MOD_CONT;
			}

			if (!level)
			{
				notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_LEVEL_NONZERO);
				return MOD_CONT;
			}
			else if (level <= ACCESS_INVALID || level >= ACCESS_FOUNDER)
			{
				notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_LEVEL_RANGE, ACCESS_INVALID + 1, ACCESS_FOUNDER - 1);
				return MOD_CONT;
			}

			na = findnick(nick);
			if (!na)
			{
				notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_NICKS_ONLY);
				return MOD_CONT;
			}
			else if (na->HasFlag(NS_FORBIDDEN))
			{
				notice_lang(Config.s_ChanServ, u, NICK_X_FORBIDDEN, nick);
				return MOD_CONT;
			}

			nc = na->nc;
			access = ci->GetAccess(nc);
			if (access)
			{
				/* Don't allow lowering from a level >= ulev */
				if (access->level >= ulev && !u->Account()->HasPriv("chanserv/access/modify"))
				{
					notice_lang(Config.s_ChanServ, u, ACCESS_DENIED);
					return MOD_CONT;
				}
				if (access->level == level)
				{
					notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_LEVEL_UNCHANGED, access->nc->display, chan, level);
					return MOD_CONT;
				}
				access->level = level;

				FOREACH_MOD(I_OnAccessChange, OnAccessChange(ci, u, na->nc, level));

				Alog() << Config.s_ChanServ << ": " << u->GetMask() << " (level " << ulev << ") set access level "
					<< access->level << " to " << na->nick << " (group " << nc->display << ") on channel " << ci->name;
				notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_LEVEL_CHANGED, nc->display, chan, level);
				return MOD_CONT;
			}

			if (ci->GetAccessCount() >= Config.CSAccessMax)
			{
				notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_REACHED_LIMIT, Config.CSAccessMax);
				return MOD_CONT;
			}

			ci->AddAccess(nc, level, u->nick);

			FOREACH_MOD(I_OnAccessAdd, OnAccessAdd(ci, u, nc, level));

			Alog() << Config.s_ChanServ << ": " << u->GetMask() << " (level " << ulev << ") set access level "
				<< level << " to " << na->nick << " (group " << nc->display << ") on channel " << ci->name;
			notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_ADDED, nc->display, ci->name.c_str(), level);
		}
		else if (cmd == "DEL")
		{
			if (readonly)
			{
				notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_DISABLED);
				return MOD_CONT;
			}

			if (!ci->GetAccessCount())
			{
				notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_LIST_EMPTY, chan);
				return MOD_CONT;
			}

			/* Special case: is it a number/list?  Only do search if it isn't. */
			if (isdigit(*nick) && strspn(nick, "1234567890,-") == strlen(nick))
				(new AccessDelCallback(u, ci, nick))->Process();
			else
			{
				na = findnick(nick);
				if (!na)
				{
					notice_lang(Config.s_ChanServ, u, NICK_X_NOT_REGISTERED, nick);
					return MOD_CONT;
				}

				nc = na->nc;

				for (i = 0; i < ci->GetAccessCount(); ++i)
				{
					access = ci->GetAccess(i);

					if (access->nc == nc)
						break;
				}

				if (i == ci->GetAccessCount())
				{
					notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_NOT_FOUND, nick, chan);
					return MOD_CONT;
				}

				if (get_access(u, ci) <= access->level && !u->Account()->HasPriv("chanserv/access/modify"))
				{
					notice_lang(Config.s_ChanServ, u, ACCESS_DENIED);
				}
				else
				{
					notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_DELETED, access->nc->display, ci->name.c_str());
					Alog() << Config.s_ChanServ << ": " << u->GetMask() << " (level " << get_access(u, ci)
						<< ") deleted access of " << na->nick << " (group " << access->nc->display << ") on " << chan;
					FOREACH_MOD(I_OnAccessDel, OnAccessDel(ci, u, na->nc));

					ci->EraseAccess(i);
				}
			}
		}
		else if (cmd == "LIST")
		{
			if (!ci->GetAccessCount())
			{
				notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_LIST_EMPTY, chan);
				return MOD_CONT;
			}
			if (nick && strspn(nick, "1234567890,-") == strlen(nick))
				(new AccessListCallback(u, ci, nick))->Process();
			else
			{
				bool SentHeader = false;

				for (i = 0; i < ci->GetAccessCount(); i++)
				{
					access = ci->GetAccess(i);

					if (nick && access->nc && !Anope::Match(access->nc->display, nick, false))
						continue;

					if (!SentHeader)
					{
						SentHeader = true;
						notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_LIST_HEADER, ci->name.c_str());
					}

					AccessListCallback::DoList(u, ci, i, access);
				}

				if (SentHeader)
					notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_LIST_FOOTER, ci->name.c_str());
				else
					notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_NO_MATCH, chan);
			}
		}
		else if (cmd == "VIEW")
		{
			if (!ci->GetAccessCount())
			{
				notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_LIST_EMPTY, chan);
				return MOD_CONT;
			}
			if (nick && strspn(nick, "1234567890,-") == strlen(nick))
				(new AccessViewCallback(u, ci, nick))->Process();
			else
			{
				bool SentHeader = false;

				for (i = 0; i < ci->GetAccessCount(); ++i)
				{
					access = ci->GetAccess(i);

					if (nick && access->nc && !Anope::Match(access->nc->display, nick, false))
						continue;

					if (!SentHeader)
					{
						SentHeader = true;
						notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_LIST_HEADER, ci->name.c_str());
					}

					AccessViewCallback::DoList(u, ci, i, access);
				}

				if (SentHeader)
					notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_LIST_FOOTER, ci->name.c_str());
				else
					notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_NO_MATCH, chan);
			}
		}
		else if (cmd == "CLEAR")
		{
			if (readonly)
			{
				notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_DISABLED);
				return MOD_CONT;
			}

			if (!check_access(u, ci, CA_FOUNDER) && !u->Account()->HasPriv("chanserv/access/modify"))
			{
				notice_lang(Config.s_ChanServ, u, ACCESS_DENIED);
				return MOD_CONT;
			}

			ci->ClearAccess();

			FOREACH_MOD(I_OnAccessClear, OnAccessClear(ci, u));

			notice_lang(Config.s_ChanServ, u, CHAN_ACCESS_CLEAR, ci->name.c_str());
			Alog() << Config.s_ChanServ << ": " << u->GetMask() << " (level " << get_access(u, ci) << " cleared access list on " << chan;
		}
		else
			this->OnSyntaxError(u, "");
		return MOD_CONT;
	}

	bool OnHelp(User *u, const ci::string &subcommand)
	{
		notice_help(Config.s_ChanServ, u, CHAN_HELP_ACCESS);
		notice_help(Config.s_ChanServ, u, CHAN_HELP_ACCESS_LEVELS);
		return true;
	}

	void OnSyntaxError(User *u, const ci::string &subcommand)
	{
		syntax_error(Config.s_ChanServ, u, "ACCESS", CHAN_ACCESS_SYNTAX);
	}
};


class CommandCSLevels : public Command
{
 public:
	CommandCSLevels() : Command("LEVELS", 2, 4)
	{
	}

	CommandReturn Execute(User *u, const std::vector<ci::string> &params)
	{
		const char *chan = params[0].c_str();
		ci::string cmd = params[1];
		const char *what = params.size() > 2 ? params[2].c_str() : NULL;
		const char *s = params.size() > 3 ? params[3].c_str() : NULL;
		char *error;

		ChannelInfo *ci = cs_findchan(chan);
		int level;
		int i;

		/* If SET, we want two extra parameters; if DIS[ABLE] or FOUNDER, we want only
		 * one; else, we want none.
		 */
		if (cmd == "SET" ? !s : (cmd.substr(0, 3) == "DIS" ? (!what || s) : !!what))
			this->OnSyntaxError(u, cmd);
		else if (ci->HasFlag(CI_XOP))
			notice_lang(Config.s_ChanServ, u, CHAN_LEVELS_XOP);
		else if (!check_access(u, ci, CA_FOUNDER) && !u->Account()->HasPriv("chanserv/access/modify"))
			notice_lang(Config.s_ChanServ, u, ACCESS_DENIED);
		else if (cmd == "SET") {
			level = strtol(s, &error, 10);

			if (!stricmp(s, "FOUNDER"))
			{
				level = ACCESS_FOUNDER;
				*error = '\0';
			}

			if (*error != '\0') {
				this->OnSyntaxError(u, "SET");
				return MOD_CONT;
			}

			if (level <= ACCESS_INVALID || level > ACCESS_FOUNDER) {
				notice_lang(Config.s_ChanServ, u, CHAN_LEVELS_RANGE,
							ACCESS_INVALID + 1, ACCESS_FOUNDER - 1);
				return MOD_CONT;
			}

			for (i = 0; levelinfo[i].what >= 0; i++) {
				if (stricmp(levelinfo[i].name, what) == 0) {
					ci->levels[levelinfo[i].what] = level;
					FOREACH_MOD(I_OnLevelChange, OnLevelChange(u, ci, i, level));
					Alog() << Config.s_ChanServ << ": " << u->GetMask() << " set level " << levelinfo[i].name
						<< " on channel " << ci->name << " to " << level;
					if (level == ACCESS_FOUNDER)
						notice_lang(Config.s_ChanServ, u, CHAN_LEVELS_CHANGED_FOUNDER, levelinfo[i].name, ci->name.c_str());
					else
						notice_lang(Config.s_ChanServ, u, CHAN_LEVELS_CHANGED,
								levelinfo[i].name, ci->name.c_str(), level);
					return MOD_CONT;
				}
			}

			notice_lang(Config.s_ChanServ, u, CHAN_LEVELS_UNKNOWN, what, Config.s_ChanServ);

		} else if (cmd == "DIS" || cmd == "DISABLE") {
			/* Don't allow disabling of the founder level. It would be hard to change it back if you dont have access to use this command */
			if (stricmp(what, "FOUNDER"))
			{
				for (i = 0; levelinfo[i].what >= 0; i++) {
					if (stricmp(levelinfo[i].name, what) == 0) {
						ci->levels[levelinfo[i].what] = ACCESS_INVALID;
						FOREACH_MOD(I_OnLevelChange, OnLevelChange(u, ci, i, levelinfo[i].what));
	
						Alog() << Config.s_ChanServ << ": " << u->GetMask() << " disabled level " << levelinfo[i].name
							<< " on channel " << ci->name;
						notice_lang(Config.s_ChanServ, u, CHAN_LEVELS_DISABLED,
									levelinfo[i].name, chan);
						return MOD_CONT;
					}
				}
			}

			notice_lang(Config.s_ChanServ, u, CHAN_LEVELS_UNKNOWN, what, Config.s_ChanServ);
		} else if (cmd == "LIST") {
			notice_lang(Config.s_ChanServ, u, CHAN_LEVELS_LIST_HEADER, chan);

			if (!levelinfo_maxwidth) {
				for (i = 0; levelinfo[i].what >= 0; i++) {
					int len = strlen(levelinfo[i].name);
					if (len > levelinfo_maxwidth)
						levelinfo_maxwidth = len;
				}
			}

			for (i = 0; levelinfo[i].what >= 0; i++) {
				int j = ci->levels[levelinfo[i].what];

				if (j == ACCESS_INVALID) {
					j = levelinfo[i].what;

					if (j == CA_AUTOOP || j == CA_AUTODEOP || j == CA_AUTOVOICE
						|| j == CA_NOJOIN) {
						notice_lang(Config.s_ChanServ, u, CHAN_LEVELS_LIST_DISABLED,
									levelinfo_maxwidth, levelinfo[i].name);
					} else {
						notice_lang(Config.s_ChanServ, u, CHAN_LEVELS_LIST_DISABLED,
									levelinfo_maxwidth, levelinfo[i].name);
					}
				} else if (j == ACCESS_FOUNDER) {
					notice_lang(Config.s_ChanServ, u, CHAN_LEVELS_LIST_FOUNDER,
								levelinfo_maxwidth, levelinfo[i].name);
				} else {
					notice_lang(Config.s_ChanServ, u, CHAN_LEVELS_LIST_NORMAL,
								levelinfo_maxwidth, levelinfo[i].name, j);
				}
			}

		} else if (cmd == "RESET") {
			reset_levels(ci);
			FOREACH_MOD(I_OnLevelChange, OnLevelChange(u, ci, -1, 0));

			Alog() << Config.s_ChanServ << ": " << u->GetMask() << " reset levels definitions on channel " << ci->name;
			notice_lang(Config.s_ChanServ, u, CHAN_LEVELS_RESET, chan);
		} else {
			this->OnSyntaxError(u, "");
		}
		return MOD_CONT;
	}

	bool OnHelp(User *u, const ci::string &subcommand)
	{
		notice_help(Config.s_ChanServ, u, CHAN_HELP_LEVELS);
		return true;
	}

	void OnSyntaxError(User *u, const ci::string &subcommand)
	{
		syntax_error(Config.s_ChanServ, u, "LEVELS", CHAN_LEVELS_SYNTAX);
	}
};


class CSAccess : public Module
{
 public:
	CSAccess(const std::string &modname, const std::string &creator) : Module(modname, creator)
	{
		this->SetAuthor("Anope");
		this->SetVersion(VERSION_STRING);
		this->SetType(CORE);

		this->AddCommand(ChanServ, new CommandCSAccess());
		this->AddCommand(ChanServ, new CommandCSLevels());

		ModuleManager::Attach(I_OnChanServHelp, this);
	}
	void OnChanServHelp(User *u)
	{
		notice_lang(Config.s_ChanServ, u, CHAN_HELP_CMD_ACCESS);
		notice_lang(Config.s_ChanServ, u, CHAN_HELP_CMD_LEVELS);
	}
};


MODULE_INIT(CSAccess)