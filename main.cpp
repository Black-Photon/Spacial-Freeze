#include "src/include.cpp"

#include "classes/Shader.h"
#include "src/data.cpp"
#include "src/preInit.cpp"
#include "src/init.cpp"
#include "src/frame.cpp"
#include "src/logger.cpp"
#include "src/util.cpp"

namespace core {
    void run() {
        logger::message("Starting Program");
        preInit(1920, 1080, "Spacial Freeze");
        logger::message("Pre-Initialisation Complete");
        init(true);
        logger::message("Initialisation Complete");

        logger::message("Starting Draw Phase");
        while (!shouldClose()) {
            float currentFrame = glfwGetTime();
            float deltaTime = currentFrame - Data.lastFrame;
            Data.lastFrame = currentFrame;
            processInput(deltaTime);
            prerender(0, 1, 0);

            glCheckError();
            glfwPollEvents();
            glfwSwapBuffers(Data.window);
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }
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

