cmake_minimum_required(VERSION 3.12)
project(SpacialFreeze)

set(CMAKE_CXX_STANDARD 17)

# Project Files
add_executable(
        SpacialFreeze

        ./main.cpp

        # Library Includes
        src/glad.c
        include/glad/glad.h
        include/stb_image.h

        # Class files
        classes/Camera.cpp classes/Shader.cpp classes/SquareMesh.cpp classes/Model.cpp
        classes/Lightning.cpp classes/Framebuffer.cpp classes/Mesh.cpp #classes/Scene.cpp
        #classes/Instance.cpp

        # Helper files
        src/logger.cpp src/texture.cpp src/error.cpp
        )

# GLFW / GLAD
add_subdirectory("include/glfw-3.2.1/")
include_directories(include)

# Assimp
add_subdirectory(include/assimp)
include_directories(include/assimp/include include/assimp/out/include)
set(BUILD_ASSIMP_TOOLS  ON)
set(ASSIMP_BUILD_STATIC_LIB ON)

# Link all
target_link_libraries(SpacialFreeze glfw assimp)