/*
 * (C) 2003-2013 Anope Team
 * Contact us at team@anope.org
 *
 * Please read COPYING and README for further details.
 */

#include "module.h"
#include "modules/httpd.h"
#include "modules/ssl.h"

static Anope::string BuildDate()
{
	char timebuf[64];
	struct tm *tm = localtime(&Anope::CurTime);
	strftime(timebuf, sizeof(timebuf), "%a, %d %b %Y %H:%M:%S %Z", tm);
	return timebuf;
}

static Anope::string GetStatusFromCode(HTTPError err)
{
	switch (err)
	{
		case HTTP_ERROR_OK:
			return "200 OK";
		case HTTP_FOUND:
			return "302 Found";
		case HTTP_BAD_REQUEST:
			return "400 Bad Request";
		case HTTP_PAGE_NOT_FOUND:
			return "404 Not Found";
		case HTTP_NOT_SUPPORTED:
			return "505 HTTP Version Not Supported";
	}

	return "501 Not Implemented";
}

class MyHTTPClient : public HTTPClient
{
	HTTPProvider *provider;
	HTTPMessage header;
	bool header_done, served;
	Anope::string page_name;
	Reference<HTTPPage> page;
	Anope::string ip;

	Anope::string inbuf;
	unsigned content_length;

	enum
	{
		ACTION_NONE,
		ACTION_GET,
		ACTION_POST
	} action;

	void Serve()
	{
		if (this->served)
			return;
		this->served = true;

		if (!this->page)
		{
			this->SendError(HTTP_PAGE_NOT_FOUND, "Page not found");
			return;
		}

		if (this->ip == this->provider->ext_ip)
		{
			for (unsigned i = 0; i < this->provider->ext_headers.size(); ++i)
			{
				const Anope::string &token = this->provider->ext_headers[i];

				if (this->header.headers.count(token))
				{
					this->ip = this->header.headers[token];
					Log(LOG_DEBUG, "httpd") << "m_httpd: IP for connection " << this->GetFD() << " changed to " << this->ip;
					break;
				}
			}
		}

		Log(LOG_DEBUG, "httpd") << "m_httpd: Serving page " << this->page_name << " to " << this->ip;

		HTTPReply reply;
		reply.content_type = this->page->GetContentType();

		if (this->page->OnRequest(this->provider, this->page_name, this, this->header, reply))
			this->SendReply(&reply);
	}

 public:
	time_t created;

	MyHTTPClient(HTTPProvider *l, int f, const sockaddrs &a) : Socket(f, l->IsIPv6()), HTTPClient(l, f, a), provider(l), header_done(false), served(false), ip(a.addr()), content_length(0), action(ACTION_NONE), created(Anope::CurTime)
	{
		Log(LOG_DEBUG, "httpd") << "Accepted connection " << f << " from " << a.addr();
	}

	~MyHTTPClient()
	{
		Log(LOG_DEBUG, "httpd") << "Closing connection " << this->GetFD() << " from " << this->ip;
	}

	const Anope::string GetIP() anope_override
	{
		return this->ip;
	}

	bool Read(const char *buffer, size_t l) anope_override
	{
		inbuf.append(buffer, l);

		for (size_t nl; !this->header_done && (nl = inbuf.find('\n')) != Anope::string::npos;)
		{
			Anope::string token = inbuf.substr(0, nl).trim();
			inbuf = inbuf.substr(nl + 1);

			if (token.empty())
				this->header_done = true;
			else
				this->Read(token);
		}

		if (!this->header_done)
			return true;

		if (this->inbuf.length() >= this->content_length)
		{
			sepstream sep(this->inbuf, '&');
			Anope::string token;

			while (sep.GetToken(token))
			{
				size_t sz = token.find('=');
				if (sz == Anope::string::npos || !sz || sz + 1 >= token.length())
					continue;
				this->header.post_data[token.substr(0, sz)] = HTTPUtils::URLDecode(token.substr(sz + 1));
				Log(LOG_DEBUG_2) << "HTTP POST from " << this->clientaddr.addr() << ": " << token.substr(0, sz) << ": " << this->header.post_data[token.substr(0, sz)];
			}

			this->Serve();
		}
		
		return true;
	}

