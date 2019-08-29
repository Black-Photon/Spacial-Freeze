#include "headers/BoxColliderComponent.h"

void BoxColliderComponent::update(float deltaT) {
    transformation->position += glm::vec3(0.0f, deltaT * 0.01f, 0.0f);
}
