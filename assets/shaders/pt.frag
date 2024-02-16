#version 460 core

struct ray
{
	vec3 ori;
	vec3 dir;
};

struct sphere 
{
	vec3 center;
	float radius;
};

out vec4 FragColor;

uniform vec3 SpherePos;
uniform float SphereRadius;
uniform vec3 CameraPos;

ray genRay(vec3 cameraPos, vec2 pixelPos)
{
	return ray(cameraPos, normalize(vec3(pixelPos, 0.0f) - cameraPos));
}

bool hitSphere(sphere sphere, ray r, out float t) 
{
    bool res = false;
    vec3 d = r.ori - sphere.center;  // distance

    float b = dot(r.dir, d);
    float c = dot(d, d) - sphere.radius* sphere.radius;

    t = b * b - c;

	float tm = 9999.0f;
    if(t > 0.0)
    {
        t = -b - sqrt(t);
        res = (t > 0.0) && (t < tm);
    }

    return res;
}

void main()
{
	ray r = genRay(CameraPos, gl_FragCoord.xy);

	vec3 color;
	float t;
	if(hitSphere(sphere(SpherePos, .5f), r, t))
	{
		color = vec3(1.0f, 0.0f, 0.0f);
	}
	else 
	{
		//Get bluesky
		float a = 0.5f * (r.dir.y + 1.0f);
		color = (1.0f - a) * vec3(1.0f) + a * vec3(.5f, .7f, 1.0f);
	}

	FragColor = vec4(color, 1.f);
}
