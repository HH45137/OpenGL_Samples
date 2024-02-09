#version 460 core

void main()
{
	vec3 vertices[4]=vec3[](
		vec3(.5f,.5f,.5f),// top right
		vec3(.5f,-.5f,.5f),// bottom right
		vec3(-.5f,-.5f,.5f),// bottom left
		vec3(-.5f,.5f,.5f)// top left
	);
	
	gl_Position=vec4(vertices[gl_VertexID],1.f);
}