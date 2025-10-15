cmake_minimum_required(VERSION 3.15)
project(SyntaxError)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)

# Source files
set(SOURCES
    src/main.cpp
    src/lexer.cpp
)

add_executable(sntx ${SOURCES})
