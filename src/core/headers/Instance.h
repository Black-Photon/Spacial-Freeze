#ifndef SPACIALFREEZE_INSTANCE_H
#define SPACIALFREEZE_INSTANCE_H

#include "Transformation.h"

class Instance {
public:
    long ID;
    Shader shader;
    Transformation transformation;
    Instance(Model &model, Shader &shader);
    void draw();
    void draw(Shader &shader);
    void draw(Shader &shader, Transformation altTrans);

private:
    static long lastID;
    Model *model;
};


#endif //SPACIALFREEZE_INSTANCE_H
