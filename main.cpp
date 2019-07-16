#include "classes/Shader.h"
#include "classes/CubeModel.h"
#include "classes/SquareModel.h"
#include "classes/Lightning.h"
#include "src/core/include.cpp"
#include "src/core/data.cpp"
#include "src/core/preInit.cpp"
#include "src/core/init.cpp"
#include "src/core/frame.cpp"
#include "src/core/util.cpp"
#include "src/logger.cpp"
#include "src/framebuffer.cpp"
#include "src/stencil.cpp"

namespace core {
    void drawLandscape(Shader &modelShader, float size) {
        CubeModel cube;
        makeModel(modelShader, Data.camera.operator*());
        cube.bind();
        modelShader.use();
        glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(size));
        modelShader.setMat4("scale", scale);

        glm::vec3 pos = glm::vec3(0.0f, 0.0f, -2.0f);
        cube.draw(pos, modelShader);
        pos = glm::vec3(3.0f, -1.0f, -4.0f);
        cube.draw(pos, modelShader);
        pos = glm::vec3(7.0f, 2.0f, 1.0f);
        cube.draw(pos, modelShader);
        pos = glm::vec3(-1.0f, 1.0f, 4.0f);
        cube.draw(pos, modelShader);
        pos = glm::vec3(0.0f, -5.0f, 0.0f);
        cube.draw(pos, modelShader);
    }

    void drawTexture(Shader &postProcessing, unsigned int tex) {
        SquareModel square;
        square.bind();
        postProcessing.use();
        postProcessing.setInt("texture2D", 0);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, tex);
        square.draw(postProcessing);
    }

    void renderOutline(Shader &modelShader) {
        stencil::enable();
        modelShader.use();

        stencil::startTrace(1);
        modelShader.setVec4("colour", 0.0f, 0.0f, 0.0f, 0.0f);
        drawLandscape(modelShader, 1.0f);

        stencil::startDrawInvert(1);
        modelShader.setVec4("colour", 1.0f, 0.5f, 0.0f, 1.0f);
        drawLandscape(modelShader, 1.02f);

        stencil::disable();
    }

    void frame(unsigned int framebuffer, unsigned int fbTex, Lightning &lightningX, Lightning &lightningY) {
        float currentFrame = glfwGetTime();
        float deltaTime = currentFrame - Data.lastFrame;
        Data.lastFrame = currentFrame;
        processInput(deltaTime);
        prerender(0.1, 0.1, 0.1);

        framebuffer::startWrite(Data.SCR_WIDTH, Data.SCR_HEIGHT, framebuffer);
        Shader singleColourShader("basic3d.vert", "solidColour.frag", Path.shaders);
        renderOutline(singleColourShader);
        framebuffer::endWrite();

        lightningX.update(0.004);
        lightningY.update(0.004);
        Shader postProcessing("basic2d.vert", "lightning.frag", Path.shaders);
        postProcessing.use();
        postProcessing.setInt("lightningX", 1);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_1D, lightningX.getTexture());
        postProcessing.setInt("lightningY", 2);
        glActiveTexture(GL_TEXTURE2);
        glBindTexture(GL_TEXTURE_1D, lightningY.getTexture());
        drawTexture(postProcessing, fbTex);

        glCheckError();
        glfwPollEvents();
        glfwSwapBuffers(Data.window);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

    void run() {
        logger::message("Starting Program");
        preInit(1920, 1080, "Spacial Freeze");
        logger::message("Pre-Initialisation Complete");
        init(true);
        logger::message("Initialisation Complete");

        unsigned int framebuffer;
        unsigned int fbTex;
        framebuffer::setup(Data.SCR_WIDTH, Data.SCR_HEIGHT, true, &framebuffer, &fbTex);

        Lightning lightningX;
        Lightning lightningY;
        logger::message("Starting Draw Phase");
        while (!shouldClose()) frame(framebuffer, fbTex, lightningX, lightningY);

        close();
    }
}

int main() {
    try {
        core::run();
    } catch (core::initialisationException &e) {
        logger::fatal(e.what());
    } catch (shaderException &e) {
        logger::fatal(e.what());
    } catch (framebuffer::framebufferException &e) {
        logger::fatal(e.what());
    }
}

