# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_SOURCE_DIR = /home/lotherxuan/workspace/my-renderer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lotherxuan/workspace/my-renderer/build

# Include any dependencies generated for this target.
include CMakeFiles/shader_library.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/shader_library.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/shader_library.dir/flags.make

CMakeFiles/shader_library.dir/lib/shaders/src/gouraud_shader.cc.o: CMakeFiles/shader_library.dir/flags.make
CMakeFiles/shader_library.dir/lib/shaders/src/gouraud_shader.cc.o: ../lib/shaders/src/gouraud_shader.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lotherxuan/workspace/my-renderer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/shader_library.dir/lib/shaders/src/gouraud_shader.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shader_library.dir/lib/shaders/src/gouraud_shader.cc.o -c /home/lotherxuan/workspace/my-renderer/lib/shaders/src/gouraud_shader.cc

CMakeFiles/shader_library.dir/lib/shaders/src/gouraud_shader.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shader_library.dir/lib/shaders/src/gouraud_shader.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lotherxuan/workspace/my-renderer/lib/shaders/src/gouraud_shader.cc > CMakeFiles/shader_library.dir/lib/shaders/src/gouraud_shader.cc.i

CMakeFiles/shader_library.dir/lib/shaders/src/gouraud_shader.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shader_library.dir/lib/shaders/src/gouraud_shader.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lotherxuan/workspace/my-renderer/lib/shaders/src/gouraud_shader.cc -o CMakeFiles/shader_library.dir/lib/shaders/src/gouraud_shader.cc.s

# Object files for target shader_library
shader_library_OBJECTS = \
"CMakeFiles/shader_library.dir/lib/shaders/src/gouraud_shader.cc.o"

# External object files for target shader_library
shader_library_EXTERNAL_OBJECTS =

libshader_library.a: CMakeFiles/shader_library.dir/lib/shaders/src/gouraud_shader.cc.o
libshader_library.a: CMakeFiles/shader_library.dir/build.make
libshader_library.a: CMakeFiles/shader_library.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lotherxuan/workspace/my-renderer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libshader_library.a"
	$(CMAKE_COMMAND) -P CMakeFiles/shader_library.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/shader_library.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/shader_library.dir/build: libshader_library.a

.PHONY : CMakeFiles/shader_library.dir/build

CMakeFiles/shader_library.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/shader_library.dir/cmake_clean.cmake
.PHONY : CMakeFiles/shader_library.dir/clean

CMakeFiles/shader_library.dir/depend:
	cd /home/lotherxuan/workspace/my-renderer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lotherxuan/workspace/my-renderer /home/lotherxuan/workspace/my-renderer /home/lotherxuan/workspace/my-renderer/build /home/lotherxuan/workspace/my-renderer/build /home/lotherxuan/workspace/my-renderer/build/CMakeFiles/shader_library.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/shader_library.dir/depend

