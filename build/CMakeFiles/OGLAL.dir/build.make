# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = F:\Programs\CMake\bin\cmake.exe

# The command to remove a file.
RM = F:\Programs\CMake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\Projects\C++\OGAL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\Projects\C++\OGAL\build

# Include any dependencies generated for this target.
include CMakeFiles/OGLAL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OGLAL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OGLAL.dir/flags.make

CMakeFiles/OGLAL.dir/src/OGAL.cpp.obj: CMakeFiles/OGLAL.dir/flags.make
CMakeFiles/OGLAL.dir/src/OGAL.cpp.obj: CMakeFiles/OGLAL.dir/includes_CXX.rsp
CMakeFiles/OGLAL.dir/src/OGAL.cpp.obj: ../src/OGAL.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Projects\C++\OGAL\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OGLAL.dir/src/OGAL.cpp.obj"
	F:\Programs\MinGW\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OGLAL.dir\src\OGAL.cpp.obj -c F:\Projects\C++\OGAL\src\OGAL.cpp

CMakeFiles/OGLAL.dir/src/OGAL.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OGLAL.dir/src/OGAL.cpp.i"
	F:\Programs\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Projects\C++\OGAL\src\OGAL.cpp > CMakeFiles\OGLAL.dir\src\OGAL.cpp.i

CMakeFiles/OGLAL.dir/src/OGAL.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OGLAL.dir/src/OGAL.cpp.s"
	F:\Programs\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Projects\C++\OGAL\src\OGAL.cpp -o CMakeFiles\OGLAL.dir\src\OGAL.cpp.s

CMakeFiles/OGLAL.dir/src/OGAL.cpp.obj.requires:

.PHONY : CMakeFiles/OGLAL.dir/src/OGAL.cpp.obj.requires

CMakeFiles/OGLAL.dir/src/OGAL.cpp.obj.provides: CMakeFiles/OGLAL.dir/src/OGAL.cpp.obj.requires
	$(MAKE) -f CMakeFiles\OGLAL.dir\build.make CMakeFiles/OGLAL.dir/src/OGAL.cpp.obj.provides.build
.PHONY : CMakeFiles/OGLAL.dir/src/OGAL.cpp.obj.provides

CMakeFiles/OGLAL.dir/src/OGAL.cpp.obj.provides.build: CMakeFiles/OGLAL.dir/src/OGAL.cpp.obj


CMakeFiles/OGLAL.dir/src/event.cpp.obj: CMakeFiles/OGLAL.dir/flags.make
CMakeFiles/OGLAL.dir/src/event.cpp.obj: CMakeFiles/OGLAL.dir/includes_CXX.rsp
CMakeFiles/OGLAL.dir/src/event.cpp.obj: ../src/event.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Projects\C++\OGAL\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OGLAL.dir/src/event.cpp.obj"
	F:\Programs\MinGW\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OGLAL.dir\src\event.cpp.obj -c F:\Projects\C++\OGAL\src\event.cpp

CMakeFiles/OGLAL.dir/src/event.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OGLAL.dir/src/event.cpp.i"
	F:\Programs\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Projects\C++\OGAL\src\event.cpp > CMakeFiles\OGLAL.dir\src\event.cpp.i

CMakeFiles/OGLAL.dir/src/event.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OGLAL.dir/src/event.cpp.s"
	F:\Programs\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Projects\C++\OGAL\src\event.cpp -o CMakeFiles\OGLAL.dir\src\event.cpp.s

CMakeFiles/OGLAL.dir/src/event.cpp.obj.requires:

.PHONY : CMakeFiles/OGLAL.dir/src/event.cpp.obj.requires

CMakeFiles/OGLAL.dir/src/event.cpp.obj.provides: CMakeFiles/OGLAL.dir/src/event.cpp.obj.requires
	$(MAKE) -f CMakeFiles\OGLAL.dir\build.make CMakeFiles/OGLAL.dir/src/event.cpp.obj.provides.build
.PHONY : CMakeFiles/OGLAL.dir/src/event.cpp.obj.provides

