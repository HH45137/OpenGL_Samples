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
		auto tL = world.getLightObject(0);
		SetUniformValue(tL->color, "lightColor");

		return 0;
	}


}
