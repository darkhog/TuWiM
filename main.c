//TuWiM v 0.0.0.1 by JAGIELSKI
//licensed under GPL
//The main file.

#define NULLDISPLAYERR 230
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char* argv[]){
	Display *dspl = NULL;
	printf("Opening X Display...\n");
	dspl = XOpenDisplay(NULL);
	if (dspl == NULL) {
		printf("Error: No valid X display provided. Are you trying to run this on Wayland? You poor silly goose...\n");
		return NULLDISPLAYERR;
	} else {
		printf("Successfully opened X Display.\n");
	}
	printf("Closing the X Display...\n");
	XCloseDisplay(dspl);
	printf("Display closed. Exiting gracefully.\n");
	return 0;
}
