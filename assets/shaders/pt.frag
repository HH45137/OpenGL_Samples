#version 460 core

struct ray
{
	vec3 ori;
	vec3 dir;
};

out vec4 FragColor;

ray genRay(vec3 cameraPos, vec2 pixelPos)
{
	return ray(cameraPos, normalize(vec3(pixelPos, 0.0f) - cameraPos));
}

void main()
{
	ray r = genRay(vec3(0.0f, 0.0f, -1.0f), gl_FragCoord.xy);

	//Get bluesky
	float a = 0.5f * (r.dir.y + 1.0f);
	vec3 color = (1.0f - a) * vec3(1.0f) + a * vec3(.5f, .7f, 1.0f);

	FragColor = vec4(color, 1.f);
}
