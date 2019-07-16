#include <glm/ext/matrix_transform.hpp>
#include "SquareModel.h"

SquareModel::SquareModel() : Model((float*) squareVertices, 24)
{
    addAttribute(2); // Position
    addAttribute(2); // Texture
    setAttributes();

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void SquareModel::draw(Shader &shader)
{
    glDrawArrays(GL_TRIANGLES, 0, 6);
}