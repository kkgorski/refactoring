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
include googletest-master/googlemock/CMakeFiles/gmock.dir/depend.make

# Include the progress variables for this target.
include googletest-master/googlemock/CMakeFiles/gmock.dir/progress.make

# Include the compile flags for this target's objects.
include googletest-master/googlemock/CMakeFiles/gmock.dir/flags.make

googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: googletest-master/googlemock/CMakeFiles/gmock.dir/flags.make
googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: ../googletest-master/googlemock/src/gmock-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/schab/CLionProjects/GtestTemplate/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o"
	cd /cygdrive/c/Users/schab/CLionProjects/GtestTemplate/cmake-build-debug/googletest-master/googlemock && /usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock.dir/src/gmock-all.cc.o -c /cygdrive/c/Users/schab/CLionProjects/GtestTemplate/googletest-master/googlemock/src/gmock-all.cc

googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/src/gmock-all.cc.i"
	cd /cygdrive/c/Users/schab/CLionProjects/GtestTemplate/cmake-build-debug/googletest-master/googlemock && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/schab/CLionProjects/GtestTemplate/googletest-master/googlemock/src/gmock-all.cc > CMakeFiles/gmock.dir/src/gmock-all.cc.i

googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/src/gmock-all.cc.s"
	cd /cygdrive/c/Users/schab/CLionProjects/GtestTemplate/cmake-build-debug/googletest-master/googlemock && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/schab/CLionProjects/GtestTemplate/googletest-master/googlemock/src/gmock-all.cc -o CMakeFiles/gmock.dir/src/gmock-all.cc.s

# Object files for target gmock
gmock_OBJECTS = \
"CMakeFiles/gmock.dir/src/gmock-all.cc.o"

# External object files for target gmock
gmock_EXTERNAL_OBJECTS =

lib/libgmockd.a: googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
lib/libgmockd.a: googletest-master/googlemock/CMakeFiles/gmock.dir/build.make
lib/libgmockd.a: googletest-master/googlemock/CMakeFiles/gmock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/schab/CLionProjects/GtestTemplate/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../lib/libgmockd.a"
	cd /cygdrive/c/Users/schab/CLionProjects/GtestTemplate/cmake-build-debug/googletest-master/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean_target.cmake
	cd /cygdrive/c/Users/schab/CLionProjects/GtestTemplate/cmake-build-debug/googletest-master/googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
googletest-master/googlemock/CMakeFiles/gmock.dir/build: lib/libgmockd.a

.PHONY : googletest-master/googlemock/CMakeFiles/gmock.dir/build

googletest-master/googlemock/CMakeFiles/gmock.dir/clean:
	cd /cygdrive/c/Users/schab/CLionProjects/GtestTemplate/cmake-build-debug/googletest-master/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean.cmake
.PHONY : googletest-master/googlemock/CMakeFiles/gmock.dir/clean

googletest-master/googlemock/CMakeFiles/gmock.dir/depend:
	cd /cygdrive/c/Users/schab/CLionProjects/GtestTemplate/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/schab/CLionProjects/GtestTemplate /cygdrive/c/Users/schab/CLionProjects/GtestTemplate/googletest-master/googlemock /cygdrive/c/Users/schab/CLionProjects/GtestTemplate/cmake-build-debug /cygdrive/c/Users/schab/CLionProjects/GtestTemplate/cmake-build-debug/googletest-master/googlemock /cygdrive/c/Users/schab/CLionProjects/GtestTemplate/cmake-build-debug/googletest-master/googlemock/CMakeFiles/gmock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : googletest-master/googlemock/CMakeFiles/gmock.dir/depend

