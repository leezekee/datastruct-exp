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
include CMakeFiles/demo-dfs.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/demo-dfs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/demo-dfs.dir/flags.make

CMakeFiles/demo-dfs.dir/example/demo.cpp.obj: CMakeFiles/demo-dfs.dir/flags.make
CMakeFiles/demo-dfs.dir/example/demo.cpp.obj: CMakeFiles/demo-dfs.dir/includes_CXX.rsp
CMakeFiles/demo-dfs.dir/example/demo.cpp.obj: ../example/demo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\Desktop\datastruct-exp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/demo-dfs.dir/example/demo.cpp.obj"
	E:\MinGW\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\demo-dfs.dir\example\demo.cpp.obj -c G:\Desktop\datastruct-exp\example\demo.cpp

CMakeFiles/demo-dfs.dir/example/demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo-dfs.dir/example/demo.cpp.i"
	E:\MinGW\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\Desktop\datastruct-exp\example\demo.cpp > CMakeFiles\demo-dfs.dir\example\demo.cpp.i

CMakeFiles/demo-dfs.dir/example/demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo-dfs.dir/example/demo.cpp.s"
	E:\MinGW\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\Desktop\datastruct-exp\example\demo.cpp -o CMakeFiles\demo-dfs.dir\example\demo.cpp.s

# Object files for target demo-dfs
demo__dfs_OBJECTS = \
"CMakeFiles/demo-dfs.dir/example/demo.cpp.obj"

# External object files for target demo-dfs
demo__dfs_EXTERNAL_OBJECTS =

../bin/demo-dfs.exe: CMakeFiles/demo-dfs.dir/example/demo.cpp.obj
../bin/demo-dfs.exe: CMakeFiles/demo-dfs.dir/build.make
../bin/demo-dfs.exe: ../lib/libdatastruct-exp.dll.a
../bin/demo-dfs.exe: CMakeFiles/demo-dfs.dir/linklibs.rsp
../bin/demo-dfs.exe: CMakeFiles/demo-dfs.dir/objects1.rsp
../bin/demo-dfs.exe: CMakeFiles/demo-dfs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\Desktop\datastruct-exp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ..\bin\demo-dfs.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\demo-dfs.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/demo-dfs.dir/build: ../bin/demo-dfs.exe

.PHONY : CMakeFiles/demo-dfs.dir/build

CMakeFiles/demo-dfs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\demo-dfs.dir\cmake_clean.cmake
.PHONY : CMakeFiles/demo-dfs.dir/clean

CMakeFiles/demo-dfs.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\Desktop\datastruct-exp G:\Desktop\datastruct-exp G:\Desktop\datastruct-exp\cmake-build-debug G:\Desktop\datastruct-exp\cmake-build-debug G:\Desktop\datastruct-exp\cmake-build-debug\CMakeFiles\demo-dfs.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/demo-dfs.dir/depend

