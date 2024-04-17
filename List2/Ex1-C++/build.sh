#!/bin/bash

g++ main.cpp GaloisField.cpp -o main -std=c++14
g++ test.cpp GaloisField.cpp catch_amalgamated.cpp -o test -std=c++14