cmake_minimum_required(VERSION 3.15)
project(24)

set(CMAKE_CXX_STANDARD 11)

add_executable(24 main.cpp Event.cpp Event.h Pipe.cpp Pipe.h Generator.cpp Generator.h)