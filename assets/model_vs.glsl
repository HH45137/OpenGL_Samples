#version 460 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aUV;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec4 color;

out vec4 oColor;
out vec2 UV;

void main()
{
	oColor = color;
	UV = aUV;
	gl_Position = projection * view * model * vec4(aPos, 1.0);
}
