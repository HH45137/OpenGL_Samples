#version 460 core

struct Material {
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shininess;
};

out vec4 FragColor;
in vec4 oColor;
in vec2 UV;
in vec3 oNormal;
in vec3 oFragPos;

uniform sampler2D texture01;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

uniform Material material;

void main()
{
	//Ambient
	vec3 ambient = material.ambient * lightColor;

	//Diffuse
	vec3 norm = normalize(oNormal);
	vec3 lightDir = normalize(lightPos - oFragPos);
	float diff = max(dot(norm, lightDir), 0.0f);
	vec3 diffuse = (diff * material.diffuse) * lightColor;

	//Specular
	vec3 viewDir = normalize(viewPos - oFragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess);
	vec3 specular = (material.specular * spec) * lightColor;

	vec3 result = ambient + diffuse + specular;
	FragColor = texture(texture01, UV) * vec4(result, 1.0f);
}
