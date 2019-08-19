// Data Includes
#include "include.cpp"

namespace core {
    void frame(Renderer &renderer) {
        float currentFrame = glfwGetTime();
        float deltaTime = currentFrame - Data.lastFrame;
        Data.lastFrame = currentFrame;
        processInput(deltaTime);

        if(Data.closed && Data.distanceOpen > 0) Data.distanceOpen -= deltaTime * 5;
        else if(!Data.closed && Data.distanceOpen < 1) Data.distanceOpen += deltaTime * 5;
        if(Data.distanceOpen > 1) Data.distanceOpen = 1;
        else if(Data.distanceOpen < 0) Data.distanceOpen = 0;

        renderer.updateFramebuffer();
        prerender(0.1, 0.1, 0.1);

        Light &light = renderer.scene.getLight("light");
        light.position = glm::vec3(0.5f, 0.0f, 0.0f);
        light.position = glm::vec3(sin(currentFrame)/16, 0.5f, 0.0f);
//        renderer.scene.getInstance("light").transformation.position = light.position;

        renderer.drawLightning();
        glScissor(Data.SCR_WIDTH/4, Data.SCR_HEIGHT * (1 - Data.distanceOpen) / 2, Data.SCR_WIDTH/2, Data.SCR_HEIGHT * Data.distanceOpen);
        renderer.draw();
        glScissor(0, 0, Data.SCR_WIDTH, Data.SCR_HEIGHT);



        glCheckError();
        glfwPollEvents();
        glfwSwapBuffers(Data.window);
    }

    void run() {
        logger::message("Starting Program");
        preInit(1920, 1080, "Spacial Freeze");
        logger::message("Pre-Initialisation Complete");
        init(false);
        logger::message("Initialisation Complete");

        Model table("Table.obj");
        Model bookshelf("Bookshelf.obj");
        Shader modelShader("basic3d.vert", "model.frag");

        Instance tableInstance(table, modelShader, "table");
        Instance bookshelfInstance(bookshelf, modelShader, "bookshelf");
        tableInstance.transformation.position = glm::vec3(0, -0.25f, 0);
        bookshelfInstance.transformation.position = glm::vec3(-0.5f, 0.0f, -0.5f);
        Scene scene;
        scene.addInstance(tableInstance);
        scene.addInstance(bookshelfInstance);

        Light mainLight;
        mainLight.position = glm::vec3(1.0f, 1.0f, 1.0f);

        scene.addLight("light", mainLight);

        Shader colourShader("basic3d.vert", "solidColour.frag");
        colourShader.use();
        colourShader.setVec4("colour", 1.0f, 1.0f, 0.7f, 1.0f);
        CubeModel cube;
        Instance room(cube, modelShader, "room");
        Instance light(cube, colourShader, "light");
        room.transformation.size = 40.0f;
        room.transformation.position = glm::vec3(0.0f, 3.7f, 0.0f);
        room.inside = true;
        light.transformation.size = 0.1f;
        scene.addInstance(room);
        scene.addInstance(light);

        Renderer renderer(scene, modelShader);

        logger::message("Starting draw Phase");
        while (!shouldClose()) frame(renderer);
    }
}

int main() {
    try {
        core::run();
    } catch (core::initialisationException &e) {
        logger::fatal(e.what(), "Initialisation");
    } catch (shaderException &e) {
        logger::fatal(e.what(), "Shaders");
    } catch (framebufferException &e) {
        logger::fatal(e.what(), "Framebuffer");
    } catch (modelLoadingException &e) {
        logger::fatal(e.what(), "Model Loading");
    }

    core::close();
}

