#version 460 core

out vec4 FragColor;

void main()
{
	vec3 pixelColor = vec3(normalize(gl_FragCoord.xy), 0.f);
	
	FragColor = vec4(pixelColor, 1.f);
}
