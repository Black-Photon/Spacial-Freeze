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

struct Light {
    vec3 position;
    vec3 colour;
    float intensity;
};

uniform Light light;

uniform Camera camera;

uniform vec4 colour;

void main()
{
    FragColor = colour;
}