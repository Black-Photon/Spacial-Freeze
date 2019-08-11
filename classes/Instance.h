#ifndef SPACIALFREEZE_INSTANCE_H
#define SPACIALFREEZE_INSTANCE_H


#include "Model.h"

class Instance {
public:
    long ID;
    Shader shader;
    Instance(Model &model, Shader shader);
    void setPosition(glm::vec3 pos);
    void draw();
    void draw(Shader shader);

private:
    static long lastID;
    Model *model;
    glm::vec3 position;
};


#endif //SPACIALFREEZE_INSTANCE_H
