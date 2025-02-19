# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/maxwell/Programming/C++/RenderingEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/maxwell/Programming/C++/RenderingEngine

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target test
test:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running tests..."
	/Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/ctest --force-new-ctest-process $(ARGS)
.PHONY : test

# Special rule for the target test
test/fast: test
.PHONY : test/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake cache editor..."
	/opt/homebrew/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/maxwell/Programming/C++/RenderingEngine/CMakeFiles /Users/maxwell/Programming/C++/RenderingEngine//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/maxwell/Programming/C++/RenderingEngine/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named test_runner

# Build rule for target.
test_runner: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 test_runner
.PHONY : test_runner

# fast build rule for target.
test_runner/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_runner.dir/build.make CMakeFiles/test_runner.dir/build
.PHONY : test_runner/fast

#=============================================================================
# Target rules for targets named RenderingEngine

# Build rule for target.
RenderingEngine: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 RenderingEngine
.PHONY : RenderingEngine

# fast build rule for target.
RenderingEngine/fast:
	$(MAKE) $(MAKESILENT) -f engine/CMakeFiles/RenderingEngine.dir/build.make engine/CMakeFiles/RenderingEngine.dir/build
.PHONY : RenderingEngine/fast

tests/src/normal_tests.o: tests/src/normal_tests.cpp.o
.PHONY : tests/src/normal_tests.o

# target to build an object file
tests/src/normal_tests.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_runner.dir/build.make CMakeFiles/test_runner.dir/tests/src/normal_tests.cpp.o
.PHONY : tests/src/normal_tests.cpp.o

tests/src/normal_tests.i: tests/src/normal_tests.cpp.i
.PHONY : tests/src/normal_tests.i

# target to preprocess a source file
tests/src/normal_tests.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_runner.dir/build.make CMakeFiles/test_runner.dir/tests/src/normal_tests.cpp.i
.PHONY : tests/src/normal_tests.cpp.i

tests/src/normal_tests.s: tests/src/normal_tests.cpp.s
.PHONY : tests/src/normal_tests.s

# target to generate assembly for a file
tests/src/normal_tests.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_runner.dir/build.make CMakeFiles/test_runner.dir/tests/src/normal_tests.cpp.s
.PHONY : tests/src/normal_tests.cpp.s

tests/src/point_tests.o: tests/src/point_tests.cpp.o
.PHONY : tests/src/point_tests.o

# target to build an object file
tests/src/point_tests.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_runner.dir/build.make CMakeFiles/test_runner.dir/tests/src/point_tests.cpp.o
.PHONY : tests/src/point_tests.cpp.o

tests/src/point_tests.i: tests/src/point_tests.cpp.i
.PHONY : tests/src/point_tests.i

# target to preprocess a source file
tests/src/point_tests.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_runner.dir/build.make CMakeFiles/test_runner.dir/tests/src/point_tests.cpp.i
.PHONY : tests/src/point_tests.cpp.i

tests/src/point_tests.s: tests/src/point_tests.cpp.s
.PHONY : tests/src/point_tests.s

# target to generate assembly for a file
tests/src/point_tests.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_runner.dir/build.make CMakeFiles/test_runner.dir/tests/src/point_tests.cpp.s
.PHONY : tests/src/point_tests.cpp.s

tests/src/test_runner.o: tests/src/test_runner.cpp.o
.PHONY : tests/src/test_runner.o

# target to build an object file
tests/src/test_runner.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_runner.dir/build.make CMakeFiles/test_runner.dir/tests/src/test_runner.cpp.o
.PHONY : tests/src/test_runner.cpp.o

tests/src/test_runner.i: tests/src/test_runner.cpp.i
.PHONY : tests/src/test_runner.i

# target to preprocess a source file
tests/src/test_runner.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_runner.dir/build.make CMakeFiles/test_runner.dir/tests/src/test_runner.cpp.i
.PHONY : tests/src/test_runner.cpp.i

tests/src/test_runner.s: tests/src/test_runner.cpp.s
.PHONY : tests/src/test_runner.s

# target to generate assembly for a file
tests/src/test_runner.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_runner.dir/build.make CMakeFiles/test_runner.dir/tests/src/test_runner.cpp.s
.PHONY : tests/src/test_runner.cpp.s

tests/src/vector_tests.o: tests/src/vector_tests.cpp.o
.PHONY : tests/src/vector_tests.o

# target to build an object file
tests/src/vector_tests.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_runner.dir/build.make CMakeFiles/test_runner.dir/tests/src/vector_tests.cpp.o
.PHONY : tests/src/vector_tests.cpp.o

tests/src/vector_tests.i: tests/src/vector_tests.cpp.i
.PHONY : tests/src/vector_tests.i

# target to preprocess a source file
tests/src/vector_tests.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_runner.dir/build.make CMakeFiles/test_runner.dir/tests/src/vector_tests.cpp.i
.PHONY : tests/src/vector_tests.cpp.i

tests/src/vector_tests.s: tests/src/vector_tests.cpp.s
.PHONY : tests/src/vector_tests.s

# target to generate assembly for a file
tests/src/vector_tests.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_runner.dir/build.make CMakeFiles/test_runner.dir/tests/src/vector_tests.cpp.s
.PHONY : tests/src/vector_tests.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... test"
	@echo "... RenderingEngine"
	@echo "... test_runner"
	@echo "... tests/src/normal_tests.o"
	@echo "... tests/src/normal_tests.i"
	@echo "... tests/src/normal_tests.s"
	@echo "... tests/src/point_tests.o"
	@echo "... tests/src/point_tests.i"
	@echo "... tests/src/point_tests.s"
	@echo "... tests/src/test_runner.o"
	@echo "... tests/src/test_runner.i"
	@echo "... tests/src/test_runner.s"
	@echo "... tests/src/vector_tests.o"
	@echo "... tests/src/vector_tests.i"
	@echo "... tests/src/vector_tests.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

