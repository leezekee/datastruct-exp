# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2021.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2021.1.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = G:\Desktop\datastruct-exp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\Desktop\datastruct-exp\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/gui-test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gui-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gui-test.dir/flags.make

CMakeFiles/gui-test.dir/example/gui-test.cpp.obj: CMakeFiles/gui-test.dir/flags.make
CMakeFiles/gui-test.dir/example/gui-test.cpp.obj: CMakeFiles/gui-test.dir/includes_CXX.rsp
CMakeFiles/gui-test.dir/example/gui-test.cpp.obj: ../example/gui-test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\Desktop\datastruct-exp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gui-test.dir/example/gui-test.cpp.obj"
	E:\MinGW\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\gui-test.dir\example\gui-test.cpp.obj -c G:\Desktop\datastruct-exp\example\gui-test.cpp

CMakeFiles/gui-test.dir/example/gui-test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gui-test.dir/example/gui-test.cpp.i"
	E:\MinGW\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\Desktop\datastruct-exp\example\gui-test.cpp > CMakeFiles\gui-test.dir\example\gui-test.cpp.i

CMakeFiles/gui-test.dir/example/gui-test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gui-test.dir/example/gui-test.cpp.s"
	E:\MinGW\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\Desktop\datastruct-exp\example\gui-test.cpp -o CMakeFiles\gui-test.dir\example\gui-test.cpp.s

# Object files for target gui-test
gui__test_OBJECTS = \
"CMakeFiles/gui-test.dir/example/gui-test.cpp.obj"

# External object files for target gui-test
gui__test_EXTERNAL_OBJECTS =

../bin/gui-test.exe: CMakeFiles/gui-test.dir/example/gui-test.cpp.obj
../bin/gui-test.exe: CMakeFiles/gui-test.dir/build.make
../bin/gui-test.exe: ../lib/datastruct-exp.a
../bin/gui-test.exe: CMakeFiles/gui-test.dir/linklibs.rsp
../bin/gui-test.exe: CMakeFiles/gui-test.dir/objects1.rsp
../bin/gui-test.exe: CMakeFiles/gui-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\Desktop\datastruct-exp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ..\bin\gui-test.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gui-test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gui-test.dir/build: ../bin/gui-test.exe

.PHONY : CMakeFiles/gui-test.dir/build

CMakeFiles/gui-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\gui-test.dir\cmake_clean.cmake
.PHONY : CMakeFiles/gui-test.dir/clean

CMakeFiles/gui-test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\Desktop\datastruct-exp G:\Desktop\datastruct-exp G:\Desktop\datastruct-exp\cmake-build-debug G:\Desktop\datastruct-exp\cmake-build-debug G:\Desktop\datastruct-exp\cmake-build-debug\CMakeFiles\gui-test.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gui-test.dir/depend

