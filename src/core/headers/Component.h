#ifndef SPACIALFREEZE_COMPONENT_H
#define SPACIALFREEZE_COMPONENT_H

class Component {
protected:
    Component() = default;
public:
    Transformation *transformation = nullptr;
    virtual void update(float) = 0;
    void setTransformation(Transformation *transformation) {
        this->transformation = transformation;
    };
};


#endif //SPACIALFREEZE_COMPONENT_H
