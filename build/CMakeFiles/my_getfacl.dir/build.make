# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/anna/code/additional_facl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anna/code/additional_facl/build

# Include any dependencies generated for this target.
include CMakeFiles/my_getfacl.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/my_getfacl.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/my_getfacl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_getfacl.dir/flags.make

CMakeFiles/my_getfacl.dir/my_getfacl.cpp.o: CMakeFiles/my_getfacl.dir/flags.make
CMakeFiles/my_getfacl.dir/my_getfacl.cpp.o: ../my_getfacl.cpp
CMakeFiles/my_getfacl.dir/my_getfacl.cpp.o: CMakeFiles/my_getfacl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anna/code/additional_facl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my_getfacl.dir/my_getfacl.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/my_getfacl.dir/my_getfacl.cpp.o -MF CMakeFiles/my_getfacl.dir/my_getfacl.cpp.o.d -o CMakeFiles/my_getfacl.dir/my_getfacl.cpp.o -c /home/anna/code/additional_facl/my_getfacl.cpp

CMakeFiles/my_getfacl.dir/my_getfacl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_getfacl.dir/my_getfacl.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anna/code/additional_facl/my_getfacl.cpp > CMakeFiles/my_getfacl.dir/my_getfacl.cpp.i

CMakeFiles/my_getfacl.dir/my_getfacl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_getfacl.dir/my_getfacl.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anna/code/additional_facl/my_getfacl.cpp -o CMakeFiles/my_getfacl.dir/my_getfacl.cpp.s

# Object files for target my_getfacl
my_getfacl_OBJECTS = \
"CMakeFiles/my_getfacl.dir/my_getfacl.cpp.o"

# External object files for target my_getfacl
my_getfacl_EXTERNAL_OBJECTS =

my_getfacl: CMakeFiles/my_getfacl.dir/my_getfacl.cpp.o
my_getfacl: CMakeFiles/my_getfacl.dir/build.make
my_getfacl: CMakeFiles/my_getfacl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anna/code/additional_facl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable my_getfacl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_getfacl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_getfacl.dir/build: my_getfacl
.PHONY : CMakeFiles/my_getfacl.dir/build

CMakeFiles/my_getfacl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_getfacl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_getfacl.dir/clean

CMakeFiles/my_getfacl.dir/depend:
	cd /home/anna/code/additional_facl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anna/code/additional_facl /home/anna/code/additional_facl /home/anna/code/additional_facl/build /home/anna/code/additional_facl/build /home/anna/code/additional_facl/build/CMakeFiles/my_getfacl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_getfacl.dir/depend

