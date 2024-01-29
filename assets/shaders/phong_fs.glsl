#version 460 core

out vec4 FragColor;
in vec4 oColor;
in vec2 UV;
in vec3 oNormal;

uniform sampler2D texture01;
uniform vec3 lightColor;
uniform vec3 lightPos;

void main()
{
	float ambientStrength = 1.0;
	vec3 ambient = ambientStrength * lightColor;

	vec3 result = ambient;

	FragColor = texture(texture01, UV) * vec4(result, 1.0f);
}