	bool Read(const Anope::string &buf)
	{
		Log(LOG_DEBUG_2) << "HTTP from " << this->clientaddr.addr() << ": " << buf;

		if (this->action == ACTION_NONE)
		{
			std::vector<Anope::string> params;
			spacesepstream(buf).GetTokens(params);

			if (params.empty() || (params[0] != "GET" && params[0] != "POST"))
			{
				this->SendError(HTTP_BAD_REQUEST, "Unknown operation");
				return true;
			}

			if (params.size() != 3)
			{
				this->SendError(HTTP_BAD_REQUEST, "Invalid parameters");
				return true;
			}

			if (params[0] == "GET")
				this->action = ACTION_GET;
			else if (params[0] == "POST")
				this->action = ACTION_POST;

			Anope::string targ = params[1];
			size_t q = targ.find('?');
			if (q != Anope::string::npos)
			{
				sepstream sep(targ.substr(q + 1), '&');
				targ = targ.substr(0, q);

				Anope::string token;
				while (sep.GetToken(token))
				{
					size_t sz = token.find('=');
					if (sz == Anope::string::npos || !sz || sz + 1 >= token.length())
						continue;
					this->header.get_data[token.substr(0, sz)] = HTTPUtils::URLDecode(token.substr(sz + 1));
				}
			}

			this->page = this->provider->FindPage(targ);
			this->page_name = targ;
		}
		else if (buf.find("Cookie: ") == 0)
		{
			spacesepstream sep(buf.substr(8));
			Anope::string token;

			while (sep.GetToken(token))
			{
				size_t sz = token.find('=');
				if (sz == Anope::string::npos || !sz || sz + 1 >= token.length())
					continue;
				size_t end = token.length() - (sz + 1);
				if (!sep.StreamEnd())
					--end; // Remove trailing ;
				this->header.cookies[token.substr(0, sz)] = token.substr(sz + 1, end);
			}
		}
		else if (buf.find("Content-Length: ") == 0)
		{
			try
			{
				this->content_length = convertTo<unsigned>(buf.substr(16));
			}
			catch (const ConvertException &ex) { }
		}
		else if (buf.find(':') != Anope::string::npos)
		{
			size_t sz = buf.find(':');
			if (sz + 2 < buf.length())
				this->header.headers[buf.substr(0, sz)] = buf.substr(sz + 2);
		}

		return true;
	}

	void SendError(HTTPError err, const Anope::string &msg) anope_override
	{
		HTTPReply h;

		h.error = err;

		h.Write(msg);

		this->SendReply(&h);
	}

	void SendReply(HTTPReply *message) anope_override
	{
		this->WriteClient("HTTP/1.1 " + GetStatusFromCode(message->error));
		this->WriteClient("Date: " + BuildDate());
		this->WriteClient("Server: Anope-" + Anope::VersionShort());
		if (message->content_type.empty())
			this->WriteClient("Content-Type: text/html");
		else
			this->WriteClient("Content-Type: " + message->content_type);
		this->WriteClient("Content-Length: " + stringify(message->length));

		for (unsigned i = 0; i < message->cookies.size(); ++i)
		{
			Anope::string buf = "Set-Cookie:";

			for (HTTPReply::cookie::iterator it = message->cookies[i].begin(), it_end = message->cookies[i].end(); it != it_end; ++it)
				buf += " " + it->first + "=" + it->second + ";";

			buf.erase(buf.length() - 1);

			this->WriteClient(buf);
		}

		typedef std::map<Anope::string, Anope::string> map;
		for (map::iterator it = message->headers.begin(), it_end = message->headers.end(); it != it_end; ++it)
			this->WriteClient(it->first + ": " + it->second);

		this->WriteClient("Connection: Close");
		this->WriteClient("");

		for (unsigned i = 0; i < message->out.size(); ++i)
		{
			HTTPReply::Data* d = message->out[i];

			this->Write(d->buf, d->len);

			delete d;
		}

		message->out.clear();
	}
};

class MyHTTPProvider : public HTTPProvider, public Timer
{
	int timeout;
	std::map<Anope::string, HTTPPage *> pages;
	std::list<Reference<MyHTTPClient> > clients;

 public:
	MyHTTPProvider(Module *c, const Anope::string &n, const Anope::string &i, const unsigned short p, const int t, bool s) : Socket(-1, i.find(':') != Anope::string::npos), HTTPProvider(c, n, i, p, s), Timer(c, 10, Anope::CurTime, true), timeout(t) { }

	void Tick(time_t) anope_override
	{
		while (!this->clients.empty())
		{
			Reference<MyHTTPClient>& c = this->clients.front();
			if (c && c->created + this->timeout >= Anope::CurTime)
				break;

			delete c;
			this->clients.pop_front();
		}
	}

	ClientSocket* OnAccept(int fd, const sockaddrs &addr) anope_override
	{
		MyHTTPClient *c = new MyHTTPClient(this, fd, addr);
		this->clients.push_back(c);
		return c;
	}