CMakeFiles/OGLAL.dir/src/event.cpp.obj.provides.build: CMakeFiles/OGLAL.dir/src/event.cpp.obj


CMakeFiles/OGLAL.dir/src/main.cpp.obj: CMakeFiles/OGLAL.dir/flags.make
CMakeFiles/OGLAL.dir/src/main.cpp.obj: CMakeFiles/OGLAL.dir/includes_CXX.rsp
CMakeFiles/OGLAL.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Projects\C++\OGAL\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/OGLAL.dir/src/main.cpp.obj"
	F:\Programs\MinGW\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OGLAL.dir\src\main.cpp.obj -c F:\Projects\C++\OGAL\src\main.cpp

CMakeFiles/OGLAL.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OGLAL.dir/src/main.cpp.i"
	F:\Programs\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Projects\C++\OGAL\src\main.cpp > CMakeFiles\OGLAL.dir\src\main.cpp.i

CMakeFiles/OGLAL.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OGLAL.dir/src/main.cpp.s"
	F:\Programs\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Projects\C++\OGAL\src\main.cpp -o CMakeFiles\OGLAL.dir\src\main.cpp.s

CMakeFiles/OGLAL.dir/src/main.cpp.obj.requires:

.PHONY : CMakeFiles/OGLAL.dir/src/main.cpp.obj.requires

CMakeFiles/OGLAL.dir/src/main.cpp.obj.provides: CMakeFiles/OGLAL.dir/src/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\OGLAL.dir\build.make CMakeFiles/OGLAL.dir/src/main.cpp.obj.provides.build
.PHONY : CMakeFiles/OGLAL.dir/src/main.cpp.obj.provides

CMakeFiles/OGLAL.dir/src/main.cpp.obj.provides.build: CMakeFiles/OGLAL.dir/src/main.cpp.obj


CMakeFiles/OGLAL.dir/src/program.cpp.obj: CMakeFiles/OGLAL.dir/flags.make
CMakeFiles/OGLAL.dir/src/program.cpp.obj: CMakeFiles/OGLAL.dir/includes_CXX.rsp
CMakeFiles/OGLAL.dir/src/program.cpp.obj: ../src/program.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Projects\C++\OGAL\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/OGLAL.dir/src/program.cpp.obj"
	F:\Programs\MinGW\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OGLAL.dir\src\program.cpp.obj -c F:\Projects\C++\OGAL\src\program.cpp

CMakeFiles/OGLAL.dir/src/program.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OGLAL.dir/src/program.cpp.i"
	F:\Programs\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Projects\C++\OGAL\src\program.cpp > CMakeFiles\OGLAL.dir\src\program.cpp.i

CMakeFiles/OGLAL.dir/src/program.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OGLAL.dir/src/program.cpp.s"
	F:\Programs\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Projects\C++\OGAL\src\program.cpp -o CMakeFiles\OGLAL.dir\src\program.cpp.s

CMakeFiles/OGLAL.dir/src/program.cpp.obj.requires:

.PHONY : CMakeFiles/OGLAL.dir/src/program.cpp.obj.requires

CMakeFiles/OGLAL.dir/src/program.cpp.obj.provides: CMakeFiles/OGLAL.dir/src/program.cpp.obj.requires
	$(MAKE) -f CMakeFiles\OGLAL.dir\build.make CMakeFiles/OGLAL.dir/src/program.cpp.obj.provides.build
.PHONY : CMakeFiles/OGLAL.dir/src/program.cpp.obj.provides

CMakeFiles/OGLAL.dir/src/program.cpp.obj.provides.build: CMakeFiles/OGLAL.dir/src/program.cpp.obj


CMakeFiles/OGLAL.dir/src/render_list.cpp.obj: CMakeFiles/OGLAL.dir/flags.make
CMakeFiles/OGLAL.dir/src/render_list.cpp.obj: CMakeFiles/OGLAL.dir/includes_CXX.rsp
CMakeFiles/OGLAL.dir/src/render_list.cpp.obj: ../src/render_list.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Projects\C++\OGAL\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/OGLAL.dir/src/render_list.cpp.obj"
	F:\Programs\MinGW\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OGLAL.dir\src\render_list.cpp.obj -c F:\Projects\C++\OGAL\src\render_list.cpp

