#include <glad/glad.h>
#include "Lightning.h"

void Lightning::update(float std) {
    for(float & i : data) {
        i = update(i, std);
    }
}

int Lightning::getTexture() const {
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_1D, texture);

    glTexImage1D(GL_TEXTURE_1D, 0, GL_DEPTH_COMPONENT, 1024, 0, GL_DEPTH_COMPONENT, GL_FLOAT, data);
    glGenerateMipmap(GL_TEXTURE_1D);
    return texture;
}

float Lightning::update(float initial, float std) {
    initial = (initial * 2) - 1;

    std::mt19937 gen(rd());
    std::normal_distribution<float> distribution(initial/2, std);
    float result = distribution(gen);
    result = (result + 1) / 2;
    return result;
}