#ifndef SPACIALFREEZE_CUBEMODEL_H
#define SPACIALFREEZE_CUBEMODEL_H

#include <glm/glm.hpp>
#include "Shader.h"
#include "Model.h"

static constexpr float SIZE = 1.0f;

static constexpr float vertices[] = {
        // Position          // Texture  // Normal
        // Back Face
        -SIZE, -SIZE, -SIZE, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f,
        SIZE,  SIZE, -SIZE, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f,
        SIZE, -SIZE, -SIZE, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f,
        SIZE,  SIZE, -SIZE, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f,
        -SIZE, -SIZE, -SIZE, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f,
        -SIZE,  SIZE, -SIZE, 0.0f, 1.0f, 0.0f, 0.0f, -1.0f,

        // Front Face
        -SIZE, -SIZE,  SIZE, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        SIZE, -SIZE,  SIZE, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        SIZE,  SIZE,  SIZE, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        SIZE,  SIZE,  SIZE, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        -SIZE,  SIZE,  SIZE, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        -SIZE, -SIZE,  SIZE, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,

        // Left Face
        -SIZE,  SIZE,  SIZE, 1.0f, 1.0f, -1.0f, 0.0f, 0.0f,
        -SIZE,  SIZE, -SIZE, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f,
        -SIZE, -SIZE, -SIZE, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
        -SIZE, -SIZE, -SIZE, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
        -SIZE, -SIZE,  SIZE, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f,
        -SIZE,  SIZE,  SIZE, 1.0f, 1.0f, -1.0f, 0.0f, 0.0f,

        // Right Face
        SIZE,  SIZE,  SIZE, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        SIZE, -SIZE, -SIZE, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        SIZE,  SIZE, -SIZE, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        SIZE, -SIZE, -SIZE, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        SIZE,  SIZE,  SIZE, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        SIZE, -SIZE,  SIZE, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f,

        // Bottom Face
        -SIZE, -SIZE, -SIZE, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f,
        SIZE, -SIZE, -SIZE, 1.0f, 1.0f, 0.0f, -1.0f, 0.0f,
        SIZE, -SIZE,  SIZE, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f,
        SIZE, -SIZE,  SIZE, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f,
        -SIZE, -SIZE,  SIZE, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f,
        -SIZE, -SIZE, -SIZE, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f,

        // Top Face
        -SIZE,  SIZE, -SIZE, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        SIZE,  SIZE,  SIZE, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        SIZE,  SIZE, -SIZE, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        SIZE,  SIZE,  SIZE, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        -SIZE,  SIZE, -SIZE, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        -SIZE,  SIZE,  SIZE, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f
};

class CubeModel : public Model {
public:
    CubeModel();
    void draw(glm::vec3 position, Shader &shader);
};


#endif //SPACIALFREEZE_CUBEMODEL_H