CMakeFiles/OGLAL.dir/src/render_list.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OGLAL.dir/src/render_list.cpp.i"
	F:\Programs\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Projects\C++\OGAL\src\render_list.cpp > CMakeFiles\OGLAL.dir\src\render_list.cpp.i

CMakeFiles/OGLAL.dir/src/render_list.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OGLAL.dir/src/render_list.cpp.s"
	F:\Programs\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Projects\C++\OGAL\src\render_list.cpp -o CMakeFiles\OGLAL.dir\src\render_list.cpp.s

CMakeFiles/OGLAL.dir/src/render_list.cpp.obj.requires:

.PHONY : CMakeFiles/OGLAL.dir/src/render_list.cpp.obj.requires

CMakeFiles/OGLAL.dir/src/render_list.cpp.obj.provides: CMakeFiles/OGLAL.dir/src/render_list.cpp.obj.requires
	$(MAKE) -f CMakeFiles\OGLAL.dir\build.make CMakeFiles/OGLAL.dir/src/render_list.cpp.obj.provides.build
.PHONY : CMakeFiles/OGLAL.dir/src/render_list.cpp.obj.provides

CMakeFiles/OGLAL.dir/src/render_list.cpp.obj.provides.build: CMakeFiles/OGLAL.dir/src/render_list.cpp.obj


CMakeFiles/OGLAL.dir/src/renderable.cpp.obj: CMakeFiles/OGLAL.dir/flags.make
CMakeFiles/OGLAL.dir/src/renderable.cpp.obj: CMakeFiles/OGLAL.dir/includes_CXX.rsp
CMakeFiles/OGLAL.dir/src/renderable.cpp.obj: ../src/renderable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Projects\C++\OGAL\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/OGLAL.dir/src/renderable.cpp.obj"
	F:\Programs\MinGW\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OGLAL.dir\src\renderable.cpp.obj -c F:\Projects\C++\OGAL\src\renderable.cpp

CMakeFiles/OGLAL.dir/src/renderable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OGLAL.dir/src/renderable.cpp.i"
	F:\Programs\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Projects\C++\OGAL\src\renderable.cpp > CMakeFiles\OGLAL.dir\src\renderable.cpp.i

CMakeFiles/OGLAL.dir/src/renderable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OGLAL.dir/src/renderable.cpp.s"
	F:\Programs\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Projects\C++\OGAL\src\renderable.cpp -o CMakeFiles\OGLAL.dir\src\renderable.cpp.s

CMakeFiles/OGLAL.dir/src/renderable.cpp.obj.requires:

.PHONY : CMakeFiles/OGLAL.dir/src/renderable.cpp.obj.requires

CMakeFiles/OGLAL.dir/src/renderable.cpp.obj.provides: CMakeFiles/OGLAL.dir/src/renderable.cpp.obj.requires
	$(MAKE) -f CMakeFiles\OGLAL.dir\build.make CMakeFiles/OGLAL.dir/src/renderable.cpp.obj.provides.build
.PHONY : CMakeFiles/OGLAL.dir/src/renderable.cpp.obj.provides

CMakeFiles/OGLAL.dir/src/renderable.cpp.obj.provides.build: CMakeFiles/OGLAL.dir/src/renderable.cpp.obj


CMakeFiles/OGLAL.dir/src/shader.cpp.obj: CMakeFiles/OGLAL.dir/flags.make
CMakeFiles/OGLAL.dir/src/shader.cpp.obj: CMakeFiles/OGLAL.dir/includes_CXX.rsp
CMakeFiles/OGLAL.dir/src/shader.cpp.obj: ../src/shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Projects\C++\OGAL\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/OGLAL.dir/src/shader.cpp.obj"
	F:\Programs\MinGW\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OGLAL.dir\src\shader.cpp.obj -c F:\Projects\C++\OGAL\src\shader.cpp

CMakeFiles/OGLAL.dir/src/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OGLAL.dir/src/shader.cpp.i"
	F:\Programs\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Projects\C++\OGAL\src\shader.cpp > CMakeFiles\OGLAL.dir\src\shader.cpp.i

