# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/liheng/project/c++/cppdemo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/liheng/project/c++/cppdemo/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cppdemo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cppdemo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cppdemo.dir/flags.make

CMakeFiles/cppdemo.dir/main.cpp.o: CMakeFiles/cppdemo.dir/flags.make
CMakeFiles/cppdemo.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/liheng/project/c++/cppdemo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cppdemo.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cppdemo.dir/main.cpp.o -c /Users/liheng/project/c++/cppdemo/main.cpp

CMakeFiles/cppdemo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppdemo.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/liheng/project/c++/cppdemo/main.cpp > CMakeFiles/cppdemo.dir/main.cpp.i

CMakeFiles/cppdemo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppdemo.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/liheng/project/c++/cppdemo/main.cpp -o CMakeFiles/cppdemo.dir/main.cpp.s

# Object files for target cppdemo
cppdemo_OBJECTS = \
"CMakeFiles/cppdemo.dir/main.cpp.o"

# External object files for target cppdemo
cppdemo_EXTERNAL_OBJECTS =

cppdemo: CMakeFiles/cppdemo.dir/main.cpp.o
cppdemo: CMakeFiles/cppdemo.dir/build.make
cppdemo: CMakeFiles/cppdemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/liheng/project/c++/cppdemo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cppdemo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cppdemo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cppdemo.dir/build: cppdemo

.PHONY : CMakeFiles/cppdemo.dir/build

CMakeFiles/cppdemo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cppdemo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cppdemo.dir/clean

CMakeFiles/cppdemo.dir/depend:
	cd /Users/liheng/project/c++/cppdemo/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/liheng/project/c++/cppdemo /Users/liheng/project/c++/cppdemo /Users/liheng/project/c++/cppdemo/cmake-build-debug /Users/liheng/project/c++/cppdemo/cmake-build-debug /Users/liheng/project/c++/cppdemo/cmake-build-debug/CMakeFiles/cppdemo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cppdemo.dir/depend

