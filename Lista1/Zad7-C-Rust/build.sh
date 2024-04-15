#!/bin/bash

cd rust_library
cargo build --release
cd ..
mv rust_library/bindings.h rust_library.h
mv rust_library/target/release/librust_library.a rust_library.a
gcc zad7.c rust_library.a -o zad7
gcc test.c rust_library.a unity.c -o test