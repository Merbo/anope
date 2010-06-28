/* ChanServ core functions
 *
 * (C) 2003-2010 Anope Team
 * Contact us at team@anope.org
 *
 * Please read COPYING and README for further details.
 *
 * Based on the original code of Epona by Lara.
 * Based on the original code of Services by Andy Church.
 */

/*************************************************************************/

#include "module.h"

class CommandCSSetEMail : public Command
{
 public:
	CommandCSSetEMail(const ci::string &cname, const ci::string &cpermission = "") : Command(cname, 1, 2, cpermission)
	{
	}

	CommandReturn Execute(User *u, const std::vector<ci::string> &params)
	{
		ChannelInfo *ci = cs_findchan(params[0]);
		assert(ci);

		if (ci->email)
			delete [] ci->email;
		if (params.size() > 1)
		{
			ci->email = sstrdup(params[1].c_str());
			notice_lang(Config.s_ChanServ, u, CHAN_EMAIL_CHANGED, ci->name.c_str(), ci->email);
		}
		else
		{
			ci->email = NULL;
			notice_lang(Config.s_ChanServ, u, CHAN_EMAIL_UNSET, ci->name.c_str());
		}

		return MOD_CONT;
	}

	bool OnHelp(User *u, const ci::string &)
	{
		notice_help(Config.s_ChanServ, u, CHAN_HELP_SET_EMAIL, "SET");
		return true;
	}

	void OnSyntaxError(User *u, const ci::string &)
	{
		// XXX
		syntax_error(Config.s_ChanServ, u, "SET", CHAN_SET_SYNTAX);
	}

	void OnServHelp(User *u)
	{
		notice_lang(Config.s_ChanServ, u, CHAN_HELP_CMD_SET_EMAIL);
	}
};

class CommandCSSASetEMail : public CommandCSSetEMail
{
 public:
	CommandCSSASetEMail(const ci::string &cname) : CommandCSSetEMail(cname, "chanserv/saset/email")
	{
	}

	bool OnHelp(User *u, const ci::string &)
	{
		notice_help(Config.s_ChanServ, u, CHAN_HELP_SET_EMAIL, "SASET");
		return true;
	}

	void OnSyntaxError(User *u, const ci::string &)
	{
		/// XXX
		syntax_error(Config.s_ChanServ, u, "SASET", CHAN_SASET_SYNTAX);
	}
};

class CSSetEMail : public Module
{
 public:
	CSSetEMail(const std::string &modname, const std::string &creator) : Module(modname, creator)
	{
		this->SetAuthor("Anope");
		this->SetType(CORE);

		Command *c = FindCommand(ChanServ, "SET");
		if (c)
			c->AddSubcommand(new CommandCSSetEMail("EMAIL"));
	}

	~CSSetEMail()
	{
		Command *c = FindCommand(ChanServ, "SET");
		if (c)
			c->DelSubcommand("EMAIL");
	}
};

MODULE_INIT(CSSetEMail)