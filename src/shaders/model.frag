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

struct Light {
    vec3 position;
    vec3 colour;
    float intensity;
};

uniform Light light;

struct Camera {
    vec3 viewDir;
    vec3 position;
};

uniform Camera camera;

vec4 calculateAmbient();
vec4 calculateDiffuse(Light light);
vec4 calculateSpecular(Camera camera, Light light);

vec4 mkVec4(float i) {
    return vec4(vec3(i), 1.0);
}

vec4 resetAlpha(vec4 i) {
    return vec4(i.xyz, 1.0);
}

float distanceBetween(vec3 first, vec3 second);

float ambientLimit = 0.4;
float diffuseLimit = 0.8;
float specularLimit = 8.0;

void main() {
    vec4 ambient = calculateAmbient();
    vec4 diffuse = calculateDiffuse(light);
    vec4 specular = calculateSpecular(camera, light);

    float distance = distanceBetween(camera.position, light.position);
    float attenuation = 1.0 / (1.0 + 0.09 * distance +
    0.032 * (distance * distance));

    FragColor = ambient + attenuation * (diffuse + specular);
}

vec4 calculateAmbient() {
    vec4 ambient = ambientLimit * texture(material.texture_diffuse1, TexCoords);
    ambient = resetAlpha(ambient);

    return ambient;
}

vec4 calculateDiffuse(Light light) {
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diffuse = max(dot(norm, lightDir), 0.0) * diffuseLimit;

    vec4 diffuseVec = diffuse * texture(material.texture_diffuse1, TexCoords);
    diffuseVec = resetAlpha(diffuseVec);

    return diffuseVec;
}

vec4 calculateSpecular(Camera camera, Light light) {
    vec3 lightDir   = normalize(light.position - FragPos);
    vec3 viewDir    = normalize(camera.position - FragPos);
    vec3 halfwayDir = normalize(lightDir + viewDir);

    float spec = pow(max(dot(Normal, halfwayDir), 0.0), 32);
    spec = specularLimit * spec;

    vec4 specular = spec * texture(material.texture_specular1, TexCoords);
    specular = resetAlpha(specular);

    return specular;
}

float distanceBetween(vec3 first, vec3 second) {
    vec3 difference = second - first;
    return sqrt(difference.x*difference.x + difference.y*difference.y + difference.z*difference.z);
}