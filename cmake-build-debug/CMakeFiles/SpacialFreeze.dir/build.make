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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/joseph/Documents/Programming/Graphics/Spacial-Freeze

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SpacialFreeze.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SpacialFreeze.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SpacialFreeze.dir/flags.make

CMakeFiles/SpacialFreeze.dir/main.cpp.o: CMakeFiles/SpacialFreeze.dir/flags.make
CMakeFiles/SpacialFreeze.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joseph/Documents/Programming/Graphics/Spacial-Freeze/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SpacialFreeze.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SpacialFreeze.dir/main.cpp.o -c /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/main.cpp

CMakeFiles/SpacialFreeze.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SpacialFreeze.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/main.cpp > CMakeFiles/SpacialFreeze.dir/main.cpp.i

CMakeFiles/SpacialFreeze.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SpacialFreeze.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/main.cpp -o CMakeFiles/SpacialFreeze.dir/main.cpp.s

CMakeFiles/SpacialFreeze.dir/src/glad.c.o: CMakeFiles/SpacialFreeze.dir/flags.make
CMakeFiles/SpacialFreeze.dir/src/glad.c.o: ../src/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joseph/Documents/Programming/Graphics/Spacial-Freeze/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/SpacialFreeze.dir/src/glad.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SpacialFreeze.dir/src/glad.c.o   -c /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/src/glad.c

CMakeFiles/SpacialFreeze.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SpacialFreeze.dir/src/glad.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/src/glad.c > CMakeFiles/SpacialFreeze.dir/src/glad.c.i

CMakeFiles/SpacialFreeze.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SpacialFreeze.dir/src/glad.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/src/glad.c -o CMakeFiles/SpacialFreeze.dir/src/glad.c.s

CMakeFiles/SpacialFreeze.dir/classes/Camera.cpp.o: CMakeFiles/SpacialFreeze.dir/flags.make
CMakeFiles/SpacialFreeze.dir/classes/Camera.cpp.o: ../classes/Camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joseph/Documents/Programming/Graphics/Spacial-Freeze/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SpacialFreeze.dir/classes/Camera.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SpacialFreeze.dir/classes/Camera.cpp.o -c /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/classes/Camera.cpp

CMakeFiles/SpacialFreeze.dir/classes/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SpacialFreeze.dir/classes/Camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/classes/Camera.cpp > CMakeFiles/SpacialFreeze.dir/classes/Camera.cpp.i

CMakeFiles/SpacialFreeze.dir/classes/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SpacialFreeze.dir/classes/Camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/classes/Camera.cpp -o CMakeFiles/SpacialFreeze.dir/classes/Camera.cpp.s

CMakeFiles/SpacialFreeze.dir/classes/Shader.cpp.o: CMakeFiles/SpacialFreeze.dir/flags.make
CMakeFiles/SpacialFreeze.dir/classes/Shader.cpp.o: ../classes/Shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joseph/Documents/Programming/Graphics/Spacial-Freeze/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SpacialFreeze.dir/classes/Shader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SpacialFreeze.dir/classes/Shader.cpp.o -c /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/classes/Shader.cpp

CMakeFiles/SpacialFreeze.dir/classes/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SpacialFreeze.dir/classes/Shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/classes/Shader.cpp > CMakeFiles/SpacialFreeze.dir/classes/Shader.cpp.i

CMakeFiles/SpacialFreeze.dir/classes/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SpacialFreeze.dir/classes/Shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/classes/Shader.cpp -o CMakeFiles/SpacialFreeze.dir/classes/Shader.cpp.s

CMakeFiles/SpacialFreeze.dir/classes/Model.cpp.o: CMakeFiles/SpacialFreeze.dir/flags.make
CMakeFiles/SpacialFreeze.dir/classes/Model.cpp.o: ../classes/Model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joseph/Documents/Programming/Graphics/Spacial-Freeze/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SpacialFreeze.dir/classes/Model.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SpacialFreeze.dir/classes/Model.cpp.o -c /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/classes/Model.cpp

CMakeFiles/SpacialFreeze.dir/classes/Model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SpacialFreeze.dir/classes/Model.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/classes/Model.cpp > CMakeFiles/SpacialFreeze.dir/classes/Model.cpp.i

CMakeFiles/SpacialFreeze.dir/classes/Model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SpacialFreeze.dir/classes/Model.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/classes/Model.cpp -o CMakeFiles/SpacialFreeze.dir/classes/Model.cpp.s

CMakeFiles/SpacialFreeze.dir/classes/CubeModel.cpp.o: CMakeFiles/SpacialFreeze.dir/flags.make
CMakeFiles/SpacialFreeze.dir/classes/CubeModel.cpp.o: ../classes/CubeModel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joseph/Documents/Programming/Graphics/Spacial-Freeze/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SpacialFreeze.dir/classes/CubeModel.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SpacialFreeze.dir/classes/CubeModel.cpp.o -c /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/classes/CubeModel.cpp

CMakeFiles/SpacialFreeze.dir/classes/CubeModel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SpacialFreeze.dir/classes/CubeModel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/classes/CubeModel.cpp > CMakeFiles/SpacialFreeze.dir/classes/CubeModel.cpp.i

