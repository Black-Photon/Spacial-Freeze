#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Model.h"

Model::Model(float vertices[], int length)
{
    // Generates a Vertex Array Object
    glGenVertexArrays(1, &VAO);
    // Generates the Vertex Buffer Objects
    glGenBuffers(1, &VBO);

    // Bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    // Binds the VAO so glVertexAttribPointer and glEnableVertexAttribArray work on this VAO
    glBindVertexArray(VAO);

    // Binds the buffer to the buffer type so glBufferData works on this
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // Allocates memory for and stores the vertices data
    glBufferData(GL_ARRAY_BUFFER, length * sizeof(*vertices), vertices, GL_STATIC_DRAW);
}

Model::~Model()
{
    // Deletes VAO and VBO data from memory
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Model::bind() const
{
    glBindVertexArray(VAO);
}

void Model::setAttribute(int index, int size, int stride, int start)
{
    // Index, Size, Type, Normalized, Stride, Pointer
    glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void *) (start * sizeof(float)));
    glEnableVertexAttribArray(index);
}

void Model::addAttribute(int size)
{
    attributeSizes.push_back(size);
}

void Model::setAttributes()
{
    std::vector<int> startPos;
    int sum = 0;
    for(int i : attributeSizes) {
        startPos.push_back(sum);
        sum += i;
    }
    for(int i = 0; i < attributeSizes.size(); i++) {
        int v = attributeSizes.at(i);
        setAttribute(i, v, sum, startPos.at(i));
    }
}