#ifndef SPACIALFREEZE_RENDERER_H
#define SPACIALFREEZE_RENDERER_H


class Renderer {
private:
    Scene scene;
    Framebuffer framebuffer;
    Shader oldShader;
    Shader ppShader;
    Shader lightningShader;
    Shader ppLightningShader;
    Lightning lightningX;
    Lightning lightningY;
    void drawScene(Shader &newShader, float size);
    void drawTexture(Shader &postProcessing, unsigned int tex);
    void renderOutline(float diff);
    void renderSceneNormal();
    void drawSceneNormal();
    void renderSceneLightning();
    void drawSceneLightning(Lightning &lightningX, Lightning &lightningY);

public:
    Renderer(Scene &scene, Shader &oldShader);
    /**
     * Draws the scene normally
     */
    void draw();
    /**
     * Draws the scene using lightning borders
     */
    void drawLightning();
    /**
     * Updates the framebuffer size in case of window resizing
     */
    void updateFramebuffer();
};


#endif //SPACIALFREEZE_RENDERER_H
