#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 FragPos;
in vec3 Normal;

uniform sampler2D texture_diffuse1;

void main() {
    float ambient = 0.2;

    float diffuse = dot(vec3(1.0, 1.0, 1.0), Normal);
    if(diffuse < 0) diffuse = 0;
    if(diffuse > 0.5) diffuse = 0.5;

    float specularStrength = 0.3;
    vec3 viewDir = normalize(vec3(-1.0, -1.0, -1.0));
    vec3 reflectDir = reflect(vec3(1.0, 1.0, 1.0), Normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 4);
    float specular = specularStrength * spec;

    FragColor = texture(texture_diffuse1, TexCoords) * vec4(vec3(diffuse + ambient + specular), 1.0);
}