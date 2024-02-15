#include "Shader_Phong.h"
#include "Common.h"


namespace OpenGLSamples::Based {

	Shader_Phong::Shader_Phong()
	{

	}
	Shader_Phong::~Shader_Phong()
	{

	}

	int Shader_Phong::inInit()
	{

		return 0;
	}

	int Shader_Phong::inUpdate()
	{
		auto tL = world.getLightObjects()[0];
		auto tC = world.getCamera()[0];

		SetUniformValue(tL->color, "lightColor");
		SetUniformValue(tL->position, "lightPos");
		SetUniformValue(tC->position, "viewPos");

		SetUniformValue(glm::vec3(1.0f, 1.0f, 1.0f), "material.ambient");
		SetUniformValue(glm::vec3(1.0f, 1.0f, 1.0f), "material.diffuse");
		SetUniformValue(glm::vec3(1.0f, 1.0f, 1.0f), "material.specular");
		SetUniformValue(1.0f, "material.shininess");

		return 0;
	}


}
