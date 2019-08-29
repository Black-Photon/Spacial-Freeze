#ifndef SPACIALFREEZE_BOXCOLLIDERCOMPONENT_H
#define SPACIALFREEZE_BOXCOLLIDERCOMPONENT_H


class BoxColliderComponent : public Component {
public:
    BoxColliderComponent() = default;
    void update(float deltaT) override;
};


#endif //SPACIALFREEZE_BOXCOLLIDERCOMPONENT_H
