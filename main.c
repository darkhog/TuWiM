//TuWiM v 0.0.0.1 by JAGIELSKI
//licensed under GPL
//The main file.

#include <X11/X.h>
#define NULLDISPLAYERR 230
#define NULLROOTWNDERR 86
#define ONWAYLANDERR 84
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

//we need to globalize certain variables to write the code in more maintainable way instead of one giant main()
Display *dspl;// XDisplay
Window rootWnd; //X11 root window
int defScr; //default screen of display.
Window ldWnd; //Window shown during the desktop entry scanning process to let the user know that the program is doing something
Window categoryWnd; //main window of the launcher.
Window itemWnd; //individual item window/category subwindow

int AreWeX11(){
	char* SessionType;
	SessionType = getenv("XDG_SESSION_TYPE");
	if ((strcmp(SessionType,"x11")!=0) || (strcmp(SessionType,"X11")!=0)){
		return 1;
	} else {
		return 0;
	}
}

int initX11() {
	dspl = NULL;
	printf("Opening X Display...\n");
	dspl = XOpenDisplay(NULL);

	if (dspl == NULL) {
		printf("Error: No valid X display provided. Are you trying to run this on Wayland? You poor silly goose...\n");
		return NULLDISPLAYERR;
	} else {
		printf("Successfully opened X Display.\n");
	}


	printf("Attempting tp get the root window...");
	rootWnd =XDefaultRootWindow(dspl);
	/*if (rootWnd == NULL){
	 p rintf("Error: No valid X root window found. Are you trying to run this on Wayland? You poor silly goose...\n");                                                                                            *
	 return NULLROOTWNDERR;
} else {
	printf("Root window got successfully!");
}*/
	defScr = DefaultScreen(dspl);
	return 0;
}

void initLoadingWindow(){
	/*
	 +--------------------------------------+
	 | TuWiM is scanning desktop entries... |
	 +--------------------------------------+
	 */

	printf("Attempting to create loading window");
	int wH =0; int wW=0; //window width/height
	wH = DisplayHeight(dspl, defScr)/6;
	wW = DisplayWidth(dspl, defScr)/4;
	XSetWindowAttributes ldWndAttr;
	ldWndAttr.background_pixel = 0;
	ldWndAttr.colormap = XCreateColormap(dspl, rootWnd, DefaultVisual(dspl, defScr), AllocNone);
	ldWnd = XCreateWindow(dspl,rootWnd,(DisplayWidth(dspl, defScr)/2)-(wW/2), (DisplayHeight(dspl, defScr)/2)-(wH/2), wW, wH, 0, CopyFromParent,InputOutput,CopyFromParent,CWBackPixel | CWColormap, &ldWndAttr);
	XStoreName(dspl,ldWnd,"Loading TuWiM...");
	XMapWindow(dspl,ldWnd);
	XFlush(dspl);
	return;
}

int main(int argc, char* argv[]){
	if (AreWeX11()!=0){
		//primitive Wayland detection

		printf("This application cannot be run under Wayland. Please use a proper windowing system. X Window System is recommended for maximum efficiency and pleasure.\n\n\n\nTHE POWER OF X COMPELS YOU");
		//return 666; that would be funny, alas, only 8bit return values on most unixes and unix-likes.
		return ONWAYLANDERR;
	}
	if (argc>1) {
		if (strcmp(argv[1],"dragons")==0){
			printf("Dragons are very cool!\n");
			printf("Here comes big boy!!!!\n\n");
			printf("  |\\           /|          \n");
			printf("  | \\         / |          \n");
			printf("  |  \\__   __/  |          \n");
			printf("  (             )          \n");
			printf("   \\  .--..--. /           \n");
			printf("    |          |      __   \n");
			printf("    \\          /     /  \\  \n");
			printf("     | (    ) |     /    | \n");
			printf("\\     \\VVVVVV/     /     | \n");
			printf(" \\    / (__) \\    /      | \n");
			printf("  \\  | (____) |  /      /  \n");
			printf("   \\/ (______) \\/      |   \n");
			return 0;
		}
	}

	int Xerr = initX11();
	if (Xerr!=0){
		return Xerr;
	}
	initLoadingWindow();
	for (;;){
		//loading
	}



	printf("Closing the X Display...\n");
	XCloseDisplay(dspl);

	printf("Display closed. Exiting gracefully.\n");
	return 0;
}
