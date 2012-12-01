#ifndef _PcreTest_RegExp_h_
#define _PcreTest_RegExp_h_

//#include <Core/Core.h>

class RegExp : public Moveable<RegExp> {
public:
	enum
	{
		PARTIAL   = PCRE_PARTIAL,
		/* compile options */
		UNICODE   = PCRE_UTF8,
		UTF8      = PCRE_UTF8,
		CASELESS  = PCRE_CASELESS,
		MULTILINE = PCRE_MULTILINE,
		UNGREEDY  = PCRE_UNGREEDY,
		DOTALL    = PCRE_DOTALL,
		
		EXECUTE_OPTIONS = PCRE_ANCHORED
		                | PCRE_NEWLINE_CR
		                | PCRE_NEWLINE_LF
		                | PCRE_NEWLINE_CRLF
		                | PCRE_NEWLINE_ANYCRLF
		                | PCRE_NEWLINE_ANY
		                | PCRE_NOTBOL
		                | PCRE_NOTEOL
		                | PCRE_NOTEMPTY
		                | PCRE_NOTEMPTY_ATSTART
		                | PCRE_NO_START_OPTIMIZE
		                | PCRE_NO_UTF8_CHECK
		                | PCRE_PARTIAL_SOFT
		                | PCRE_PARTIAL_HARD,
		COMPILE_OPTIONS = PCRE_ANCHORED
		                | PCRE_AUTO_CALLOUT
		                | PCRE_BSR_ANYCRLF
		                | PCRE_BSR_UNICODE
		                | PCRE_CASELESS
		                | PCRE_DOLLAR_ENDONLY
		                | PCRE_DOTALL
		                | PCRE_DUPNAMES
		                | PCRE_EXTENDED
		                | PCRE_EXTRA
		                | PCRE_FIRSTLINE
		                | PCRE_JAVASCRIPT_COMPAT
		                | PCRE_MULTILINE
		                | PCRE_NEWLINE_CR
		                | PCRE_NEWLINE_LF
		                | PCRE_NEWLINE_CRLF
		                | PCRE_NEWLINE_ANYCRLF
		                | PCRE_NEWLINE_ANY
		                | PCRE_NO_AUTO_CAPTURE
		                | PCRE_NO_START_OPTIMIZE
		                | PCRE_UCP
		                | PCRE_UNGREEDY
		                | PCRE_UTF8
		                | PCRE_NO_UTF8_CHECK
	};

private:
	String pattern;
	String text;
	pcre * cpattern;
	pcre_extra * study;
	const char * error_string;
	int error_offset;
	int error_code;
	int pos[30];
	int rc;
	bool first;
	int compile_options;
	int execute_options;

public:
	void           Clear(bool freemem = false);
	void           SetOptions(int options);
	void           SetPattern(const char * p);
	void           SetPattern(const String &p);
	bool           Compile(bool recompile = false);
	bool           Study(bool restudy = false);
	int            Execute(const String &t, int offset = 0);
	bool           Match(const String &t, bool copy = true);
	bool           FastMatch(const String &t);
	bool           GlobalMatch(const String &t);
	String         operator[](const int i);
	int            GetCount();
	String         GetString(int i);
	void           GetMatchPos(int i, int& iPosStart, int& iPosAfterEnd);
	Vector<String> GetStrings();
	String         GetPattern() const { return pattern; }


	bool           IsError() { return error_code != 0; }
	const char    *GetError() { return error_string; }
	int            GetErrorCode() { return error_code; }

	RegExp(int options = UTF8);
	RegExp(const char * p, int options = UTF8);
	RegExp(const String &p, int options = UTF8);
	~RegExp();
};

#endif