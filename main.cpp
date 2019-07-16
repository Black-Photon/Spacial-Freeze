#include "src/include.cpp"

#include "classes/Shader.h"
#include "src/data.cpp"
#include "src/preInit.cpp"
#include "src/init.cpp"
#include "src/frame.cpp"
#include "src/logger.cpp"
#include "src/util.cpp"
#include "classes/CubeModel.h"

namespace core {
    void drawLandscape(Shader &modelShader) {
        CubeModel cube;
        makeModel(modelShader, Data.camera.operator*());
        cube.bind();
        modelShader.use();
        glm::vec3 pos = glm::vec3(0.0f, 0.0f, -2.0f);
        cube.draw(pos, modelShader);
    }

    void frame() {
        float currentFrame = glfwGetTime();
        float deltaTime = currentFrame - Data.lastFrame;
        Data.lastFrame = currentFrame;
        processInput(deltaTime);
        prerender(0, 1, 0);

        Shader singleColourShader("basic3d.vert", "solidColour.frag", Path.shaders);
        singleColourShader.use();
        singleColourShader.setVec3("colour", glm::vec3(1.0f, 0.0f, 0.0f));
        glCheckError();
        drawLandscape(singleColourShader);

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

        logger::message("Starting Draw Phase");
        while (!shouldClose()) frame();
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
    }
}

