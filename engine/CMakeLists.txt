cmake_minimum_required(VERSION 3.30)
project(RenderingEngine)

set(CMAKE_CXX_STANDARD 20)

add_executable(RenderingEngine main.cpp
        include/tuple2.h
        include/tuple3.h
        include/normal3.h
        include/point3.h
        include/util.h
        src/tuple2.cpp
        src/tuple3.cpp
        src/normal3.cpp
        src/vector3.cpp
        src/point3.cpp)



