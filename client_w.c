#include <WINGs/WINGs.h>

static Display *display;

int main()
{
	WMScreen *screen;
	WMWindow *win;

	display = XOpenDisplay(NULL);
	screen = WMCreateScreen(display, DefaultScreen(display));
	win = WMCreateWindow(screen, "");

	WMRealizeWidget(win);
	WMMapWidget(win);

	WMScreenMainLoop(screen);
	return 0;
}
