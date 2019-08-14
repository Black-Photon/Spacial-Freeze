#ifndef SPACIALFREEZE_SCENE_H
#define SPACIALFREEZE_SCENE_H

#include "Instance.h"

class Scene {
private:
    std::vector<Shader> shaders;
    std::map<int, std::vector<Instance>> instances;
    std::map<std::string, Light> lights;

public:
    void addInstance(Instance &instance);
    bool removeInstance(Instance &instance);
    void replaceShader(Shader &newShader, Shader &oldShader);
    void drawScene(float size);
    void drawScene();
    void addLight(std::string name, Light &light);
    bool removeLight(std::string name);
    Light& getLight(std::string name);
};


#endif //SPACIALFREEZE_SCENE_H
