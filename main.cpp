#include "classes/Shader.h"
#include "classes/SquareMesh.h"
#include "classes/Lightning.h"
#include "classes/Framebuffer.h"
#include "classes/Model.h"
#include "src/core/include.cpp"
#include "src/core/data.cpp"
#include "src/core/preInit.cpp"
#include "src/core/init.cpp"
#include "src/core/frame.cpp"
#include "src/core/util.cpp"
#include "src/stencil.cpp"
#include "headers/logger.h"
#include "headers/error.h"

#include "classes/Scene.cpp"
#include "classes/Instance.cpp"

namespace core {
    Model *model;
    void drawLandscape(Shader &modelShader, float size) {
        makeModel(modelShader, *Data.camera);
        glm::mat4 modelMat = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
        modelMat = glm::scale(modelMat, glm::vec3(size * 0.1f));
        modelMat = glm::translate(modelMat, glm::vec3(0.0f, 0.0f, 0.0f));
        modelShader.setMat4("model", modelMat);
        model->draw(modelShader);
    }

    void drawTexture(Shader &postProcessing, unsigned int tex) {
        SquareMesh square;
        postProcessing.use();
        postProcessing.setInt("texture2D", 0);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, tex);
        square.draw(postProcessing);
    }

    void renderOutline(Shader &modelShader, float diff) {
        stencil::enable();
        modelShader.use();

        stencil::startTrace(1);
        modelShader.setVec4("colour", 0.1f, 0.1f, 0.1f, 0.0f);
        drawLandscape(modelShader, 1.0f);

        stencil::startDrawInvert(1);
        modelShader.setVec4("colour", 1.0f, 0.5f, 0.0f, 1.0f);
        drawLandscape(modelShader, 1.0f + diff);
        drawLandscape(modelShader, 1.0f - diff);

        stencil::disable();
    }

    void renderSceneNormal(Framebuffer &fbMain) {
        fbMain.startWrite();
        prerender(0, 0, 0);
        Shader shader("basic3d.vert", "model.frag", Path.shaders);
        drawLandscape(shader, 1.0f);
        fbMain.endWrite(Data.SCR_WIDTH, Data.SCR_HEIGHT);
    }

    void renderSceneLightning(Framebuffer &fbLightning) {
        fbLightning.startWrite();
        Shader singleColourShader("basic3d.vert", "solidColour.frag", Path.shaders);
        renderOutline(singleColourShader, 0.04f);
        fbLightning.endWrite(Data.SCR_WIDTH, Data.SCR_HEIGHT);
    }

    void drawSceneNormal(Framebuffer &fbMain) {
        Shader postProcessing("basic2d.vert", "texture.frag", Path.shaders);
        postProcessing.use();
        postProcessing.setFloat("zPos", 0.0f);
        drawTexture(postProcessing, fbMain.texture);
    }

    void drawSceneLightning(Framebuffer &fbLightning, Lightning &lightningX, Lightning &lightningY) {
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
        postProcessing.setFloat("zPos", 0.1f);
        drawTexture(postProcessing, fbLightning.texture);
    }

    void frame(Framebuffer &framebuffer, Lightning &lightningX, Lightning &lightningY) {
        float currentFrame = glfwGetTime();
        float deltaTime = currentFrame - Data.lastFrame;
        Data.lastFrame = currentFrame;
        processInput(deltaTime);

        if(Data.closed && Data.distanceOpen > 0) Data.distanceOpen -= deltaTime * 5;
        else if(!Data.closed && Data.distanceOpen < 1) Data.distanceOpen += deltaTime * 5;
        if(Data.distanceOpen > 1) Data.distanceOpen = 1;
        else if(Data.distanceOpen < 0) Data.distanceOpen = 0;

        framebuffer.updateSize(Data.SCR_WIDTH, Data.SCR_HEIGHT); // Done in case of window size change
        prerender(0.1, 0.1, 0.1);

        renderSceneLightning(framebuffer);
        drawSceneLightning(framebuffer, lightningX, lightningY);
        glScissor(Data.SCR_WIDTH/4, Data.SCR_HEIGHT * (1 - Data.distanceOpen) / 2, Data.SCR_WIDTH/2, Data.SCR_HEIGHT * Data.distanceOpen);
        renderSceneNormal(framebuffer);
        drawSceneNormal(framebuffer);
        glScissor(0, 0, Data.SCR_WIDTH, Data.SCR_HEIGHT);


        glCheckError();
        glfwPollEvents();
        glfwSwapBuffers(Data.window);
    }

    void run() {
        logger::message("Starting Program");
        preInit(1920, 1080, "Spacial Freeze");
        logger::message("Pre-Initialisation Complete");
        init(true);
        logger::message("Initialisation Complete");

        Framebuffer framebuffer(Data.SCR_WIDTH, Data.SCR_HEIGHT, true);

        Lightning lightningX;
        Lightning lightningY;
//        Model model(Path.models + "nanosuit/nanosuit.obj");
        Model model(Path.models + "Table.obj");
        core::model = &model;
        logger::message("Starting draw Phase");
        while (!shouldClose()) frame(framebuffer, lightningX, lightningY);

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
    } catch (framebufferException &e) {
        logger::fatal(e.what());
    }
}

