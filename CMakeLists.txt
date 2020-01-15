cmake_minimum_required(VERSION 3.15)
project(24)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(24 main.cpp Event.cpp Event.h Pipe.cpp Pipe.h Generator.cpp Generator.h LowPass.cpp LowPass.h Display.cpp Display.h)