#include "CtrlLib.h"

#define LLOG(x) // LOG(x)

NAMESPACE_UPP

#ifdef PLATFORM_X11

#if !defined(flagNOGTK)
	#include <limits.h>
	#include <gtk/gtk.h>
	#include <gdk/gdkx.h>
	#include <libnotify/notify.h>
#endif

Atom TraySelection()
{
	return XAtom(Format("_NET_SYSTEM_TRAY_S%d", Xscreenno));
}

void TrayIcon::Call(int code, unsigned long d1, unsigned long d2, unsigned long d3)
{
	if(!traywin)
		return;
	bool x11trap = TrapX11Errors();
	XEvent e;
	Zero(e);
	e.xclient.data.l[0] = CurrentTime;
	e.xclient.data.l[1] = code;
	e.xclient.data.l[2] = d1;
	e.xclient.data.l[3] = d2;
	e.xclient.data.l[4] = d3;
	e.xclient.window = traywin;
	e.xclient.type = ClientMessage;
	e.xclient.message_type = XAtom("_NET_SYSTEM_TRAY_OPCODE");
	e.xclient.format = 32;
	XSendEvent(Xdisplay, traywin, XFalse, 0, &e);
	XSync(Xdisplay, XFalse);
	UntrapX11Errors(x11trap);
}

void TrayIcon::AddToTray()
{
	Hide();
	traywin = XGetSelectionOwner(Xdisplay, TraySelection());
	if(!traywin) return;

	XSelectInput(Xdisplay, traywin, StructureNotifyMask);
	XWindowAttributes attr;
	XGetWindowAttributes(Xdisplay, Xroot, &attr);
	XSelectInput(Xdisplay, Xroot, attr.your_event_mask | StructureNotifyMask);

	Window win = GetWindow();
	XSizeHints *size_hints = XAllocSizeHints();
	size_hints->min_width = 22;
	size_hints->min_height = 22;
	size_hints->max_width = 22;
	size_hints->max_height = 22;
	size_hints->width = 22;
	size_hints->height = 22;
	size_hints->x = 0;
	size_hints->y = 0;
	size_hints->win_gravity = StaticGravity;
	size_hints->flags = PMinSize|PMaxSize|PPosition|PSize|PWinGravity;
	XSetWMNormalHints(Xdisplay, win, size_hints);

	Call(0, win, 0, 0);

	XSetWMNormalHints(Xdisplay, win, size_hints);

	Show();
	XSetWMNormalHints(Xdisplay, win, size_hints);
	XFree(size_hints);
}

void TrayIcon::Message(const char *title, const char *text, int timeout)
{
	if(!traywin)
		return;
#if defined(flagNOGTK)
	int len = strlen(text);
	static int stamp;
	Call(1, 1000 * timeout, len, ++stamp);
	bool x11trap = TrapX11Errors();
	while(len > 0) {
		XClientMessageEvent ev;
		Zero(ev);
		ev.type = ClientMessage;
		ev.window = GetWindow();
		ev.format = 8;
		ev.message_type = XAtom("_NET_SYSTEM_TRAY_MESSAGE_DATA");
		int n = min(len, 20);
		memcpy(&ev.data, text, n);
		text += n;
		len -= n;
		XSendEvent(Xdisplay, traywin, XFalse, StructureNotifyMask, (XEvent *) &ev);
		XSync(Xdisplay, XFalse);
	}
	UntrapX11Errors(x11trap);
#else	
	Size size = this->icon.GetSize();
	GdkPixmap *pixmap = NULL;
	GdkPixbuf *nicon = NULL;
	GError* error = NULL;
	NotifyNotification* notification;
	ImageDraw iw(size);
	iw.DrawRect(0, 0, size.cx, size.cy, Color(255, 0, 255)); // fuchsia color used for transparency
	iw.DrawImage(0, 0, this->icon);
	pixmap = gdk_pixmap_foreign_new(iw.GetDrawable());
	if (!pixmap)
		return;

	nicon = gdk_pixbuf_get_from_drawable(NULL, pixmap, gdk_colormap_get_system(), 0, 0, 0, 0, icon.GetSize().cx, icon.GetSize().cy);
	nicon = gdk_pixbuf_add_alpha(nicon, TRUE, 255, 0, 255);
	if (!notify_init (GetAppName().Begin()))
		return;
	
	notification = notify_notification_new (title, text, NULL , NULL);
	if (nicon)
		notify_notification_set_icon_from_pixbuf (notification, nicon);
	notify_notification_show (notification, &error);
	notify_uninit ();
	g_object_unref(pixmap);
	g_object_unref(nicon);
#endif
}

bool TrayIcon::HookProc(XEvent *event)
{
	XAnyEvent *e = (XAnyEvent *)event;
	if(e->type == DestroyNotify && e->window == traywin) {
		AddToTray();
		return true;
	}
	if(e->type == ClientMessage && !traywin) {
		XClientMessageEvent *cm = (XClientMessageEvent *)event;
		if(cm->message_type == XAtom("MANAGER") && (Atom)cm->data.l[1] == TraySelection()) {
			AddToTray();
			return true;
		}
    }
	return false;
}

void TrayIcon::Paint(Draw& w)
{
	Size sz = GetSize();
	Size isz = icon.GetSize();
	Image m = icon;
	if(isz.cx > sz.cx || isz.cy > sz.cy) {
		m = Rescale(icon, sz);
		isz = sz;
	}
	Point p = Rect(sz).CenterPos(isz);
	w.DrawRect(sz, SColorFace());
	w.DrawImage(p.x, p.y, m);
}

void TrayIcon::LeftDown()
{
	WhenLeftDown();
}

void TrayIcon::LeftDown(Point p, dword keyflags)
{
	LeftDown();
}

void TrayIcon::LeftUp()
{
	WhenLeftUp();
}

void TrayIcon::LeftUp(Point p, dword keyflags)
{
	LeftUp();
}

void TrayIcon::LeftDouble()
{
	WhenLeftDouble();
}

void TrayIcon::LeftDouble(Point p, dword keyflags)
{
	LeftDouble();
}

void TrayIcon::Menu(Bar& bar)
{
	WhenBar(bar);
}

void TrayIcon::DoMenu(Bar& bar)
{
	Menu(bar);
}

void TrayIcon::RightDown(Point p, dword keyflags)
{
	MenuBar::Execute(this, THISBACK(DoMenu), GetMousePos());
}

void TrayIcon::Show(bool b)
{
/*	if(!!b == !!IsOpen()) return; // Needs fixing....
	if(b) {
	}
	else
		Close();*/
}

TrayIcon::TrayIcon()
{
	SetRect(0, 0, 24, 24);
	ignoretakefocus = true;
	Create(NULL, true, false);
	if(top) {
		popup = true;
		Transparent();
		AddToTray();
	}
}

// Not implemented in X11 yet...
void TrayIcon::BalloonLeftDown()
{
}

void TrayIcon::BalloonShow()
{
}

void TrayIcon::BalloonHide()
{
}

void TrayIcon::BalloonTimeout()
{
}


#endif

END_UPP_NAMESPACE
