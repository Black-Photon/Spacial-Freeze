#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"

Shader::Shader(std::string vertexPath, std::string fragmentPath, std::string location)
{
    vertexName = vertexPath;
    fragmentName = fragmentPath;

    std::string vertexLocation;// = new std::string;
    std::string fragmentLocation;// = new std::string;
    readVertexFile((location + vertexPath).c_str(), &vertexLocation);
    readFragmentFile((location + fragmentPath).c_str(), &fragmentLocation);
    const char* vShaderCode = (vertexLocation).c_str();
    const char* fShaderCode = (fragmentLocation).c_str();

    unsigned int vertex, fragment;
    vertex = createVertexShader(vShaderCode);
    fragment = createFragmentShader(fShaderCode);

    linkShaders(&ID, vertex, fragment);
    // Delete the shaders as they're linked into our program now and no longer necessery
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::use() const
{
    glUseProgram(ID);
}

void Shader::setBool(const std::string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value) const
{
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setVec3(const std::string &name, float v1, float v2, float v3) const
{
    setVec3(name, glm::vec3(v1, v2, v3));
}

void Shader::setVec3(const std::string &name, glm::vec3 vec) const
{
    glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, glm::value_ptr(vec));
}

void Shader::readVertexFile(const char* vertexPath, std::string * vertexCode) const
{
    std::ifstream vShaderFile;
    // Ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try{
        // Open files
        vShaderFile.open(vertexPath);
        std::stringstream vShaderStream;
        // Read file's buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        // Close file handlers
        vShaderFile.close();
        // Convert stream into string
        *vertexCode = vShaderStream.str();
    } catch(std::ifstream::failure &e) {
        throw shaderException("Couldn't read Vertex Shader: " + std::string(vertexPath));
    }
}

void Shader::readFragmentFile(const char* fragmentPath, std::string * fragmentCode) const
{
    std::ifstream fShaderFile;
    // Ensure ifstream objects can throw exceptions:
    fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try {
        // Open files
        fShaderFile.open(fragmentPath);
        std::stringstream fShaderStream;
        // Read file's buffer contents into streams
        fShaderStream << fShaderFile.rdbuf();
        // Close file handlers
        fShaderFile.close();
        // Convert stream into string
        *fragmentCode = fShaderStream.str();
    } catch(std::ifstream::failure &e) {
        throw shaderException("Couldn't read Fragment Shader: " + std::string(fragmentPath));
    }
}

void Shader::linkShaders(unsigned int * shaderProgram, unsigned int vertexShader, unsigned int fragmentShader)
{
    int success;
    char infoLog[512];

    // SHADER LINKING
    // Creates a basic program object
    *shaderProgram = glCreateProgram();
    // Attaches a compiled shader3d object to a program
    glAttachShader(*shaderProgram, vertexShader);
    glAttachShader(*shaderProgram, fragmentShader);
    // Links all the shaders in the program together
    glLinkProgram(*shaderProgram);

    glGetProgramiv(*shaderProgram, GL_LINK_STATUS, &success);

    if(!success) {
        glGetProgramInfoLog(shaderProgram[1], 512, nullptr, infoLog);
        throw shaderException("Couldn't link Shader Inputs");
    }
}

unsigned int Shader::createVertexShader(const char * vertexShaderSource) const
{
    // VERTEX SHADERS
    // Makes an empty vertex shader3d
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // Replaces the current shader3d source code with that given by the .vert files
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    // Compiles the shader3d object using source code just given
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    // Gets specific info about an element of a shader3d
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if(!success) {
        // Returns the error log
        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        std::cerr << infoLog << std::endl;
        throw shaderException("Couldn't compile Vertex Shader: \"" + vertexName + "\"");
    }

    return vertexShader;
}

unsigned int Shader::createFragmentShader(const char * fragmentShaderSource) const
{
    // FRAGMENT SHADERS
    int success;
    char infoLog[512];

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if(!success) {
        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
        std::cerr << infoLog << std::endl;
        throw shaderException("Couldn't compile Fragment Shader: \"" + fragmentName + "\"");
    }

    return fragmentShader;
}