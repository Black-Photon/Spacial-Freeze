#include "Scene.h"

void Scene::addInstance(Instance &instance) {
    Shader shader = instance.shader;
    int pos;
    bool found = false;
    for(int i = 0; i < shaders.size(); i++) {
        if(shaders.at(i).ID == shader.ID) {
            found = true;
            pos = i;
            break;
        }
    }

    if(!found) {
        pos = shaders.size();
        shaders.push_back(shader);
    }

    found = false;
    for(auto& pair : instances) {
        if(pair.first == pos) {
            pair.second.push_back(instance);
            found = true;
        }
    }

    if(!found) {
        std::vector<Instance> newInstances;
        newInstances.push_back(instance);
        instances.insert(std::pair(pos, newInstances));
    }
}

bool Scene::removeInstance(Instance &instance) {
    Shader shader = instance.shader;
    int pos;
    bool found = false;
    for(int i = 0; i < shaders.size(); i++) {
        if(shaders.at(i).ID == shader.ID) {
            found = true;
            pos = i;
            break;
        }
    }

    if(!found) {
        return false;
    }

    for(auto& pair : instances) {
        if(pair.first == pos) {
            for(int i = 0; i < pair.second.size(); i++) {
                if(pair.second.at(i).ID == instance.ID) {
                    pair.second.erase(pair.second.begin() + i);
                    
                    return true;
                }
            }
        }
    }

    return false;
}

void Scene::replaceShader(Shader &newShader, Shader &oldShader) {
    for(auto & shader : shaders) {
        if(shader.ID == oldShader.ID) {
            shader = newShader;
            break;
        }
    }
}

void Scene::drawScene(float size) {
    for(const auto pair : instances) {
        auto shader = shaders.at(pair.first);
        auto instanceList = pair.second;
        shader.use();
        core::makeModel(shader, *core::Data.camera);
        for(auto instance : instanceList) {
            instance.setSize(size);
            instance.draw(shader);
        }
    }
}

void Scene::drawScene() {
    drawScene(1.0f);
}