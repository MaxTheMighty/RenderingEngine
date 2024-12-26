# CMake generated Testfile for 
# Source directory: /Users/maxwell/Programming/C++/RenderingEngine
# Build directory: /Users/maxwell/Programming/C++/RenderingEngine
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[all_tests]=] "/Users/maxwell/Programming/C++/RenderingEngine/test_runner" "--log_level=all" "--color_output=yes" "--report_level=detailed")
set_tests_properties([=[all_tests]=] PROPERTIES  ENVIRONMENT "BOOST_TEST_SHOW_PROGRESS=yes" _BACKTRACE_TRIPLES "/Users/maxwell/Programming/C++/RenderingEngine/CMakeLists.txt;32;add_test;/Users/maxwell/Programming/C++/RenderingEngine/CMakeLists.txt;0;")
subdirs("engine")
