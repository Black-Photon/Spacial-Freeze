cmake_minimum_required(VERSION 3.12)
project(SpacialFreeze)

set(CMAKE_CXX_STANDARD 17)

# GLaDOS

include_directories(include)

add_executable(SpacialFreeze
        ./main.cpp
        src/glad.c
        include/glad/glad.h
        include/stb_image.h
        classes/Camera.cpp classes/Shader.cpp classes/Model.cpp classes/CubeModel.cpp classes/SquareModel.cpp classes/Lightning.cpp)

# GLFW

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory("/home/joseph/Documents/Programming/Graphics/Spacial-Freeze/include/glfw-3.2.1/")
target_link_libraries(SpacialFreeze glfw)