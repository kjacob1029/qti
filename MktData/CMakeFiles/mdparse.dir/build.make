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
CMAKE_SOURCE_DIR = /home/kjacob1029/dev/MktData

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kjacob1029/dev/MktData

# Include any dependencies generated for this target.
include CMakeFiles/mdparse.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mdparse.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mdparse.dir/flags.make

CMakeFiles/mdparse.dir/src/main.C.o: CMakeFiles/mdparse.dir/flags.make
CMakeFiles/mdparse.dir/src/main.C.o: src/main.C
	$(CMAKE_COMMAND) -E cmake_progress_report /home/kjacob1029/dev/MktData/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/mdparse.dir/src/main.C.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/mdparse.dir/src/main.C.o -c /home/kjacob1029/dev/MktData/src/main.C

CMakeFiles/mdparse.dir/src/main.C.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mdparse.dir/src/main.C.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/kjacob1029/dev/MktData/src/main.C > CMakeFiles/mdparse.dir/src/main.C.i

CMakeFiles/mdparse.dir/src/main.C.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mdparse.dir/src/main.C.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/kjacob1029/dev/MktData/src/main.C -o CMakeFiles/mdparse.dir/src/main.C.s

CMakeFiles/mdparse.dir/src/main.C.o.requires:
.PHONY : CMakeFiles/mdparse.dir/src/main.C.o.requires

CMakeFiles/mdparse.dir/src/main.C.o.provides: CMakeFiles/mdparse.dir/src/main.C.o.requires
	$(MAKE) -f CMakeFiles/mdparse.dir/build.make CMakeFiles/mdparse.dir/src/main.C.o.provides.build
.PHONY : CMakeFiles/mdparse.dir/src/main.C.o.provides

CMakeFiles/mdparse.dir/src/main.C.o.provides.build: CMakeFiles/mdparse.dir/src/main.C.o

CMakeFiles/mdparse.dir/src/PcapReader.C.o: CMakeFiles/mdparse.dir/flags.make
CMakeFiles/mdparse.dir/src/PcapReader.C.o: src/PcapReader.C
	$(CMAKE_COMMAND) -E cmake_progress_report /home/kjacob1029/dev/MktData/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/mdparse.dir/src/PcapReader.C.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/mdparse.dir/src/PcapReader.C.o -c /home/kjacob1029/dev/MktData/src/PcapReader.C

CMakeFiles/mdparse.dir/src/PcapReader.C.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mdparse.dir/src/PcapReader.C.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/kjacob1029/dev/MktData/src/PcapReader.C > CMakeFiles/mdparse.dir/src/PcapReader.C.i

CMakeFiles/mdparse.dir/src/PcapReader.C.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mdparse.dir/src/PcapReader.C.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/kjacob1029/dev/MktData/src/PcapReader.C -o CMakeFiles/mdparse.dir/src/PcapReader.C.s

CMakeFiles/mdparse.dir/src/PcapReader.C.o.requires:
.PHONY : CMakeFiles/mdparse.dir/src/PcapReader.C.o.requires

CMakeFiles/mdparse.dir/src/PcapReader.C.o.provides: CMakeFiles/mdparse.dir/src/PcapReader.C.o.requires
	$(MAKE) -f CMakeFiles/mdparse.dir/build.make CMakeFiles/mdparse.dir/src/PcapReader.C.o.provides.build
.PHONY : CMakeFiles/mdparse.dir/src/PcapReader.C.o.provides

CMakeFiles/mdparse.dir/src/PcapReader.C.o.provides.build: CMakeFiles/mdparse.dir/src/PcapReader.C.o

CMakeFiles/mdparse.dir/src/ItchParser.C.o: CMakeFiles/mdparse.dir/flags.make
CMakeFiles/mdparse.dir/src/ItchParser.C.o: src/ItchParser.C
	$(CMAKE_COMMAND) -E cmake_progress_report /home/kjacob1029/dev/MktData/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/mdparse.dir/src/ItchParser.C.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/mdparse.dir/src/ItchParser.C.o -c /home/kjacob1029/dev/MktData/src/ItchParser.C

CMakeFiles/mdparse.dir/src/ItchParser.C.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mdparse.dir/src/ItchParser.C.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/kjacob1029/dev/MktData/src/ItchParser.C > CMakeFiles/mdparse.dir/src/ItchParser.C.i

CMakeFiles/mdparse.dir/src/ItchParser.C.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mdparse.dir/src/ItchParser.C.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/kjacob1029/dev/MktData/src/ItchParser.C -o CMakeFiles/mdparse.dir/src/ItchParser.C.s

CMakeFiles/mdparse.dir/src/ItchParser.C.o.requires:
.PHONY : CMakeFiles/mdparse.dir/src/ItchParser.C.o.requires

CMakeFiles/mdparse.dir/src/ItchParser.C.o.provides: CMakeFiles/mdparse.dir/src/ItchParser.C.o.requires
	$(MAKE) -f CMakeFiles/mdparse.dir/build.make CMakeFiles/mdparse.dir/src/ItchParser.C.o.provides.build
.PHONY : CMakeFiles/mdparse.dir/src/ItchParser.C.o.provides

CMakeFiles/mdparse.dir/src/ItchParser.C.o.provides.build: CMakeFiles/mdparse.dir/src/ItchParser.C.o

# Object files for target mdparse
mdparse_OBJECTS = \
"CMakeFiles/mdparse.dir/src/main.C.o" \
"CMakeFiles/mdparse.dir/src/PcapReader.C.o" \
"CMakeFiles/mdparse.dir/src/ItchParser.C.o"

# External object files for target mdparse
mdparse_EXTERNAL_OBJECTS =

mdparse: CMakeFiles/mdparse.dir/src/main.C.o
mdparse: CMakeFiles/mdparse.dir/src/PcapReader.C.o
mdparse: CMakeFiles/mdparse.dir/src/ItchParser.C.o
mdparse: CMakeFiles/mdparse.dir/build.make
mdparse: CMakeFiles/mdparse.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable mdparse"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mdparse.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mdparse.dir/build: mdparse
.PHONY : CMakeFiles/mdparse.dir/build

CMakeFiles/mdparse.dir/requires: CMakeFiles/mdparse.dir/src/main.C.o.requires
CMakeFiles/mdparse.dir/requires: CMakeFiles/mdparse.dir/src/PcapReader.C.o.requires
CMakeFiles/mdparse.dir/requires: CMakeFiles/mdparse.dir/src/ItchParser.C.o.requires
.PHONY : CMakeFiles/mdparse.dir/requires

CMakeFiles/mdparse.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mdparse.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mdparse.dir/clean

CMakeFiles/mdparse.dir/depend:
	cd /home/kjacob1029/dev/MktData && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kjacob1029/dev/MktData /home/kjacob1029/dev/MktData /home/kjacob1029/dev/MktData /home/kjacob1029/dev/MktData /home/kjacob1029/dev/MktData/CMakeFiles/mdparse.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mdparse.dir/depend

