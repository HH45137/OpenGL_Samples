#version 460 core

out vec4 FragColor;
in vec4 oColor;
in vec2 UV;
in vec3 oNormal;
in vec3 oFragPos;

uniform sampler2D texture01;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

void main()
{
	//Ambient
	float ambientStrength = 1.0;
	vec3 ambient = ambientStrength * lightColor;

	//Diffuse
	vec3 norm = normalize(oNormal);
	vec3 lightDir = normalize(lightPos - oFragPos);
	float diff = max(dot(norm, lightDir), 0.0f);
	vec3 diffuse = diff * lightColor;

	//Specular
	float specularStrength = 0.5f;
	vec3 viewDir = normalize(viewPos - oFragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0f), 32);
	vec3 specular = specularStrength * spec * lightColor;

	vec3 result = ambient + diffuse + specular;
	FragColor = texture(texture01, UV) * vec4(result, 1.0f);
}
