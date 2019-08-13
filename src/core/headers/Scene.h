#ifndef SPACIALFREEZE_SCENE_H
#define SPACIALFREEZE_SCENE_H

#include "Instance.h"

class Scene {
private:
    std::vector<Shader> shaders;
    std::map<int, std::vector<Instance>> instances;

public:
    void addInstance(Instance &instance);
    bool removeInstance(Instance &instance);
    void replaceShader(Shader &newShader, Shader &oldShader);
    void drawScene(float size);
    void drawScene();
};


#endif //SPACIALFREEZE_SCENE_H