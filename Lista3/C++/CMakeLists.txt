cmake_minimum_required(VERSION 3.10)
project(Zad1)

file(GLOB SOURCE_FILES "*.cpp")

add_executable(main ${SOURCE_FILES})

target_compile_options(main PRIVATE -std=c++14)