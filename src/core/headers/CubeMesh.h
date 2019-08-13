#ifndef SPACIALFREEZE_CUBEMODEL_H
#define SPACIALFREEZE_SQAUREMODEL_H

static constexpr float cubeVertices[] = {
        // Position          // Texture
        -1.0f, -1.0f, 0.0f, 0.0f,
        1.0f, -1.0f, 1.0f, 0.0f,
        -1.0f,  1.0f, 0.0f, 1.0f,
        1.0f,  1.0f, 1.0f, 1.0f,
        -1.0f,  1.0f, 0.0f, 1.0f,
        1.0f, -1.0f, 1.0f, 0.0f
};

class CubeMesh {
public:
    CubeMesh();
    ~CubeMesh();
    void draw(Shader &shader);

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


#endif //SPACIALFREEZE_CUBEMODEL_H
