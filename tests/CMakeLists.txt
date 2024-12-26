project(tests LANGUAGES CXX)
add_executable(tests src/tests.cpp)
target_link_libraries(tests PRIVATE engine)
add_test(NAME tests COMMAND tests)