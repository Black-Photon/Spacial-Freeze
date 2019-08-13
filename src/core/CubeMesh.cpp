CubeMesh::CubeMesh()
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
    // Allocates memory for and stores the cubeVertices data
    glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(*cubeVertices), cubeVertices, GL_STATIC_DRAW);

    addAttribute(2); // Position
    addAttribute(2); // Texture
    setAttributes();

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

CubeMesh::~CubeMesh()
{
    // Deletes VAO and VBO data from memory
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void CubeMesh::setAttribute(int index, int size, int stride, int start)
{
    // Index, Size, Type, Normalized, Stride, Pointer
    glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void *) (start * sizeof(float)));
    glEnableVertexAttribArray(index);
}

void CubeMesh::addAttribute(int size)
{
    attributeSizes.push_back(size);
}

void CubeMesh::setAttributes()
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

void CubeMesh::draw(Shader &shader)
{
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}