#include <glm/gtc/matrix_transform.hpp>
#include "Instance.h"

long Instance::lastID = 0;

Instance::Instance(Model &model, Shader &shader) : shader(shader), model(&model) {
    ID = lastID++;
}

void Instance::setPosition(glm::vec3 pos) {
    position = pos;
}

void Instance::setSize(float newSize) {
    size = newSize;
}

void Instance::draw() {
    shader.use();
    core::makeModel(shader, *core::Data.camera);
    draw(shader);
}

void Instance::draw(Shader &altShader) {
    glm::mat4 modelMat = glm::mat4(1.0f);
    modelMat = glm::scale(modelMat, glm::vec3(size * 0.1f));
    modelMat = glm::translate(modelMat, position);
    altShader.setMat4("model", modelMat);
    model->draw(altShader);
}