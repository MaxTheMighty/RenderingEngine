# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/maxwell/Programming/C++/RenderingEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/maxwell/Programming/C++/RenderingEngine

# Include any dependencies generated for this target.
include engine/CMakeFiles/RenderingEngine.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include engine/CMakeFiles/RenderingEngine.dir/compiler_depend.make

# Include the progress variables for this target.
include engine/CMakeFiles/RenderingEngine.dir/progress.make

# Include the compile flags for this target's objects.
include engine/CMakeFiles/RenderingEngine.dir/flags.make

engine/CMakeFiles/RenderingEngine.dir/codegen:
.PHONY : engine/CMakeFiles/RenderingEngine.dir/codegen

engine/CMakeFiles/RenderingEngine.dir/main.cpp.o: engine/CMakeFiles/RenderingEngine.dir/flags.make
engine/CMakeFiles/RenderingEngine.dir/main.cpp.o: engine/main.cpp
engine/CMakeFiles/RenderingEngine.dir/main.cpp.o: engine/CMakeFiles/RenderingEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/maxwell/Programming/C++/RenderingEngine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object engine/CMakeFiles/RenderingEngine.dir/main.cpp.o"
	cd /Users/maxwell/Programming/C++/RenderingEngine/engine && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT engine/CMakeFiles/RenderingEngine.dir/main.cpp.o -MF CMakeFiles/RenderingEngine.dir/main.cpp.o.d -o CMakeFiles/RenderingEngine.dir/main.cpp.o -c /Users/maxwell/Programming/C++/RenderingEngine/engine/main.cpp

engine/CMakeFiles/RenderingEngine.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/RenderingEngine.dir/main.cpp.i"
	cd /Users/maxwell/Programming/C++/RenderingEngine/engine && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maxwell/Programming/C++/RenderingEngine/engine/main.cpp > CMakeFiles/RenderingEngine.dir/main.cpp.i

engine/CMakeFiles/RenderingEngine.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/RenderingEngine.dir/main.cpp.s"
	cd /Users/maxwell/Programming/C++/RenderingEngine/engine && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maxwell/Programming/C++/RenderingEngine/engine/main.cpp -o CMakeFiles/RenderingEngine.dir/main.cpp.s

engine/CMakeFiles/RenderingEngine.dir/src/tuple2.cpp.o: engine/CMakeFiles/RenderingEngine.dir/flags.make
engine/CMakeFiles/RenderingEngine.dir/src/tuple2.cpp.o: engine/src/tuple2.cpp
engine/CMakeFiles/RenderingEngine.dir/src/tuple2.cpp.o: engine/CMakeFiles/RenderingEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/maxwell/Programming/C++/RenderingEngine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object engine/CMakeFiles/RenderingEngine.dir/src/tuple2.cpp.o"
	cd /Users/maxwell/Programming/C++/RenderingEngine/engine && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT engine/CMakeFiles/RenderingEngine.dir/src/tuple2.cpp.o -MF CMakeFiles/RenderingEngine.dir/src/tuple2.cpp.o.d -o CMakeFiles/RenderingEngine.dir/src/tuple2.cpp.o -c /Users/maxwell/Programming/C++/RenderingEngine/engine/src/tuple2.cpp

engine/CMakeFiles/RenderingEngine.dir/src/tuple2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/RenderingEngine.dir/src/tuple2.cpp.i"
	cd /Users/maxwell/Programming/C++/RenderingEngine/engine && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maxwell/Programming/C++/RenderingEngine/engine/src/tuple2.cpp > CMakeFiles/RenderingEngine.dir/src/tuple2.cpp.i

engine/CMakeFiles/RenderingEngine.dir/src/tuple2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/RenderingEngine.dir/src/tuple2.cpp.s"
	cd /Users/maxwell/Programming/C++/RenderingEngine/engine && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maxwell/Programming/C++/RenderingEngine/engine/src/tuple2.cpp -o CMakeFiles/RenderingEngine.dir/src/tuple2.cpp.s

