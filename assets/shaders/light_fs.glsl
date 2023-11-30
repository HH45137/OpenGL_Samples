#version 460 core

out vec4 FragColor;
in vec4 oColor;
in vec2 UV;

uniform sampler2D texture01;

void main()
{
//	FragColor = vec4(UV, 1.0f, 1.0f);

	FragColor = texture(texture01, UV);
}
