#include "TabCtrl.h"

void TabCtrlTest::AddTab()
{
	Button& b = ins.Add();
	b.SetLabel("Inserted").SizePos();
	tab.Insert(1, b, "Inserted!");
}

TabCtrlTest::TabCtrlTest()
{
	CtrlLayoutOK(*this, "Window title");
	CtrlLayout(tab1);
	CtrlLayout(tab2);
	CtrlLayout(tab3);
	b.SetRect(0, 0, 16, 16);
	tab.Add(tab1, "First").Control(&b);
	tab.Add(tab2, "Second").Image(CtrlImg::cut());
	tab.Add(tab3, "Third");
	tab.Add(arr.SizePos(), "Array");

	arr.AddColumn("1")
		.Ctrls(DefaultCtrlFactory<Option>())
	;
	arr.AddColumn("2")
		.Ctrls(DefaultCtrlFactory<EditString>())
	;
	arr.AddColumn("3");
//	arr.BackPaint();
//	arr.SetLineCy(300);

	arr.SetLineCy(20);
	for(int i = 0; i < 30; i++)
		arr.Add(i, AsString(i), GetSysDate() + i);

//	Background(PaintRect(ColorDisplay(), LtCyan()));
	
	test <<= THISBACK(AddTab);
}

GUI_APP_MAIN
{
/*
	TabDlg dlg;
	WithTab1<ParentCtrl> tab1;
	WithTab2<ParentCtrl> tab2;
	dlg(tab1, "Test1")(tab2, "Test2")(tab2, "Test2")(tab2, "Test2")(tab2, "Test2")(tab2, "Test2")(tab2, "Test2");
	dlg(tab1, "Test1")(tab2, "Test2")(tab2, "Test2")(tab2, "Test2")(tab2, "Test2")(tab2, "Test2")(tab2, "Test2");
//	dlg.tabctrl.SideGap(0).VertGap(0);
	dlg.OKCancel().Exit().Apply();
	dlg.Run();
*/
//	ChSetStyle("classic");


//	Ctrl::ShowRepaint(0);
	TabCtrlTest app;
	app.Sizeable();
//	app.NoBackPaint();
//	app.BackPaint();
	app.Run();
}
