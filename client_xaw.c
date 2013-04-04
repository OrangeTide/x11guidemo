#include <stdlib.h>
#include <X11/Intrinsic.h>
#include <X11/Shell.h>
#include <X11/StringDefs.h>

static XtAppContext appcontext;

void act_quit(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
	XtUnmapWidget(w);
	XtDestroyApplicationContext(appcontext);
	exit(1);
}

int main(int argc, char **argv)
{
	XrmOptionDescRec optlist[0] = { };
	Widget top;
	Atom wm_delete_window;
	XtActionsRec actions[1] = {
		{ "quit", act_quit },
	};

	top = XtVaOpenApplication(&appcontext, "Client",
		optlist, XtNumber(optlist),
		&argc, argv, NULL, applicationShellWidgetClass,
		XtNwidth, 600, XtNheight, 600, "title", "Hello World", NULL);
	wm_delete_window = XInternAtom(XtDisplay(top), "WM_DELETE_WINDOW", False);

	XtAppAddActions(appcontext, actions, XtNumber(actions));
	XtOverrideTranslations(top,
		XtParseTranslationTable("<Message>WM_PROTOCOLS: quit()"));

	XtRealizeWidget(top);
	XSetWMProtocols(XtDisplay(top), XtWindow(top), &wm_delete_window, 1);
	XtAppMainLoop(appcontext);
	return 0;
}
