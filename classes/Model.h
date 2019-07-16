#ifndef OPENGLPROJECT_MODEL_H
#define OPENGLPROJECT_MODEL_H

#include <glm/glm.hpp>
#include "Shader.h"
#include <vector>

/**
 * Represents a specific shape type
 *
 * Holds reused information to make copies of the same shape with different positions
 */
class Model {
public:
    /**
     * Builds a model with the given Vertices
     * @param vertices Vertices of the points
     * @param length Length of the vertex array
     */
    Model(float vertices[], int length);
    /**
     * Deletes saved resources
     */
    ~Model();

    /**
     * Draws the model to the screen at the given position
     * @param position Position to draw to the screen
     * @param shader Shader to draw using
     */
    virtual void draw(glm::vec3 position, Shader &shader) = 0;

    /**
     * Binds the VAO
     */
    void bind() const;

protected:
    unsigned int VAO;
    unsigned int VBO;
    std::vector<int> attributeSizes;

    /**
     * Sets an individual attribute manually
     * @param index Which attribute index it uses
     * @param size Size of attribute
     * @param stride Next element distance
     * @param start Start index
     */
    static void setAttribute(int index, int size, int stride, int start);

    /**
     * Adds an attribute to the queue
     * @param size Size of attribute
     */
    void addAttribute(int size);
    /**
     * Sets all attributes using the queue
     */
    void setAttributes();
};


#endif //OPENGLPROJECT_MODEL_H
