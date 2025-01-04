cmake_minimum_required(VERSION 3.30)
project(RenderingEngine)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(engine)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

enable_testing()

include_directories(${Boost_INCLUDE_DIRS})


# Create a list of all your test source files (excluding test_runner.cpp)
set(TEST_SOURCES
        tests/src/vector_tests.cpp
        tests/src/point_tests.cpp
        tests/src/normal_tests.cpp
        tests/src/util_tests.cpp
        # Add other test files here
)

add_executable(test_runner
        tests/src/test_runner.cpp
        ${TEST_SOURCES}
)


target_link_libraries(test_runner ${BOOST_LIBRARIES})


target_link_libraries(test_runner Boost::unit_test_framework)

add_test(NAME all_tests
        COMMAND test_runner
        --log_level=all
        --color_output=yes
        --report_level=detailed
)

# Optional: Set test properties
set_tests_properties(all_tests
        PROPERTIES
        ENVIRONMENT BOOST_TEST_LOG_LEVEL=all
        ENVIRONMENT BOOST_TEST_COLOR_OUTPUT=yes
        ENVIRONMENT BOOST_TEST_SHOW_PROGRESS=yes
)

