//TuWiM v 0.0.0.1 by JAGIELSKI
//licensed under GPL
//The main file.

#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char* argv[]){
	Display *dspl;
	dspl = XOpenDisplay(NULL);

	XCloseDisplay(dspl);
	return 0;
}
