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

	int Shader_Phong::inUpdate(int index)
	{
		auto tL = world.getLightObject(index);
		SetUniformValue(tL->color, "lightColor");
		SetUniformValue(tL->position, "lightPos");

		return 0;
	}


}
