#include "data.cpp"
#include "../logger.cpp"
#include <memory>

/**
 * Methods used in Initialisation
 */
namespace core {

    /**
     * Performs all operations that are required for drawing
     */
    void init(bool capture);
    /**
     * Generates a texture, registering it to be used
     * @param texture Location of to put texture reference in
     * @param path Path to texture relative to assets folder
     * @param isPNG Whether the image is a png (has an alpha channel)
     */
    void generateTexture(unsigned int *texture, std::string path, bool isPNG);

    void init(bool capture) {
        // Enables basic features
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_STENCIL_TEST);
        glEnable(GL_CULL_FACE);
        glEnable(GL_SCISSOR_TEST);

        // Flips Textures to correct orientation
        stbi_set_flip_vertically_on_load(true);

        // Creates the actual main viewport, and makes it adjust for window size changes
        glViewport(0, 0, Data.SCR_WIDTH, Data.SCR_HEIGHT);

        // Initialises time
        Data.lastFrame = glfwGetTime();

        // Creates Camera viewed from
        auto *camera = new Camera(1920.0f/1080.0f);
        Data.camera = std::unique_ptr<Camera>(camera);
        Data.camera->rotate(YAW, -90.0f);

        if(capture) {
            glfwSetInputMode(Data.window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        }
    }

    void generateTexture(unsigned int *texture, const std::string &path, bool alpha) {
        glGenTextures(1, texture);
        glBindTexture(GL_TEXTURE_2D, *texture);

        // Sets the parameters for the texture to use if incorrectly sized
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // Set's the Mipmap filter
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        int width, height, nrChannels;
        unsigned char *data = stbi_load((Path.assets + path).c_str(), &width, &height, &nrChannels, 0);

        // Whether it uses alpha depends on whether it is a .png or not
        GLenum useAlpha;
        if (alpha) {
            useAlpha = GL_RGBA;
        } else {
            useAlpha = GL_RGB;
        }

        if (data) {
            // Target Dimension, Mipmap level, Texture Format, width, height, 0, Format, Data Type, Image
            glTexImage2D(GL_TEXTURE_2D, 0, useAlpha, width, height, 0, useAlpha, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        } else {
            logger::error("Failed to load texture");
        }

        stbi_image_free(data);
    }
}