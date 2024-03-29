#include "headers/Model.h"

Model::Model(std::string path)  {
    std::string fullPath = core::Path.models + path;
    loadModel(fullPath);
}

void Model::draw(Shader shader) {
    shader.use();
    for(auto &mesh : meshes)
        mesh->draw(shader);
}

void Model::loadModel(std::string &path) {
    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        throw modelLoadingException(importer.GetErrorString());
    }
    directory = path.substr(0, path.find_last_of('/'));

    processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode *node, const aiScene *scene) {
    // Process this node
    for(unsigned int i = 0; i < node->mNumMeshes; i++) {
        aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
        meshes.push_back(processMesh(mesh, scene));
    }

    // Process sub-nodes
    for(unsigned int i = 0; i < node->mNumChildren; i++) {
        processNode(node->mChildren[i], scene);
    }
}

std::unique_ptr<Mesh> Model::processMesh(aiMesh *mesh, const aiScene *scene) {
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;

    for(unsigned int i = 0; i < mesh->mNumVertices; i++) {
        Vertex vertex;

        //Positions
        glm::vec3 vector;
        vector = convertAVec3(mesh->mVertices[i]);
        vertex.Position = vector;

        vector = convertAVec3(mesh->mNormals[i]);
        vertex.Normal = vector;

        if(mesh->mTextureCoords[0]) {
            glm::vec2 vec;
            vec = convertAVec2(mesh->mTextureCoords[0][i]);
            vertex.TexCoords = vec;
        } else vertex.TexCoords = glm::vec2(0.0f, 0.0f);

        vertices.push_back(vertex);
    }

    for(unsigned int i = 0; i < mesh->mNumFaces; i++) {
        aiFace face = mesh->mFaces[i];
        for(unsigned int j = 0; j < face.mNumIndices; j++)
            indices.push_back(face.mIndices[j]);
    }

    if(mesh->mMaterialIndex >= 0) {
        aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
        std::vector<Texture> diffuseMaps = loadMaterialTextures(material,
                                                           aiTextureType_DIFFUSE, "texture_diffuse");
        textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
        std::vector<Texture> specularMaps = loadMaterialTextures(material,
                                                            aiTextureType_SPECULAR, "texture_specular");
        textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
        std::vector<Texture> normalMaps = loadMaterialTextures(material,
                                                            aiTextureType_HEIGHT, "texture_normal");
        textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
    }

    return std::make_unique<Mesh>(vertices, indices, textures);
}

std::vector<Texture> Model::loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName) {
    std::vector<Texture> textures;
    for(unsigned int i = 0; i < mat->GetTextureCount(type); i++) {
        aiString str;
        mat->GetTexture(type, i, &str);
        bool skip = false;
        for(auto & tex : texturesLoaded) {
            if(std::strcmp(tex.path.data(), str.C_Str()) == 0) {
                textures.push_back(tex);
                skip = true;
                break;
            }
        }
        if(!skip) {
            Texture texture = texture::generateTexture(directory + "/" + str.C_Str(), true);
            texture.type = typeName;
            texture.path = str.C_Str();
            textures.push_back(texture);
        }
    }
    return textures;
}

glm::vec2 Model::convertAVec2(aiVector3t<float> vec) {
    return glm::vec2(vec.x, vec.y);
}

glm::vec3 Model::convertAVec3(aiVector3t<float> vec) {
    return glm::vec3(vec.x, vec.y, vec.z);
}