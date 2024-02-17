#version 460 core

const float EPSILON  = 1e-6;
const float INFINITY = 1e+4;

const float MAX = 99999.0f;
const float MIN = -99999.0f;

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

struct camera 
{
	vec3 lower_left_corner;
	vec3 horizontal;
	vec3 vertical;
	vec3 origin;
};

out vec4 FragColor;
in vec2 screenCoord;

uniform vec3 SpherePos;
uniform float SphereRadius;

uniform camera camera01;

ray genRay()
{
	float u = screenCoord.x;
	float v = screenCoord.y;
	
	vec3 ray_dir = 
	camera01.lower_left_corner + 
	u * camera01.horizontal + 
	v * camera01.vertical - camera01.origin;

	return ray(camera01.origin, ray_dir);
}

bool hitSphere(sphere sphere, ray r, out float t) 
{
	vec3 oc = r.ori - sphere.center;
	float A = length(r.dir);
	float half_B = dot(oc, r.dir);
	float C = length(oc) - sphere.radius * sphere.radius;

	float discriminant = half_B * half_B - A * C;
	if (discriminant < 0.0f) { return false; }

	//找到位于可接受范围内的最近的根
	float sqrtd = sqrt(discriminant);
	float root = (-half_B - sqrtd) / A;
	if (!(MIN < root && root < MAX)) {
		root = (-half_B + sqrtd) / A;
		if (!(MIN < root && root < MAX)) {
			return false;
		}
	}

	return true;
}

void main()
{
	ray r = genRay();

	vec3 color;
	float t;
	if(hitSphere(sphere(SpherePos, .5f), r, t))
	{
		color = vec3(1.0f, 0.0f, 0.0f);
	}
	else 
	{
		//Get bluesky
		vec3 normalizeDir = normalize(r.dir);
		float a = 0.5f * (normalizeDir.y + 1.0f);
		color = (1.0f - a) * vec3(1.0f) + a * vec3(.5f, .7f, 1.0f);
	}

	FragColor = vec4(color, 1.f);
	// FragColor = vec4(screenCoord.xy, 0.2f, 1.0f);
}