engine/CMakeFiles/RenderingEngine.dir/src/tuple3.cpp.o: engine/CMakeFiles/RenderingEngine.dir/flags.make
engine/CMakeFiles/RenderingEngine.dir/src/tuple3.cpp.o: engine/src/tuple3.cpp
engine/CMakeFiles/RenderingEngine.dir/src/tuple3.cpp.o: engine/CMakeFiles/RenderingEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/maxwell/Programming/C++/RenderingEngine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object engine/CMakeFiles/RenderingEngine.dir/src/tuple3.cpp.o"
	cd /Users/maxwell/Programming/C++/RenderingEngine/engine && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT engine/CMakeFiles/RenderingEngine.dir/src/tuple3.cpp.o -MF CMakeFiles/RenderingEngine.dir/src/tuple3.cpp.o.d -o CMakeFiles/RenderingEngine.dir/src/tuple3.cpp.o -c /Users/maxwell/Programming/C++/RenderingEngine/engine/src/tuple3.cpp

engine/CMakeFiles/RenderingEngine.dir/src/tuple3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/RenderingEngine.dir/src/tuple3.cpp.i"
	cd /Users/maxwell/Programming/C++/RenderingEngine/engine && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maxwell/Programming/C++/RenderingEngine/engine/src/tuple3.cpp > CMakeFiles/RenderingEngine.dir/src/tuple3.cpp.i

engine/CMakeFiles/RenderingEngine.dir/src/tuple3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/RenderingEngine.dir/src/tuple3.cpp.s"
	cd /Users/maxwell/Programming/C++/RenderingEngine/engine && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maxwell/Programming/C++/RenderingEngine/engine/src/tuple3.cpp -o CMakeFiles/RenderingEngine.dir/src/tuple3.cpp.s

# Object files for target RenderingEngine
RenderingEngine_OBJECTS = \
"CMakeFiles/RenderingEngine.dir/main.cpp.o" \
"CMakeFiles/RenderingEngine.dir/src/tuple2.cpp.o" \
"CMakeFiles/RenderingEngine.dir/src/tuple3.cpp.o"

# External object files for target RenderingEngine
RenderingEngine_EXTERNAL_OBJECTS =

engine/RenderingEngine: engine/CMakeFiles/RenderingEngine.dir/main.cpp.o
engine/RenderingEngine: engine/CMakeFiles/RenderingEngine.dir/src/tuple2.cpp.o
engine/RenderingEngine: engine/CMakeFiles/RenderingEngine.dir/src/tuple3.cpp.o
engine/RenderingEngine: engine/CMakeFiles/RenderingEngine.dir/build.make
engine/RenderingEngine: engine/CMakeFiles/RenderingEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/maxwell/Programming/C++/RenderingEngine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable RenderingEngine"
	cd /Users/maxwell/Programming/C++/RenderingEngine/engine && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RenderingEngine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
engine/CMakeFiles/RenderingEngine.dir/build: engine/RenderingEngine
.PHONY : engine/CMakeFiles/RenderingEngine.dir/build

engine/CMakeFiles/RenderingEngine.dir/clean:
	cd /Users/maxwell/Programming/C++/RenderingEngine/engine && $(CMAKE_COMMAND) -P CMakeFiles/RenderingEngine.dir/cmake_clean.cmake
.PHONY : engine/CMakeFiles/RenderingEngine.dir/clean

engine/CMakeFiles/RenderingEngine.dir/depend:
	cd /Users/maxwell/Programming/C++/RenderingEngine && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/maxwell/Programming/C++/RenderingEngine /Users/maxwell/Programming/C++/RenderingEngine/engine /Users/maxwell/Programming/C++/RenderingEngine /Users/maxwell/Programming/C++/RenderingEngine/engine /Users/maxwell/Programming/C++/RenderingEngine/engine/CMakeFiles/RenderingEngine.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : engine/CMakeFiles/RenderingEngine.dir/depend