	bool RegisterPage(HTTPPage *page) anope_override
	{
		return this->pages.insert(std::make_pair(page->GetURL(), page)).second;
	}

	void UnregisterPage(HTTPPage *page) anope_override
	{
		this->pages.erase(page->GetURL());
	}

	HTTPPage* FindPage(const Anope::string &pname)
	{
		if (this->pages.count(pname) == 0)
			return NULL;
		return this->pages[pname];
	}
};

class HTTPD : public Module
{
	ServiceReference<SSLService> sslref;
	std::map<Anope::string, MyHTTPProvider *> providers;
 public:
	HTTPD(const Anope::string &modname, const Anope::string &creator) : Module(modname, creator, EXTRA | VENDOR), sslref("SSLService", "ssl")
	{

	}

	~HTTPD()
	{
		for (std::map<int, Socket *>::const_iterator it = SocketEngine::Sockets.begin(), it_end = SocketEngine::Sockets.end(); it != it_end;)
		{
			Socket *s = it->second;
			++it;

			if (dynamic_cast<MyHTTPProvider *>(s) || dynamic_cast<MyHTTPClient *>(s))
				delete s;
		}

		this->providers.clear();
	}

	void OnReload(Configuration::Conf *config) anope_override
	{
		Configuration::Block *conf = config->GetModule(this);
		std::set<Anope::string> existing;

		for (int i = 0; i < conf->CountBlock("httpd"); ++i)
		{
			Configuration::Block *block = conf->GetBlock("httpd", i);


			const Anope::string &hname = block->Get<const Anope::string>("name", "httpd/main");
			existing.insert(hname);

			Anope::string ip = block->Get<const Anope::string>("ip");
			int port = block->Get<int>("port", "8080");
			int timeout = block->Get<int>("timeout", "30");
			bool ssl = block->Get<bool>("ssl", "no");
			Anope::string ext_ip = block->Get<const Anope::string>("extforward_ip");
			Anope::string ext_header = block->Get<const Anope::string>("extforward_header");

			if (ip.empty())
			{
				Log(this) << "You must configure a bind IP for HTTP server " << hname;
				continue;
			}
			else if (port <= 0 || port > 65535)
			{
				Log(this) << "You must configure a (valid) listen port for HTTP server " << hname;
				continue;
			}

			MyHTTPProvider *p;
			if (this->providers.count(hname) == 0)
			{
				try
				{
					p = new MyHTTPProvider(this, hname, ip, port, timeout, ssl);
					if (ssl && sslref)
						sslref->Init(p);
				}
				catch (const SocketException &ex)
				{
					Log(this) << "Unable to create HTTP server " << hname << ": " << ex.GetReason();
					continue;
				}
				this->providers[hname] = p;

				Log(this) << "Created HTTP server " << hname;
			}
			else
			{
				p = this->providers[hname];

				if (p->GetIP() != ip || p->GetPort() != port)
				{
					delete p;
					this->providers.erase(hname);

					Log(this) << "Changing HTTP server " << hname << " to " << ip << ":" << port;

					try
					{
						p = new MyHTTPProvider(this, hname, ip, port, timeout, ssl);
						if (ssl && sslref)
							sslref->Init(p);
					}
					catch (const SocketException &ex)
					{
						Log(this) << "Unable to create HTTP server " << hname << ": " << ex.GetReason();
						continue;
					}

					this->providers[hname] = p;
				}
			}


			p->ext_ip = ext_ip;
			spacesepstream(ext_header).GetTokens(p->ext_headers);
		}

		for (std::map<Anope::string, MyHTTPProvider *>::iterator it = this->providers.begin(), it_end = this->providers.end(); it != it_end;)
		{
			HTTPProvider *p = it->second;
			++it;

			if (existing.count(p->name) == 0)
			{
				Log(this) << "Removing HTTP server " << p->name;
				this->providers.erase(p->name);
				delete p;
			}
		}
	}

	void OnModuleLoad(User *u, Module *m) anope_override
	{
		if (m->name != "m_ssl")
			return;

		for (std::map<Anope::string, MyHTTPProvider *>::iterator it = this->providers.begin(), it_end = this->providers.end(); it != it_end; ++it)
		{
			MyHTTPProvider *p = it->second;

			if (p->IsSSL() && sslref)
				try
				{
					sslref->Init(p);
				}
				catch (const CoreException &) { } // Throws on reinitialization
		}
	}
};

MODULE_INIT(HTTPD)
