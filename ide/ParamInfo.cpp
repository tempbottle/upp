#include "ide.h"

void AssistEditor::SyncParamInfo()
{
	String qtf;
	int mpar = INT_MAX;
	int pos = 0;
	for(int q = 0; q < PARAMN; q++) {
		ParamInfo& m = param[q];
		int i = GetCursorLine();
		if(m.line >= 0 && m.line < GetLineCount() && i >= m.line && i < m.line + 10
		   && m.editfile == theide->editfile && GetWLine(m.line).StartsWith(m.test)) {
			int c = GetCursor();
			i = GetPos(m.line) + m.test.GetCount();
			if(c >= i) {
				int par = 0;
				int pari = 0;
				for(;;) {
					int ch = Ch(i++);
					if(i > c) {
						if(par < mpar) {
							qtf = "[A1  " + DecoratedItem(m.item.name, m.item, m.item.natural, pari);
							mpar = par;
							pos = m.pos;
						}
						break;
					}
					if(ch == ')') {
						if(par <= 0)
							break;
						par--;
					}
					if(ch == '(')
						par++;
					if(ch == ',' && par == 0)
						pari++;
				}
			}
		}
	}
	if(param_qtf != qtf)
		param_info.SetQTF(qtf);
	Rect r = GetLineScreenRect(GetCursorLine());
	int cx = max(GetSize().cx - 30, 300);
	int h = param_info.GetHeight(cx);
	h = min(h, 550);
	int y = r.top - h - 6;
	if(y < GetWorkArea().top)
		y = r.bottom;
	r = RectC(r.left, y, min(param_info.GetWidth(), cx) + 8, h + 6);
	r.OffsetHorz(GetColumnLine(pos).x * GetFontSize().cx);
	r.OffsetHorz(min(GetWorkArea().right - r.right, 0));
	if(param_qtf != qtf || r != param_info.GetRect()) {
		param_qtf = qtf;
		if(IsNull(qtf)) {
			if(param_info.IsOpen())
				param_info.Close();
		}
		else {
			param_info.SetRect(r);
			if(!param_info.IsOpen())
				param_info.Ctrl::PopUp(this, false, false, false);
		}
	}
}

void AssistEditor::StartParamInfo(const CppItem& m, int pos)
{
	int x = GetCursor();
	ParamInfo& f = param[parami];
	f.line = GetLinePos(x);
	f.test = GetWLine(f.line).Mid(0, x);
	f.item = m;
	f.editfile = theide->editfile;
	f.pos = pos;
	SyncParamInfo();
	parami = (parami + 1) % PARAMN;
}