CMakeFiles/OGLAL.dir/src/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OGLAL.dir/src/shader.cpp.s"
	F:\Programs\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Projects\C++\OGAL\src\shader.cpp -o CMakeFiles\OGLAL.dir\src\shader.cpp.s

CMakeFiles/OGLAL.dir/src/shader.cpp.obj.requires:

.PHONY : CMakeFiles/OGLAL.dir/src/shader.cpp.obj.requires

CMakeFiles/OGLAL.dir/src/shader.cpp.obj.provides: CMakeFiles/OGLAL.dir/src/shader.cpp.obj.requires
	$(MAKE) -f CMakeFiles\OGLAL.dir\build.make CMakeFiles/OGLAL.dir/src/shader.cpp.obj.provides.build
.PHONY : CMakeFiles/OGLAL.dir/src/shader.cpp.obj.provides

CMakeFiles/OGLAL.dir/src/shader.cpp.obj.provides.build: CMakeFiles/OGLAL.dir/src/shader.cpp.obj


CMakeFiles/OGLAL.dir/src/texture.cpp.obj: CMakeFiles/OGLAL.dir/flags.make
CMakeFiles/OGLAL.dir/src/texture.cpp.obj: CMakeFiles/OGLAL.dir/includes_CXX.rsp
CMakeFiles/OGLAL.dir/src/texture.cpp.obj: ../src/texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Projects\C++\OGAL\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/OGLAL.dir/src/texture.cpp.obj"
	F:\Programs\MinGW\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OGLAL.dir\src\texture.cpp.obj -c F:\Projects\C++\OGAL\src\texture.cpp

CMakeFiles/OGLAL.dir/src/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OGLAL.dir/src/texture.cpp.i"
	F:\Programs\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Projects\C++\OGAL\src\texture.cpp > CMakeFiles\OGLAL.dir\src\texture.cpp.i

CMakeFiles/OGLAL.dir/src/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OGLAL.dir/src/texture.cpp.s"
	F:\Programs\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Projects\C++\OGAL\src\texture.cpp -o CMakeFiles\OGLAL.dir\src\texture.cpp.s

CMakeFiles/OGLAL.dir/src/texture.cpp.obj.requires:

.PHONY : CMakeFiles/OGLAL.dir/src/texture.cpp.obj.requires

CMakeFiles/OGLAL.dir/src/texture.cpp.obj.provides: CMakeFiles/OGLAL.dir/src/texture.cpp.obj.requires
	$(MAKE) -f CMakeFiles\OGLAL.dir\build.make CMakeFiles/OGLAL.dir/src/texture.cpp.obj.provides.build
.PHONY : CMakeFiles/OGLAL.dir/src/texture.cpp.obj.provides

CMakeFiles/OGLAL.dir/src/texture.cpp.obj.provides.build: CMakeFiles/OGLAL.dir/src/texture.cpp.obj


CMakeFiles/OGLAL.dir/src/vao.cpp.obj: CMakeFiles/OGLAL.dir/flags.make
CMakeFiles/OGLAL.dir/src/vao.cpp.obj: CMakeFiles/OGLAL.dir/includes_CXX.rsp
CMakeFiles/OGLAL.dir/src/vao.cpp.obj: ../src/vao.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Projects\C++\OGAL\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/OGLAL.dir/src/vao.cpp.obj"
	F:\Programs\MinGW\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OGLAL.dir\src\vao.cpp.obj -c F:\Projects\C++\OGAL\src\vao.cpp

CMakeFiles/OGLAL.dir/src/vao.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OGLAL.dir/src/vao.cpp.i"
	F:\Programs\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Projects\C++\OGAL\src\vao.cpp > CMakeFiles\OGLAL.dir\src\vao.cpp.i

CMakeFiles/OGLAL.dir/src/vao.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OGLAL.dir/src/vao.cpp.s"
	F:\Programs\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Projects\C++\OGAL\src\vao.cpp -o CMakeFiles\OGLAL.dir\src\vao.cpp.s

