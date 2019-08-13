#ifndef SPACIALFREEZE_TRANSFORMATION_H
#define SPACIALFREEZE_TRANSFORMATION_H


class Transformation {
public:
    glm::vec3 position;
    float size;

    glm::mat4 getMatrix();
};


#endif //SPACIALFREEZE_TRANSFORMATION_H
