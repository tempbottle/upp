#include <CtrlLib/CtrlLib.h>

using namespace Upp;

struct MyApp : public TopWindow {
	void Serialize(Stream& s) {
		SerializePlacement(s);
	}
	
	MyApp() { Sizeable().Zoomable(); }
};

GUI_APP_MAIN
{
	MyApp app;
	LoadFromFile(app);
	app.Execute();
	StoreToFile(app);
}
