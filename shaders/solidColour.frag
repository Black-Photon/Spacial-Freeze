#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 FragPos;
in vec3 Normal;

uniform vec3 colour;

void main()
{
    FragColor = vec4(colour, 1.0f);
}