CMakeFiles/OGLAL.dir/src/vao.cpp.obj.requires:

.PHONY : CMakeFiles/OGLAL.dir/src/vao.cpp.obj.requires

CMakeFiles/OGLAL.dir/src/vao.cpp.obj.provides: CMakeFiles/OGLAL.dir/src/vao.cpp.obj.requires
	$(MAKE) -f CMakeFiles\OGLAL.dir\build.make CMakeFiles/OGLAL.dir/src/vao.cpp.obj.provides.build
.PHONY : CMakeFiles/OGLAL.dir/src/vao.cpp.obj.provides

CMakeFiles/OGLAL.dir/src/vao.cpp.obj.provides.build: CMakeFiles/OGLAL.dir/src/vao.cpp.obj


CMakeFiles/OGLAL.dir/src/vbo.cpp.obj: CMakeFiles/OGLAL.dir/flags.make
CMakeFiles/OGLAL.dir/src/vbo.cpp.obj: CMakeFiles/OGLAL.dir/includes_CXX.rsp
CMakeFiles/OGLAL.dir/src/vbo.cpp.obj: ../src/vbo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Projects\C++\OGAL\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/OGLAL.dir/src/vbo.cpp.obj"
	F:\Programs\MinGW\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OGLAL.dir\src\vbo.cpp.obj -c F:\Projects\C++\OGAL\src\vbo.cpp

CMakeFiles/OGLAL.dir/src/vbo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OGLAL.dir/src/vbo.cpp.i"
	F:\Programs\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Projects\C++\OGAL\src\vbo.cpp > CMakeFiles\OGLAL.dir\src\vbo.cpp.i

CMakeFiles/OGLAL.dir/src/vbo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OGLAL.dir/src/vbo.cpp.s"
	F:\Programs\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Projects\C++\OGAL\src\vbo.cpp -o CMakeFiles\OGLAL.dir\src\vbo.cpp.s

CMakeFiles/OGLAL.dir/src/vbo.cpp.obj.requires:

.PHONY : CMakeFiles/OGLAL.dir/src/vbo.cpp.obj.requires

CMakeFiles/OGLAL.dir/src/vbo.cpp.obj.provides: CMakeFiles/OGLAL.dir/src/vbo.cpp.obj.requires
	$(MAKE) -f CMakeFiles\OGLAL.dir\build.make CMakeFiles/OGLAL.dir/src/vbo.cpp.obj.provides.build
.PHONY : CMakeFiles/OGLAL.dir/src/vbo.cpp.obj.provides

CMakeFiles/OGLAL.dir/src/vbo.cpp.obj.provides.build: CMakeFiles/OGLAL.dir/src/vbo.cpp.obj


CMakeFiles/OGLAL.dir/src/shapes/equilateral_triangle.cpp.obj: CMakeFiles/OGLAL.dir/flags.make
CMakeFiles/OGLAL.dir/src/shapes/equilateral_triangle.cpp.obj: CMakeFiles/OGLAL.dir/includes_CXX.rsp
CMakeFiles/OGLAL.dir/src/shapes/equilateral_triangle.cpp.obj: ../src/shapes/equilateral_triangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Projects\C++\OGAL\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/OGLAL.dir/src/shapes/equilateral_triangle.cpp.obj"
	F:\Programs\MinGW\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OGLAL.dir\src\shapes\equilateral_triangle.cpp.obj -c F:\Projects\C++\OGAL\src\shapes\equilateral_triangle.cpp

CMakeFiles/OGLAL.dir/src/shapes/equilateral_triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OGLAL.dir/src/shapes/equilateral_triangle.cpp.i"
	F:\Programs\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Projects\C++\OGAL\src\shapes\equilateral_triangle.cpp > CMakeFiles\OGLAL.dir\src\shapes\equilateral_triangle.cpp.i

CMakeFiles/OGLAL.dir/src/shapes/equilateral_triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OGLAL.dir/src/shapes/equilateral_triangle.cpp.s"
	F:\Programs\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Projects\C++\OGAL\src\shapes\equilateral_triangle.cpp -o CMakeFiles\OGLAL.dir\src\shapes\equilateral_triangle.cpp.s

