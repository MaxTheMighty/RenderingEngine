cmake_minimum_required(VERSION 3.30)
project(RenderingEngine)

set(CMAKE_CXX_STANDARD 20)

add_executable(RenderingEngine main.cpp
        include/tuple2.h
        src/tuple2.cpp
        src/tuple3.cpp
        include/tuple3.h)



