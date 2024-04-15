#!/bin/bash

gnatmake -c jpplib
gnatbind -n jpplib
gcc -c test.c
gnatlink jpplib test.o -o test