CMakeFiles/OGLAL.dir/src/shapes/equilateral_triangle.cpp.obj.requires:

.PHONY : CMakeFiles/OGLAL.dir/src/shapes/equilateral_triangle.cpp.obj.requires

CMakeFiles/OGLAL.dir/src/shapes/equilateral_triangle.cpp.obj.provides: CMakeFiles/OGLAL.dir/src/shapes/equilateral_triangle.cpp.obj.requires
	$(MAKE) -f CMakeFiles\OGLAL.dir\build.make CMakeFiles/OGLAL.dir/src/shapes/equilateral_triangle.cpp.obj.provides.build
.PHONY : CMakeFiles/OGLAL.dir/src/shapes/equilateral_triangle.cpp.obj.provides

CMakeFiles/OGLAL.dir/src/shapes/equilateral_triangle.cpp.obj.provides.build: CMakeFiles/OGLAL.dir/src/shapes/equilateral_triangle.cpp.obj


CMakeFiles/OGLAL.dir/src/shapes/square.cpp.obj: CMakeFiles/OGLAL.dir/flags.make
CMakeFiles/OGLAL.dir/src/shapes/square.cpp.obj: CMakeFiles/OGLAL.dir/includes_CXX.rsp
CMakeFiles/OGLAL.dir/src/shapes/square.cpp.obj: ../src/shapes/square.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Projects\C++\OGAL\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/OGLAL.dir/src/shapes/square.cpp.obj"
	F:\Programs\MinGW\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OGLAL.dir\src\shapes\square.cpp.obj -c F:\Projects\C++\OGAL\src\shapes\square.cpp

CMakeFiles/OGLAL.dir/src/shapes/square.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OGLAL.dir/src/shapes/square.cpp.i"
	F:\Programs\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Projects\C++\OGAL\src\shapes\square.cpp > CMakeFiles\OGLAL.dir\src\shapes\square.cpp.i

CMakeFiles/OGLAL.dir/src/shapes/square.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OGLAL.dir/src/shapes/square.cpp.s"
	F:\Programs\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Projects\C++\OGAL\src\shapes\square.cpp -o CMakeFiles\OGLAL.dir\src\shapes\square.cpp.s

CMakeFiles/OGLAL.dir/src/shapes/square.cpp.obj.requires:

.PHONY : CMakeFiles/OGLAL.dir/src/shapes/square.cpp.obj.requires

CMakeFiles/OGLAL.dir/src/shapes/square.cpp.obj.provides: CMakeFiles/OGLAL.dir/src/shapes/square.cpp.obj.requires
	$(MAKE) -f CMakeFiles\OGLAL.dir\build.make CMakeFiles/OGLAL.dir/src/shapes/square.cpp.obj.provides.build
.PHONY : CMakeFiles/OGLAL.dir/src/shapes/square.cpp.obj.provides

CMakeFiles/OGLAL.dir/src/shapes/square.cpp.obj.provides.build: CMakeFiles/OGLAL.dir/src/shapes/square.cpp.obj


# Object files for target OGLAL
OGLAL_OBJECTS = \
"CMakeFiles/OGLAL.dir/src/OGAL.cpp.obj" \
"CMakeFiles/OGLAL.dir/src/event.cpp.obj" \
"CMakeFiles/OGLAL.dir/src/main.cpp.obj" \
"CMakeFiles/OGLAL.dir/src/program.cpp.obj" \
"CMakeFiles/OGLAL.dir/src/render_list.cpp.obj" \
"CMakeFiles/OGLAL.dir/src/renderable.cpp.obj" \
"CMakeFiles/OGLAL.dir/src/shader.cpp.obj" \
"CMakeFiles/OGLAL.dir/src/texture.cpp.obj" \
"CMakeFiles/OGLAL.dir/src/vao.cpp.obj" \
"CMakeFiles/OGLAL.dir/src/vbo.cpp.obj" \
"CMakeFiles/OGLAL.dir/src/shapes/equilateral_triangle.cpp.obj" \
"CMakeFiles/OGLAL.dir/src/shapes/square.cpp.obj"

