# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /usr/bin/cmake.exe

# The command to remove a file.
RM = /usr/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/schab/CLionProjects/GtestTemplate

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/schab/CLionProjects/GtestTemplate/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/konfig_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/konfig_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/konfig_test.dir/flags.make

CMakeFiles/konfig_test.dir/test/main_test.cpp.o: CMakeFiles/konfig_test.dir/flags.make
CMakeFiles/konfig_test.dir/test/main_test.cpp.o: ../test/main_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/schab/CLionProjects/GtestTemplate/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/konfig_test.dir/test/main_test.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/konfig_test.dir/test/main_test.cpp.o -c /cygdrive/c/Users/schab/CLionProjects/GtestTemplate/test/main_test.cpp

CMakeFiles/konfig_test.dir/test/main_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/konfig_test.dir/test/main_test.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/schab/CLionProjects/GtestTemplate/test/main_test.cpp > CMakeFiles/konfig_test.dir/test/main_test.cpp.i

CMakeFiles/konfig_test.dir/test/main_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/konfig_test.dir/test/main_test.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/schab/CLionProjects/GtestTemplate/test/main_test.cpp -o CMakeFiles/konfig_test.dir/test/main_test.cpp.s

# Object files for target konfig_test
konfig_test_OBJECTS = \
"CMakeFiles/konfig_test.dir/test/main_test.cpp.o"

# External object files for target konfig_test
konfig_test_EXTERNAL_OBJECTS =

konfig_test.exe: CMakeFiles/konfig_test.dir/test/main_test.cpp.o
konfig_test.exe: CMakeFiles/konfig_test.dir/build.make
konfig_test.exe: lib/libgmockd.a
konfig_test.exe: lib/libgtestd.a
konfig_test.exe: CMakeFiles/konfig_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/schab/CLionProjects/GtestTemplate/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable konfig_test.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/konfig_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/konfig_test.dir/build: konfig_test.exe

.PHONY : CMakeFiles/konfig_test.dir/build

CMakeFiles/konfig_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/konfig_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/konfig_test.dir/clean

CMakeFiles/konfig_test.dir/depend:
	cd /cygdrive/c/Users/schab/CLionProjects/GtestTemplate/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/schab/CLionProjects/GtestTemplate /cygdrive/c/Users/schab/CLionProjects/GtestTemplate /cygdrive/c/Users/schab/CLionProjects/GtestTemplate/cmake-build-debug /cygdrive/c/Users/schab/CLionProjects/GtestTemplate/cmake-build-debug /cygdrive/c/Users/schab/CLionProjects/GtestTemplate/cmake-build-debug/CMakeFiles/konfig_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/konfig_test.dir/depend

