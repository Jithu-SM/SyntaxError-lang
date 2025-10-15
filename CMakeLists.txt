cmake_minimum_required(VERSION 3.15)
project(SyntaxError C)

set(CMAKE_C_STANDARD 11)
set(SOURCE_FILES src/main.c)

add_executable(sntx ${SOURCE_FILES})
