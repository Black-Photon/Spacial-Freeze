#include "headers/Transformation.h"

glm::mat4 Transformation::getMatrix()  {
    glm::mat4 matrix = glm::mat4(1.0f);
    matrix = glm::translate(matrix, position);
    matrix = glm::scale(matrix, glm::vec3(size * 0.1f));
    return matrix;
}