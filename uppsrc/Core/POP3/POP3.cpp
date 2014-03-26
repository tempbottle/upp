#include "POP3.h"

static bool sPop3Trace;
#define LLOG(x) do { if(sPop3Trace) RLOG(x); } while(0)

void Pop3::Trace(bool b)
{
	sPop3Trace = b;
}

String Pop3::GetTimeStamp()
{
	int begin = data.Find('<');
	if(begin >= 0) {
		int end = data.Find('>', begin);
		if(end > begin) {
			end++;
			return data.Mid(begin, end - begin);
		}
	}
	return Null;
}

bool Pop3::GetListItems(ValueMap& list, dword type1, dword type2)
{
	StringStream s(data);
	while(!s.IsEof()) {
		String line = s.GetLine();
		Vector<String> s = Split(line, ' ');
		if(s.GetCount() < 2)
			return false;
		list.Add(Scan(type1, s[0]), Scan(type2, s[1]));
	}
	return true;	
}

int Pop3::GetMessageCount()
{
	if(!PutGet("STAT\r\n"))
		return Null;
	String ok, cnt, tsz;
	if(!SplitTo(data, ' ', ok, cnt, tsz))
		return Null;
	return StrInt(cnt);
}

String Pop3::GetMessage(int index)
{
	if(!PutGet(Format("RETR %d\r\n", index), true))
		return Null;
	return data;	
}

String Pop3::GetMessageHeader(int index)
{
	if(!PutGet(Format("TOP %d %d\r\n", index, 0), true))
		return Null;
	return data;
}

bool Pop3::GetMessageList(ValueMap& list)
{
	if(!PutGet("LIST\r\n", true))
		return false;
	return GetListItems(list, INT_V, INT_V);
}


String Pop3::GetMessageUniqueId(int index)
{
	if(!PutGet(Format("UIDL %d\r\n", index)))
		return Null;
	String ok, id, tsz;
	if(!SplitTo(data, ' ', ok, id, tsz))
		return Null;
	return id;
}

bool Pop3::GetMessageUniqueIds(ValueMap& uids)
{
	if(!PutGet("UIDL\r\n", true))
		return false;
	return GetListItems(uids, INT_V, STRING_V);
}

bool Pop3::RemoveMessage(int index)
{
	return PutGet(Format("DELE %d\r\n", index));
}

bool Pop3::Undo()
{
	return PutGet("RSET\r\n");
}

bool Pop3::Noop()
{
	return PutGet("NOOP\r\n");
}

String Pop3::GetDataLine()
{
	// We can't use TcpSocket::GetLine(), since it omits carriage returns we need.
	String line;
	for(;;) {
		int c = Get();
		if(c < 0) {
			if(!IsError())
				continue;  
			return String::GetVoid();
		}
		line.Cat(c);
		if(line.EndsWith("\r\n"))
			return line;
	}
}

bool Pop3::PutGet(const String& s, bool multiline, bool nolog)
{
	// Put() request.
	if(!s.IsEmpty()) {
		if(!nolog)
			LLOG(">> " << TrimRight(s));
		if(!PutAll(s)) {
			LLOG("-- " << GetLastError());
			return false;
		}		
	}
	// Get() respone.
	data.Clear();
	String line = GetDataLine();
	if(!line.IsEmpty()) {
		LLOG("<< " << TrimRight(line));
		if(line.StartsWith("+OK")) {
			if(!multiline) {
				data.Cat(line);
				return true;
			}
			else 
				for(;;) {
					line = GetDataLine();
					if(line.IsEmpty())
						break;
					if(line == ".\r\n") {
						LLOG("<< ...");
						return true;
					}
					data.Cat(*line == '.' ? line.Mid(1) : line);
				}
		}
		else
		if(line.StartsWith("-ERR"))
			error = line;
	}
	LLOG("-- " << GetLastError());
	return false;
}

bool Pop3::Authenticate()
{
	// Try using APOP authentication.
	String timestamp = GetTimeStamp();
	if(!timestamp.IsEmpty()) {
		if(PutGet("APOP " + user + " " + MD5String(timestamp << pass) + "\r\n"))
			return true;
	}
	else
	if(PutGet("USER " + user + "\r\n")) {
		LLOG(">>PASS ******");
		if(PutGet("PASS " + pass + "\r\n", false, true))
			return true;
	}
	
	return false;
}

bool Pop3::Login()
{
	try {
		if(host.IsEmpty())
			throw Exc(t_("Hostname is not specified."));
		if(user.IsEmpty())
			throw Exc(t_("Username is not specified."));
		if(pass.IsEmpty())
			throw Exc(t_("Password is nor specified."));
		if(!Connect(host, Nvl(port, ssl ? 995 : 110)))
			throw Exc(GetErrorDesc());
		LLOG(Format(t_("Opening connection to %s:%d."), host, port));
		if(ssl) {
			if(!StartSSL())
				throw Exc(t_("Couldn't start SSL session."));
			LLOG(t_("SSL session successfully started."));
		}
		// Receive server greetings.
		if(!PutGet(Null))
			throw Exc(GetLastError());
		if(!Authenticate())
			throw Exc(GetLastError());
	}
	catch (Exc e) {
		error = e;
		LLOG("-- " + e);
		Logout();
		return false;
	}
	return online = true;
}

bool Pop3::Logout()
{
	if(IsOnline()) 
		PutGet("QUIT\r\n");
	LLOG(Format(t_("Closing connection to %s:%d."), host, port));
	if(IsOpen())
		Close();
	online = false;
	return true;
}

Pop3::Pop3()
{
	ssl         = false;
	online		= false;
	Timeout(60000);
}

Pop3::~Pop3()
{
	Logout();
}
