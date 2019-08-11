#include <glm/gtc/matrix_transform.hpp>
#include "Instance.h"

long Instance::lastID = 0;

Instance::Instance(Model &model, Shader shader) : shader(shader), model(&model) {
    ID = lastID++;
}

void Instance::setPosition(glm::vec3 pos) {
    position = pos;
}

void Instance::draw() {
    draw(shader);
}

void Instance::draw(Shader shader) {
    glm::mat4 modelMat = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
//    modelMat = glm::scale(modelMat, glm::vec3(size * 0.1f));
    modelMat = glm::translate(modelMat, glm::vec3(0.0f, 0.0f, 0.0f));
    shader.setMat4("model", modelMat);
    model->draw(shader);
}