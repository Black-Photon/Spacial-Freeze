#include <glm/ext/matrix_transform.hpp>
#include "CubeModel.h"

CubeModel::CubeModel() : Model((float*) vertices, 288)
{
    addAttribute(3); // Position
    addAttribute(2); // Texture
    addAttribute(3); // Normal
    setAttributes();

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void CubeModel::draw(glm::vec3 position, Shader &shader)
{
    glm::mat4 model = glm::translate(glm::mat4(1.0f), position);
    shader.setMat4("model", model);

    glDrawArrays(GL_TRIANGLES, 0, 36);
}