#ifndef SPACIALFREEZE_INSTANCE_H
#define SPACIALFREEZE_INSTANCE_H

#include "Transformation.h"

class Instance {
public:
    long ID;
    std::string name;
    Shader shader;
    Transformation transformation;
    bool inside = false;
    Instance(Model &model, Shader &shader, std::string name);
    void draw();
    void draw(Shader &shader);
    void draw(Shader &shader, Transformation altTrans);

private:
    static long lastID;
    Model *model;
};


#endif //SPACIALFREEZE_INSTANCE_H
