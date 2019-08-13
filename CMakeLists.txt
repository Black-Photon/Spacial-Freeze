cmake_minimum_required(VERSION 3.12)
project(SpacialFreeze)

set(CMAKE_CXX_STANDARD 17)

# Project Files
add_executable(
        SpacialFreeze

        src/main.cpp

        # Library Includes
        src/glad.c
        include/glad/glad.h
        include/stb_image.h

        # Class files
#        src/classes/Camera.cpp src/classes/Shader.cpp src/classes/SquareMesh.cpp src/classes/Model.cpp
#        src/classes/Lightning.cpp src/classes/Framebuffer.cpp src/classes/Mesh.cpp classes/Scene.cpp
#        classes/Instance.cpp

        # Helper files
#        src/logger.cpp src/texture.cpp src/error.cpp
        )

# GLFW / GLAD
add_subdirectory("include/glfw-3.2.1/")
include_directories(include)
include_directories(include/glfw-3.2.1/deps)
include_directories(include/glad)

# Assimp
if(WIN32)
        include_directories(include/win32)
        include_directories(include/win32/assimp)
endif()
if(UNIX)
        add_subdirectory(include/assimp-src)
        include_directories(include/assimp-src/include include/assimp-src/out/include)
endif()
set(BUILD_ASSIMP_TOOLS  ON)
set(ASSIMP_BUILD_STATIC_LIB ON)

# Link all
if(WIN32)
        add_library( assimp STATIC IMPORTED )
        set_target_properties( assimp PROPERTIES IMPORTED_LOCATION "C:/Program Files/Assimp/lib/x64/assimp-vc140-mt.lib" )
endif()
target_link_libraries(SpacialFreeze glfw assimp)