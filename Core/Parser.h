inline bool iscib(int c) {
	return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '_';
}

inline bool iscid(int c) {
	return iscib(c) || c >= '0' && c <= '9';
}

class CParser {
protected:
	const char *term;
	const char *wspc;
	const char *lineptr;
	int         line;
	String      fn;
	bool        skipspaces;
	bool        uescape;

	bool        Spaces0();
	const char *IsId0(const char *s) const;
	bool        Id0(const char *id);
	void        DoSpaces()                    { if(skipspaces) Spaces(); }

public:
	struct Error : public Exc                 { Error(const char *s) : Exc(s) {} };

	void   ThrowError(const char *s);
	void   ThrowError()                       { ThrowError(""); }

	bool   Spaces()                           { wspc = term; return ((byte)*term <= ' ' || *term == '/') && Spaces0(); }
	char   PeekChar() const                   { return *term; }
	char   GetChar();

	bool   IsChar(char c) const               { return *term == c; }
	bool   IsChar2(char c1, char c2) const    { return term[0] == c1 && term[1] == c2; }
	bool   IsChar3(char c1, char c2, char c3) const { return term[0] == c1 && term[1] == c2 && term[2] == c3; }
	bool   Char(char c);
	bool   Char2(char c1, char c2);
	bool   Char3(char c1, char c2, char c3);
	void   PassChar(char c) throw(Error);
	void   PassChar2(char c1, char c2) throw(Error);
	void   PassChar3(char c1, char c2, char c3) throw(Error);
	bool   Id(const char *s)                  { return term[0] == s[0] && (s[1] == 0 || term[1] == s[1]) && Id0(s); }
	void   PassId(const char *s) throw(Error);
	bool   IsId() const                       { return iscib(*term); }
	bool   IsId(const char *s) const          { return term[0] == s[0] && (s[1] == 0 || term[1] == s[1]) && IsId0(s); }
	String ReadId() throw(Error);
	String ReadIdt() throw(Error);
	bool   IsInt() const;
	int    ReadInt() throw(Error);
	int    ReadInt(int min, int max) throw(Error);
	bool   IsNumber() const                   { return IsDigit(*term); }
	bool   IsNumber(int base) const;
	uint32 ReadNumber(int base = 10) throw(Error);
	uint64 ReadNumber64(int base = 10) throw(Error);
	bool   IsDouble() const                   { return IsInt(); }
	double ReadDouble() throw(Error);
	bool   IsString() const                   { return IsChar('\"'); };
	String ReadOneString(bool chkend = false) throw(Error);
	String ReadString(bool chkend = false) throw(Error);
	String ReadOneString(int delim, bool chkend = false) throw(Error);
	String ReadString(int delim, bool chkend = false) throw(Error);

	void   SkipTerm();

	struct Pos {
		const char *ptr;
		const char *wspc;
		const char *lineptr;
		int         line;
		String      fn;
		
		int GetColumn(int tabsize = 4) const;

		Pos(const char *ptr = NULL, int line = 1, String fn = Null) : ptr(ptr), line(line), fn(fn) {}
	};

	const char *GetPtr() const                { return (const char *)term; }
	const char *GetSpacePtr() const           { return (const char *)wspc; }

	Pos         GetPos() const;
	void        SetPos(const Pos& pos);

	bool   IsEof() const                      { return *term == '\0'; }
	operator bool() const                     { return *term; }

	int    GetLine() const                    { return line; }
	String GetFileName() const                { return fn; }
	
	void   Set(const char *ptr, const char *fn, int line = 1);
	void   Set(const char *ptr);

	CParser& SkipSpaces(bool b = true)        { skipspaces = true; return *this; }
	CParser& NoSkipSpaces()                   { skipspaces = false; return *this; }
	CParser& UnicodeEscape(bool b = true)     { uescape = b; return *this; }

	CParser(const char *ptr);
	CParser(const char *ptr, const char *fn, int line = 1);
	CParser();
};

inline bool CParser::Char(char c)
{
	if(IsChar(c)) {
		term++;
		DoSpaces();
		return true;
	}
	return false;
}

inline bool CParser::Char2(char c1, char c2)
{
	if(IsChar2(c1, c2)) {
		term += 2;
		DoSpaces();
		return true;
	}
	return false;
}

inline bool CParser::Char3(char c1, char c2, char c3)
{
	if(IsChar3(c1, c2, c3)) {
		term += 3;
		DoSpaces();
		return true;
	}
	return false;
}

enum {
	ASCSTRING_SMART     = 0x01,
	ASCSTRING_OCTALHI   = 0x02,
	ASCSTRING_JSON      = 0x04,
};

String AsCString(const char *s, const char *end, int linemax = INT_MAX, const char *linepfx = NULL,
                 dword flags = 0);
String AsCString(const char *s, int linemax = INT_MAX, const char *linepfx = NULL,
                 dword flags = 0);
String AsCString(const String& s, int linemax = INT_MAX, const char *linepfx = NULL,
                 dword flags = 0);
