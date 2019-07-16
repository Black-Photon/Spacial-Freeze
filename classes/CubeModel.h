#ifndef SPACIALFREEZE_CUBEMODEL_H
#define SPACIALFREEZE_CUBEMODEL_H

#include <glm/glm.hpp>
#include "Shader.h"
#include "Model.h"

static constexpr float CUBESIZE = 1.0f;

static constexpr float cubeVertices[] = {
        // Position          // Texture  // Normal
        // Back Face
        -CUBESIZE, -CUBESIZE, -CUBESIZE, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f,
        CUBESIZE,  CUBESIZE, -CUBESIZE, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f,
        CUBESIZE, -CUBESIZE, -CUBESIZE, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f,
        CUBESIZE,  CUBESIZE, -CUBESIZE, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f,
        -CUBESIZE, -CUBESIZE, -CUBESIZE, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f,
        -CUBESIZE,  CUBESIZE, -CUBESIZE, 0.0f, 1.0f, 0.0f, 0.0f, -1.0f,

        // Front Face
        -CUBESIZE, -CUBESIZE,  CUBESIZE, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        CUBESIZE, -CUBESIZE,  CUBESIZE, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        CUBESIZE,  CUBESIZE,  CUBESIZE, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        CUBESIZE,  CUBESIZE,  CUBESIZE, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        -CUBESIZE,  CUBESIZE,  CUBESIZE, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        -CUBESIZE, -CUBESIZE,  CUBESIZE, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,

        // Left Face
        -CUBESIZE,  CUBESIZE,  CUBESIZE, 1.0f, 1.0f, -1.0f, 0.0f, 0.0f,
        -CUBESIZE,  CUBESIZE, -CUBESIZE, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f,
        -CUBESIZE, -CUBESIZE, -CUBESIZE, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
        -CUBESIZE, -CUBESIZE, -CUBESIZE, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
        -CUBESIZE, -CUBESIZE,  CUBESIZE, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f,
        -CUBESIZE,  CUBESIZE,  CUBESIZE, 1.0f, 1.0f, -1.0f, 0.0f, 0.0f,

        // Right Face
        CUBESIZE,  CUBESIZE,  CUBESIZE, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        CUBESIZE, -CUBESIZE, -CUBESIZE, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        CUBESIZE,  CUBESIZE, -CUBESIZE, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        CUBESIZE, -CUBESIZE, -CUBESIZE, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        CUBESIZE,  CUBESIZE,  CUBESIZE, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        CUBESIZE, -CUBESIZE,  CUBESIZE, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f,

        // Bottom Face
        -CUBESIZE, -CUBESIZE, -CUBESIZE, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f,
        CUBESIZE, -CUBESIZE, -CUBESIZE, 1.0f, 1.0f, 0.0f, -1.0f, 0.0f,
        CUBESIZE, -CUBESIZE,  CUBESIZE, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f,
        CUBESIZE, -CUBESIZE,  CUBESIZE, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f,
        -CUBESIZE, -CUBESIZE,  CUBESIZE, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f,
        -CUBESIZE, -CUBESIZE, -CUBESIZE, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f,

        // Top Face
        -CUBESIZE,  CUBESIZE, -CUBESIZE, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        CUBESIZE,  CUBESIZE,  CUBESIZE, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        CUBESIZE,  CUBESIZE, -CUBESIZE, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        CUBESIZE,  CUBESIZE,  CUBESIZE, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        -CUBESIZE,  CUBESIZE, -CUBESIZE, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        -CUBESIZE,  CUBESIZE,  CUBESIZE, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f
};

class CubeModel : public Model {
public:
    CubeModel();
    void draw(glm::vec3 position, Shader &shader);
};


#endif //SPACIALFREEZE_CUBEMODEL_H
