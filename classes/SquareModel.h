#ifndef SPACIALFREEZE_SQUAREMODEL_H
#define SPACIALFREEZE_SQAUREMODEL_H

#include <glm/glm.hpp>
#include "Shader.h"
#include "Model.h"

static constexpr float squareVertices[] = {
        // Position          // Texture
        -1.0f, -1.0f, 0.0f, 0.0f,
        1.0f, -1.0f, 1.0f, 0.0f,
        -1.0f,  1.0f, 0.0f, 1.0f,
        1.0f,  1.0f, 1.0f, 1.0f,
        -1.0f,  1.0f, 0.0f, 1.0f,
        1.0f, -1.0f, 1.0f, 0.0f
};

class SquareModel : public Model {
public:
    SquareModel();
    void draw(Shader &shader);
};


#endif //SPACIALFREEZE_SQUAREMODEL_H
