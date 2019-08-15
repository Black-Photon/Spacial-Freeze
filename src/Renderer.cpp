#include "Renderer.h"

Renderer::Renderer(Scene &scene, Shader &oldShader):
    scene(scene),
    framebuffer(core::Data.SCR_WIDTH, core::Data.SCR_HEIGHT, false, true),
    shadowBuffer(2048, 2048, true, false),
    oldShader(oldShader),
    ppShader("basic2d.vert", "texture.frag"),
    lightningShader("basic3d.vert", "solidColour.frag"),
    ppLightningShader("basic2d.vert", "lightning.frag"),
    shadowShader("shadow.vert", "shadow.frag", "shadow.geom"),
    shadowCam(core::Data.SCR_WIDTH/core::Data.SCR_HEIGHT),
    lightningX(), lightningY() {
    shadowCam.fov = 90.0f;
}

void Renderer::drawScene(Shader &newShader, float size) {
    scene.replaceShader(newShader, oldShader);
    scene.drawScene(size);
    scene.replaceShader(oldShader, newShader);
}

void Renderer::drawTexture(Shader &postProcessing, unsigned int tex) {
    SquareMesh square;
    postProcessing.use();
    postProcessing.setInt("texture2D", 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tex);
    square.draw(postProcessing);
}

void Renderer::renderOutline(float diff) {
    stencil::enable();
    lightningShader.use();

    stencil::startTrace(1);
    lightningShader.setVec4("colour", 0.1f, 0.1f, 0.1f, 0.0f);
    drawScene(lightningShader, 1.0f);

    stencil::startDrawInvert(1);
    lightningShader.setVec4("colour", 1.0f, 0.5f, 0.0f, 1.0f);
    drawScene(lightningShader, 1.0f + diff);
    drawScene(lightningShader, 1.0f - diff);

    stencil::disable();
}

void Renderer::renderSceneNormal() {
    framebuffer.startWrite();
    core::prerender(0, 0, 0);
    scene.drawScene();
    framebuffer.endWrite();
}

void Renderer::drawSceneNormal() {
    ppShader.use();
    ppShader.setFloat("zPos", 0.0f);
    drawTexture(ppShader, framebuffer.texture);
}

void Renderer::renderSceneLightning() {
    framebuffer.startWrite();
    renderOutline(0.04f);
    framebuffer.endWrite();
}

void Renderer::drawSceneLightning(Lightning &lightningX, Lightning &lightningY) {
    lightningX.update(0.004);
    lightningY.update(0.004);
    ppLightningShader.use();
    ppLightningShader.setInt("lightningX", 1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_1D, lightningX.getTexture());
    ppLightningShader.setInt("lightningY", 2);
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_1D, lightningY.getTexture());
    ppLightningShader.setFloat("zPos", 0.1f);
    drawTexture(ppLightningShader, framebuffer.texture);
}

void Renderer::draw() {
    renderSceneNormal();
    drawSceneNormal();
}

void Renderer::drawLightning() {
    renderSceneLightning();
    drawSceneLightning(lightningX, lightningY);
}

void Renderer::updateFramebuffer() {
    framebuffer.updateSize(core::Data.SCR_WIDTH, core::Data.SCR_HEIGHT);
}

void Renderer::generateShadows() {
    shadowBuffer.startWrite();
    shadowShader.use();
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, shadowBuffer.texture);
    shadowBuffer.endWrite();
}