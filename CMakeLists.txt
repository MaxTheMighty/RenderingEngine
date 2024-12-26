cmake_minimum_required(VERSION 3.30)


set(CMAKE_CXX_STANDARD 20)

include(CTest)

add_subdirectory(engine)
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
    add_subdirectory(tests)
endif()

enable_testing()