//TuWiM v 0.0.0.1 by JAGIELSKI
//licensed under GPL
//The main file.

#include <X11/X.h>
#define NULLDISPLAYERR 230
#define NULLROOTWNDERR 86
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char* argv[]){
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

	Display *dspl = NULL;
	printf("Opening X Display...\n");
	dspl = XOpenDisplay(NULL);

	if (dspl == NULL) {
		printf("Error: No valid X display provided. Are you trying to run this on Wayland? You poor silly goose...\n");
		return NULLDISPLAYERR;
	} else {
		printf("Successfully opened X Display.\n");
	}

	Window rootWnd;
	printf("Attempting tp get the root window...");
	rootWnd =XDefaultRootWindow(dspl);
	/*if (rootWnd == NULL){
		printf("Error: No valid X root window found. Are you trying to run this on Wayland? You poor silly goose...\n");
		return NULLROOTWNDERR;
	} else {
		printf("Root window got successfully!");
	}*/
	int defScr = DefaultScreen(dspl);
	/*
	 +--------------------------------------+
	 | TuWiM is scanning desktop entries... |
	 +--------------------------------------+
	*/
	Window ldWnd; //Window shown during the desktop entry scanning process to let the user know that the program is doing something
	printf("Attempting to create loading window");
	int wH =0; int wW=0; //window width/height
	wH = DisplayHeight(dspl, defScr)/6;
	wW = DisplayWidth(dspl, defScr)/4;
	XSetWindowAttributes ldWndAttr;
	ldWndAttr.background_pixel = 0;
	ldWndAttr.colormap = XCreateColormap(dspl, rootWnd, DefaultVisual(dspl, defScr), AllocNone);
	ldWnd = XCreateWindow(dspl,rootWnd,(DisplayWidth(dspl, defScr)/2)-(wW/2), (DisplayHeight(dspl, defScr)/2)-(wH/2), wW, wH, 0, CopyFromParent,InputOutput,CopyFromParent,CWBackPixel | CWColormap, &ldWndAttr);
	for (;;){
		//loading
	}
	XStoreName(dspl,ldWnd,"Loading TuWiM...");
	XMapWindow(dspl,ldWnd);
	XFlush(dspl);
	Window categoryWnd; //main window of the launcher.
	Window itemWnd;

	printf("Closing the X Display...\n");
	XCloseDisplay(dspl);

	printf("Display closed. Exiting gracefully.\n");
	return 0;
}
