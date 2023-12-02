#include "Shader_Phong.h"


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
		SetUniformValue(glm::vec3(1.0f, 0.5f, 0.2f), "lightColor");

		return 0;
	}


}
