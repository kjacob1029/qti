# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/kjacob1029/3rd/cmake/3.0.2/bin/cmake

# The command to remove a file.
RM = /home/kjacob1029/3rd/cmake/3.0.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kjacob1029/dev/tmp/DataStructs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kjacob1029/dev/tmp/DataStructs

# Include any dependencies generated for this target.
include CMakeFiles/testcb.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testcb.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testcb.dir/flags.make

CMakeFiles/testcb.dir/src/cb.cpp.o: CMakeFiles/testcb.dir/flags.make
CMakeFiles/testcb.dir/src/cb.cpp.o: src/cb.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/kjacob1029/dev/tmp/DataStructs/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/testcb.dir/src/cb.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/testcb.dir/src/cb.cpp.o -c /home/kjacob1029/dev/tmp/DataStructs/src/cb.cpp

CMakeFiles/testcb.dir/src/cb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testcb.dir/src/cb.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/kjacob1029/dev/tmp/DataStructs/src/cb.cpp > CMakeFiles/testcb.dir/src/cb.cpp.i

CMakeFiles/testcb.dir/src/cb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testcb.dir/src/cb.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/kjacob1029/dev/tmp/DataStructs/src/cb.cpp -o CMakeFiles/testcb.dir/src/cb.cpp.s

CMakeFiles/testcb.dir/src/cb.cpp.o.requires:
.PHONY : CMakeFiles/testcb.dir/src/cb.cpp.o.requires

CMakeFiles/testcb.dir/src/cb.cpp.o.provides: CMakeFiles/testcb.dir/src/cb.cpp.o.requires
	$(MAKE) -f CMakeFiles/testcb.dir/build.make CMakeFiles/testcb.dir/src/cb.cpp.o.provides.build
.PHONY : CMakeFiles/testcb.dir/src/cb.cpp.o.provides

CMakeFiles/testcb.dir/src/cb.cpp.o.provides.build: CMakeFiles/testcb.dir/src/cb.cpp.o

# Object files for target testcb
testcb_OBJECTS = \
"CMakeFiles/testcb.dir/src/cb.cpp.o"

# External object files for target testcb
testcb_EXTERNAL_OBJECTS =

testcb: CMakeFiles/testcb.dir/src/cb.cpp.o
testcb: CMakeFiles/testcb.dir/build.make
testcb: CMakeFiles/testcb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable testcb"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testcb.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testcb.dir/build: testcb
.PHONY : CMakeFiles/testcb.dir/build

CMakeFiles/testcb.dir/requires: CMakeFiles/testcb.dir/src/cb.cpp.o.requires
.PHONY : CMakeFiles/testcb.dir/requires

CMakeFiles/testcb.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testcb.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testcb.dir/clean

CMakeFiles/testcb.dir/depend:
	cd /home/kjacob1029/dev/tmp/DataStructs && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kjacob1029/dev/tmp/DataStructs /home/kjacob1029/dev/tmp/DataStructs /home/kjacob1029/dev/tmp/DataStructs /home/kjacob1029/dev/tmp/DataStructs /home/kjacob1029/dev/tmp/DataStructs/CMakeFiles/testcb.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testcb.dir/depend

