#include <Core/Core.h>

using namespace Upp;

#define LDUMP(x) DUMP(x)

template <class T>
void Check(T haystack, T needle, int pos)
{
	if(haystack.Find(needle) != pos) {
		DUMP(haystack);
		DUMP(needle);
		DUMP(haystack.Find(needle));
		NEVER();
	}
}

template <class T>
void Check()
{
	for(int l = 0; l < 30; l++) {
		for(int r = 0; r < 30; r++) {
			LOG(l << ":" << r);
			for(int nl = 0; nl < 30; nl++)
				for(int nr = 0; nr < 30; nr++)
					for(int nc = 1; nc < 30; nc++) {
						T needle = T('a', nl) + T('x', nc) + T('a', nr);
						Check(T('a', l) + needle + T('a', r), needle, l);
						Check(T('b', l) + needle + T('c', r), needle, l);
					}
		}
	}
}

CONSOLE_APP_MAIN
{
	StdLogSetup(LOG_COUT|LOG_FILE);

//	WString x("ax");
//	int pos = x.Find(WString("x"));

	Check<String>();
	Check<WString>();					
	
	LOG("Everything OK");
}
