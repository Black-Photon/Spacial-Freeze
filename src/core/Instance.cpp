long Instance::lastID = 0;

Instance::Instance(Model &model, Shader &shader, std::string name) : shader(shader), model(&model), name(name) {
    ID = lastID++;
}
void Instance::draw() {
    shader.use();
    core::makeModel(shader, *core::Data.camera);
    draw(shader);
}

void Instance::draw(Shader &altShader) {
    draw(altShader, transformation);
}

void Instance::draw(Shader &altShader, Transformation altTrans) {
    altShader.setMat4("model", altTrans.getMatrix());
    altShader.setCamera("camera", *core::Data.camera);
    altShader.setBool("inside", inside);
    model->draw(altShader);
}