CMakeFiles/SpacialFreeze.dir/classes/CubeModel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SpacialFreeze.dir/classes/CubeModel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/classes/CubeModel.cpp -o CMakeFiles/SpacialFreeze.dir/classes/CubeModel.cpp.s

CMakeFiles/SpacialFreeze.dir/classes/SquareModel.cpp.o: CMakeFiles/SpacialFreeze.dir/flags.make
CMakeFiles/SpacialFreeze.dir/classes/SquareModel.cpp.o: ../classes/SquareModel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joseph/Documents/Programming/Graphics/Spacial-Freeze/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/SpacialFreeze.dir/classes/SquareModel.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SpacialFreeze.dir/classes/SquareModel.cpp.o -c /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/classes/SquareModel.cpp

CMakeFiles/SpacialFreeze.dir/classes/SquareModel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SpacialFreeze.dir/classes/SquareModel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/classes/SquareModel.cpp > CMakeFiles/SpacialFreeze.dir/classes/SquareModel.cpp.i

CMakeFiles/SpacialFreeze.dir/classes/SquareModel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SpacialFreeze.dir/classes/SquareModel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/classes/SquareModel.cpp -o CMakeFiles/SpacialFreeze.dir/classes/SquareModel.cpp.s

CMakeFiles/SpacialFreeze.dir/classes/Lightning.cpp.o: CMakeFiles/SpacialFreeze.dir/flags.make
CMakeFiles/SpacialFreeze.dir/classes/Lightning.cpp.o: ../classes/Lightning.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joseph/Documents/Programming/Graphics/Spacial-Freeze/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/SpacialFreeze.dir/classes/Lightning.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SpacialFreeze.dir/classes/Lightning.cpp.o -c /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/classes/Lightning.cpp

CMakeFiles/SpacialFreeze.dir/classes/Lightning.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SpacialFreeze.dir/classes/Lightning.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/classes/Lightning.cpp > CMakeFiles/SpacialFreeze.dir/classes/Lightning.cpp.i

CMakeFiles/SpacialFreeze.dir/classes/Lightning.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SpacialFreeze.dir/classes/Lightning.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/classes/Lightning.cpp -o CMakeFiles/SpacialFreeze.dir/classes/Lightning.cpp.s

# Object files for target SpacialFreeze
SpacialFreeze_OBJECTS = \
"CMakeFiles/SpacialFreeze.dir/main.cpp.o" \
"CMakeFiles/SpacialFreeze.dir/src/glad.c.o" \
"CMakeFiles/SpacialFreeze.dir/classes/Camera.cpp.o" \
"CMakeFiles/SpacialFreeze.dir/classes/Shader.cpp.o" \
"CMakeFiles/SpacialFreeze.dir/classes/Model.cpp.o" \
"CMakeFiles/SpacialFreeze.dir/classes/CubeModel.cpp.o" \
"CMakeFiles/SpacialFreeze.dir/classes/SquareModel.cpp.o" \
"CMakeFiles/SpacialFreeze.dir/classes/Lightning.cpp.o"

# External object files for target SpacialFreeze
SpacialFreeze_EXTERNAL_OBJECTS =

SpacialFreeze: CMakeFiles/SpacialFreeze.dir/main.cpp.o
SpacialFreeze: CMakeFiles/SpacialFreeze.dir/src/glad.c.o
SpacialFreeze: CMakeFiles/SpacialFreeze.dir/classes/Camera.cpp.o
SpacialFreeze: CMakeFiles/SpacialFreeze.dir/classes/Shader.cpp.o
SpacialFreeze: CMakeFiles/SpacialFreeze.dir/classes/Model.cpp.o
SpacialFreeze: CMakeFiles/SpacialFreeze.dir/classes/CubeModel.cpp.o
SpacialFreeze: CMakeFiles/SpacialFreeze.dir/classes/SquareModel.cpp.o
SpacialFreeze: CMakeFiles/SpacialFreeze.dir/classes/Lightning.cpp.o
SpacialFreeze: CMakeFiles/SpacialFreeze.dir/build.make
SpacialFreeze: include/glfw-3.2.1/src/libglfw3.a
SpacialFreeze: /usr/lib/librt.so
SpacialFreeze: /usr/lib/libm.so
SpacialFreeze: /usr/lib/libX11.so
SpacialFreeze: /usr/lib/libXrandr.so
SpacialFreeze: /usr/lib/libXinerama.so
SpacialFreeze: /usr/lib/libXxf86vm.so
SpacialFreeze: /usr/lib/libXcursor.so
SpacialFreeze: CMakeFiles/SpacialFreeze.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/joseph/Documents/Programming/Graphics/Spacial-Freeze/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable SpacialFreeze"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SpacialFreeze.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SpacialFreeze.dir/build: SpacialFreeze

.PHONY : CMakeFiles/SpacialFreeze.dir/build

CMakeFiles/SpacialFreeze.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SpacialFreeze.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SpacialFreeze.dir/clean

CMakeFiles/SpacialFreeze.dir/depend:
	cd /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/joseph/Documents/Programming/Graphics/Spacial-Freeze /home/joseph/Documents/Programming/Graphics/Spacial-Freeze /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/cmake-build-debug /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/cmake-build-debug /home/joseph/Documents/Programming/Graphics/Spacial-Freeze/cmake-build-debug/CMakeFiles/SpacialFreeze.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SpacialFreeze.dir/depend