# External object files for target OGLAL
OGLAL_EXTERNAL_OBJECTS =

../run/OGLAL.exe: CMakeFiles/OGLAL.dir/src/OGAL.cpp.obj
../run/OGLAL.exe: CMakeFiles/OGLAL.dir/src/event.cpp.obj
../run/OGLAL.exe: CMakeFiles/OGLAL.dir/src/main.cpp.obj
../run/OGLAL.exe: CMakeFiles/OGLAL.dir/src/program.cpp.obj
../run/OGLAL.exe: CMakeFiles/OGLAL.dir/src/render_list.cpp.obj
../run/OGLAL.exe: CMakeFiles/OGLAL.dir/src/renderable.cpp.obj
../run/OGLAL.exe: CMakeFiles/OGLAL.dir/src/shader.cpp.obj
../run/OGLAL.exe: CMakeFiles/OGLAL.dir/src/texture.cpp.obj
../run/OGLAL.exe: CMakeFiles/OGLAL.dir/src/vao.cpp.obj
../run/OGLAL.exe: CMakeFiles/OGLAL.dir/src/vbo.cpp.obj
../run/OGLAL.exe: CMakeFiles/OGLAL.dir/src/shapes/equilateral_triangle.cpp.obj
../run/OGLAL.exe: CMakeFiles/OGLAL.dir/src/shapes/square.cpp.obj
../run/OGLAL.exe: CMakeFiles/OGLAL.dir/build.make
../run/OGLAL.exe: CMakeFiles/OGLAL.dir/linklibs.rsp
../run/OGLAL.exe: CMakeFiles/OGLAL.dir/objects1.rsp
../run/OGLAL.exe: CMakeFiles/OGLAL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\Projects\C++\OGAL\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable ..\run\OGLAL.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\OGLAL.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OGLAL.dir/build: ../run/OGLAL.exe

.PHONY : CMakeFiles/OGLAL.dir/build

CMakeFiles/OGLAL.dir/requires: CMakeFiles/OGLAL.dir/src/OGAL.cpp.obj.requires
CMakeFiles/OGLAL.dir/requires: CMakeFiles/OGLAL.dir/src/event.cpp.obj.requires
CMakeFiles/OGLAL.dir/requires: CMakeFiles/OGLAL.dir/src/main.cpp.obj.requires
CMakeFiles/OGLAL.dir/requires: CMakeFiles/OGLAL.dir/src/program.cpp.obj.requires
CMakeFiles/OGLAL.dir/requires: CMakeFiles/OGLAL.dir/src/render_list.cpp.obj.requires
CMakeFiles/OGLAL.dir/requires: CMakeFiles/OGLAL.dir/src/renderable.cpp.obj.requires
CMakeFiles/OGLAL.dir/requires: CMakeFiles/OGLAL.dir/src/shader.cpp.obj.requires
CMakeFiles/OGLAL.dir/requires: CMakeFiles/OGLAL.dir/src/texture.cpp.obj.requires
CMakeFiles/OGLAL.dir/requires: CMakeFiles/OGLAL.dir/src/vao.cpp.obj.requires
CMakeFiles/OGLAL.dir/requires: CMakeFiles/OGLAL.dir/src/vbo.cpp.obj.requires
CMakeFiles/OGLAL.dir/requires: CMakeFiles/OGLAL.dir/src/shapes/equilateral_triangle.cpp.obj.requires
CMakeFiles/OGLAL.dir/requires: CMakeFiles/OGLAL.dir/src/shapes/square.cpp.obj.requires

.PHONY : CMakeFiles/OGLAL.dir/requires

CMakeFiles/OGLAL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\OGLAL.dir\cmake_clean.cmake
.PHONY : CMakeFiles/OGLAL.dir/clean

CMakeFiles/OGLAL.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\Projects\C++\OGAL F:\Projects\C++\OGAL F:\Projects\C++\OGAL\build F:\Projects\C++\OGAL\build F:\Projects\C++\OGAL\build\CMakeFiles\OGLAL.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OGLAL.dir/depend

