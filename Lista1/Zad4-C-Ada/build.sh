#!/bin/bash

gnatmake -c jpplib
gnatbind -n jpplib
gcc -c test.c
gcc -c unity.c
gnatlink jpplib test.o unity.o -o test

gnatmake -c jpplib
gnatbind -n jpplib
gcc -c zad4.c
gnatlink jpplib zad4.o -o zad4

rm jpplib.ali
rm jpplib.o
rm test.o
rm unity.o
rm zad4.o