#ifndef SPACIALFREEZE_LIGHTNING_H
#define SPACIALFREEZE_LIGHTNING_H

#include <random>

class Lightning {
public:
    void update(float std);
    int getTexture() const;

private:
    std::random_device rd;
    static unsigned const int dataLength = 1024;
    float data[dataLength];

    float update(float initial, float std);
};


#endif //SPACIALFREEZE_LIGHTNING_H
