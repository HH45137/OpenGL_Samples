#version 460 core

layout(location=0)in vec3 aPos;

out vec2 screenCoord;

void main()
{
	screenCoord = (aPos.xy + 1.0f) / 2.0f;

	gl_Position=vec4(aPos.xyz,1.f);
}