#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 FragPos;
in vec3 Normal;

struct Material {
    sampler2D texture_diffuse1;
    sampler2D texture_specular1;
};

uniform Material material;

struct Camera {
    vec3 viewDir;
};

uniform Camera camera;

void main() {
    float ambient = 0.4;

    float diffuse = dot(vec3(1.0, 1.0, 1.0), Normal);
    if(diffuse < 0) diffuse = 0;
    if(diffuse > 0.3) diffuse = 0.3;

    float specularStrength = 8.0;
    vec3 viewDir = normalize(camera.viewDir);
    vec3 reflectDir = normalize(reflect(vec3(1.0, 1.0, 1.0), Normal));
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    float specular = specularStrength * spec;

    FragColor = texture(material.texture_diffuse1, TexCoords) * (texture(material.texture_specular1, TexCoords) * specular + vec4(vec3(diffuse + ambient), 1.0));
}