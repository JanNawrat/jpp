#!/bin/bash

gcc -c rust_wrapper/src/c_library/c_library.c
mv c_library.o rust_wrapper/src/c_library/c_library.o
ar rcs rust_wrapper/src/c_library/libc_library.a rust_wrapper/src/c_library/c_library.o