cmake_minimum_required(VERSION 3.30)
project(RenderingEngine)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(RenderingEngine main.cpp
        include/tuple2.h
        include/tuple3.h
        include/normal3.h
        include/point3.h
        include/ray.h
        include/medium.h
        include/util.h
        include/bounds2.h
        include/bounds3.h
        include/sphericalgeometry.h
        include/vector3.h
        include/canvas.h
        include/model.h
        include/parser.h
        src/tuple2.cpp
        src/tuple3.cpp
        src/normal3.cpp
        src/vector3.cpp
        src/point3.cpp
        src/ray.cpp
        src/medium.cpp
        src/canvas.cpp
        src/model.cpp
        src/parser.cpp
        include/triangle.h
        src/triangle.cpp
)

target_include_directories(RenderingEngine PRIVATE /Users/maxwell/Programming/C++/RenderingEngine/engine/external/sdl/include/) #SDL headers

target_link_libraries(RenderingEngine
        /Users/maxwell/Programming/C++/RenderingEngine/engine/external/sdl/lib/libSDL_uclibc.a
        /Users/maxwell/Programming/C++/RenderingEngine/engine/external/sdl/lib/libSDL3.0.dylib
) #SDL lib





