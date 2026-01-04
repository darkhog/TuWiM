#!/bin/bash

#even if the directory exists, it will just exit with a harmless error
#no need to test for its existence
#and if you have a file called "build" here it's your own damn fault.
mkdir build > /dev/null
gcc -Wall -o "./build/tuwim" "./main.c" -lX11