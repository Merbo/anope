#include "services.h"
#include "modules.h"

#define HASH(nick)       ((tolower((nick)[0])&31)<<5 | (tolower((nick)[1])&31))

NickRequest::NickRequest(const std::string &nickname)
{
	if (nickname.empty())
		throw CoreException("Empty nick passed to NickRequest constructor");

	next = prev = NULL;
	email = NULL;
	requested = lastmail = 0;

	this->nick = sstrdup(nickname.c_str());
	insert_requestnick(this); // till this is destroyed / redone in STL
}

NickRequest::~NickRequest()
{
	FOREACH_MOD(I_OnDelNickRequest, OnDelNickRequest(this));

	if (this->next)
		this->next->prev = this->prev;
	if (this->prev)
		this->prev->next = this->next;
	else
		nrlists[HASH(this->nick)] = this->next;
	
	if (this->nick)
		delete [] this->nick;
	if (this->email)
		delete [] this->email;
}

/** Default constructor
 * @param nick The nick
 * @param nickcore The nickcofe for this nick
 */
NickAlias::NickAlias(const std::string &nickname, NickCore *nickcore)
{
	if (nickname.empty())
		throw CoreException("Empty nick passed to NickAlias constructor");
	else if (!nickcore)
		throw CoreException("Empty nickcore passed to NickAlias constructor");

	next = prev = NULL;
	nick = last_quit = last_realname = last_usermask = NULL;
	time_registered = last_seen = 0;
	
	this->nick = sstrdup(nickname.c_str());
	this->nc = nickcore;
	slist_add(&nc->aliases, this);
	alpha_insert_alias(this);

	for (std::list<std::pair<std::string, std::string> >::iterator it = Config.Opers.begin(); it != Config.Opers.end(); it++)
	{
		if (nc->ot)
			break;
		if (!stricmp(it->first.c_str(), this->nick))
			continue;

		for (std::list<OperType *>::iterator tit = Config.MyOperTypes.begin(); tit != Config.MyOperTypes.end(); tit++)
		{	
			OperType *ot = *tit;

			if (ot->GetName() == it->second)
			{
				Alog() << "Tied oper " << nc->display << " to type " << ot->GetName();
				nc->ot = ot;
				break;
			}
		}
	}
}

/** Default destructor
 */
NickAlias::~NickAlias()
{
	User *u = NULL;

	/* First thing to do: remove any timeout belonging to the nick we're deleting */
	NickServCollide::ClearTimers(this);
	NickServRelease::ClearTimers(this, true);

	FOREACH_MOD(I_OnDelNick, OnDelNick(this));

	/* Second thing to do: look for an user using the alias
	 * being deleted, and make appropriate changes */
	if ((u = finduser(this->nick)) && u->Account())
	{
		ircdproto->SendAccountLogout(u, u->Account());
		ircdproto->SendUnregisteredNick(u);
		u->Logout();
	}

	/* Accept nicks that have no core, because of database load functions */
	if (this->nc)
	{
		/* Next: see if our core is still useful. */
		slist_remove(&this->nc->aliases, this);
		if (this->nc->aliases.count == 0)
		{
			delete this->nc;
			this->nc = NULL;
		}
		else
		{
			/* Display updating stuff */
			if (!stricmp(this->nick, this->nc->display))
				change_core_display(this->nc);
		}
	}

	/* Remove us from the aliases list */
	if (this->next)
		this->next->prev = this->prev;
	if (this->prev)
		this->prev->next = this->next;
	else
		nalists[HASH(this->nick)] = this->next;

	delete [] this->nick;
	if (this->last_usermask)
		delete [] this->last_usermask;
	if (this->last_realname)
		delete [] this->last_realname;
	if (this->last_quit)
		delete [] this->last_quit;
}

