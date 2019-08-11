#ifndef SPACIALFREEZE_SCENE_H
#define SPACIALFREEZE_SCENE_H

#include <vector>
#include "Shader.h"
#include "Instance.h"
#include <map>

class Scene {
private:
    std::vector<Shader> shaders;
    std::map<int, std::vector<Instance>> instances;

public:
    void addInstance(Instance &instance);
    bool removeInstance(Instance &instance);
    void replaceShader(Shader newShader, Shader oldShader);
    void drawScene(float size);

    void printVectors() {
        for (auto const& c : shaders)
            std::cout << c.ID << ' ';
        std::cout << std::endl;

        for (auto const& c : instances)
            std::cout << c.first << ' ';
        std::cout << std::endl;
    }
};


#endif //SPACIALFREEZE_SCENE_H
