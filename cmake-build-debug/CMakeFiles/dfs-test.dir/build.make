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
include CMakeFiles/dfs-test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dfs-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dfs-test.dir/flags.make

CMakeFiles/dfs-test.dir/example/dfs-test.cpp.obj: CMakeFiles/dfs-test.dir/flags.make
CMakeFiles/dfs-test.dir/example/dfs-test.cpp.obj: CMakeFiles/dfs-test.dir/includes_CXX.rsp
CMakeFiles/dfs-test.dir/example/dfs-test.cpp.obj: ../example/dfs-test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\Desktop\datastruct-exp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dfs-test.dir/example/dfs-test.cpp.obj"
	E:\MinGW\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\dfs-test.dir\example\dfs-test.cpp.obj -c G:\Desktop\datastruct-exp\example\dfs-test.cpp

CMakeFiles/dfs-test.dir/example/dfs-test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dfs-test.dir/example/dfs-test.cpp.i"
	E:\MinGW\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\Desktop\datastruct-exp\example\dfs-test.cpp > CMakeFiles\dfs-test.dir\example\dfs-test.cpp.i

CMakeFiles/dfs-test.dir/example/dfs-test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dfs-test.dir/example/dfs-test.cpp.s"
	E:\MinGW\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\Desktop\datastruct-exp\example\dfs-test.cpp -o CMakeFiles\dfs-test.dir\example\dfs-test.cpp.s

# Object files for target dfs-test
dfs__test_OBJECTS = \
"CMakeFiles/dfs-test.dir/example/dfs-test.cpp.obj"

# External object files for target dfs-test
dfs__test_EXTERNAL_OBJECTS =

../bin/dfs-test.exe: CMakeFiles/dfs-test.dir/example/dfs-test.cpp.obj
../bin/dfs-test.exe: CMakeFiles/dfs-test.dir/build.make
../bin/dfs-test.exe: ../lib/datastruct-exp.a
../bin/dfs-test.exe: CMakeFiles/dfs-test.dir/linklibs.rsp
../bin/dfs-test.exe: CMakeFiles/dfs-test.dir/objects1.rsp
../bin/dfs-test.exe: CMakeFiles/dfs-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\Desktop\datastruct-exp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ..\bin\dfs-test.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\dfs-test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dfs-test.dir/build: ../bin/dfs-test.exe

.PHONY : CMakeFiles/dfs-test.dir/build

CMakeFiles/dfs-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\dfs-test.dir\cmake_clean.cmake
.PHONY : CMakeFiles/dfs-test.dir/clean

CMakeFiles/dfs-test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\Desktop\datastruct-exp G:\Desktop\datastruct-exp G:\Desktop\datastruct-exp\cmake-build-debug G:\Desktop\datastruct-exp\cmake-build-debug G:\Desktop\datastruct-exp\cmake-build-debug\CMakeFiles\dfs-test.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dfs-test.dir/depend

