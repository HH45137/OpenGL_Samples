#version 460 core

out vec4 FragColor;
in vec4 oColor;
in vec2 UV;

uniform sampler2D texture01;
uniform vec3 lightColor;

void main()
{
	float ambientStrength = 0.1;
	vec4 ambient = vec4(ambientStrength * lightColor, 1.0f);

	FragColor = texture(texture01, UV) * ambient;
}
