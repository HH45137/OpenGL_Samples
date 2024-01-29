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
		auto tC = world.getCamera()[0];

		SetUniformValue(tL->color, "lightColor");
		SetUniformValue(tL->position, "lightPos");
		SetUniformValue(tC->position, "viewPos");

		return 0;
	}


}
