#ifndef OPENGLPROJECT_SHADER_H
#define OPENGLPROJECT_SHADER_H

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>

class Shader
{
public:
    // The program ID
    unsigned int ID;

    // Shader name
    std::string vertexName;
    std::string fragmentName;

    /**
     * Initialises and builds the shader
     * @param vertexPath Path to vertex shader relative to shaders
     * @param fragmentPath Path to fragment shader relative to shaders
     * @param location Location of shaders path (Use Path.shaders)
     */
    Shader(std::string vertexPath, std::string fragmentPath, std::string location);
    /**
     * Activates the shader as the one being used to draw
     */
    void use() const;
    /**
     * Sets a boolean uniform to the given value
     * @param name Variable name
     * @param value Boolean value
     */
    void setBool(const std::string &name, bool value) const;
    /**
     * Sets an integer uniform to the given value
     * @param name Variable name
     * @param value Integer value
     */
    void setInt(const std::string &name, int value) const;
    /**
     * Sets a float uniform to the given value
     * @param name Variable name
     * @param value Float value
     */
    void setFloat(const std::string &name, float value) const;
    /**
     * Sets a vector 3 uniform to the given value
     * @param name Variable name
     * @param v1 First Value
     * @param v2 Second Value
     * @param v3 Third Value
     */
    void setVec3(const std::string &name, float v1, float v2, float v3) const;

    /**
     * Sets a vector 3 uniform to the given value
     * @param name Variable name
     * @param vec Vector Value
     */
    void setVec3(const std::string &name, glm::vec3 vec) const;

    /**
     * Sets a matrix 4 uniform to the given value
     * @param name Variable name
     * @param vec Vector Value
     */
    void setMat4(const std::string &name, glm::mat4 mat) const;

private:
    /**
     * Links the shader programs together into a single program
     * @param shaderProgram Location to store the program ID
     * @param vertexShader ID of Vertex Shader to use
     * @param fragmentShader ID of Fragment Shader to use
     */
    static void linkShaders(unsigned int * shaderProgram, unsigned int vertexShader, unsigned int fragmentShader);
    /**
     * Creates a vertex shader from the source code
     * @param vertexShaderSource Vertex Shader Source Code
     * @return Vertex Shader ID
     */
    unsigned int createVertexShader(const char * vertexShaderSource) const;
    /**
     * Creates a fragment shader from the source code
     * @param fragmentShaderSource Fragment Shader Source Code
     * @return Fragment Shader ID
     */
    unsigned int createFragmentShader(const char * fragmentShaderSource) const;
    /**
     * Reads a vertex file, storing it as a string
     * @param vertexPath Path to vertex code file
     * @param vertexCode Location to store the source code extracted
     */
    void readVertexFile(const char *vertexPath, std::string * vertexCode) const;
    /**
     * Reads a fragment file, storing it as a string
     * @param fragmentPath Path to fragment code file
     * @param fragmentCode Location to store the source code extracted
     */
    void readFragmentFile(const char *fragmentPath, std::string * fragmentCode) const;
};

/**
 * Indicated an error occurred in a shader
 */
struct shaderException : public std::exception {
    std::string s;

    explicit shaderException(const std::string &string) {
        s = string;
    }

    const char *what() const noexcept(true) override {
        return s.c_str();
    }
};

#endif //OPENGLPROJECT_SHADER_H
