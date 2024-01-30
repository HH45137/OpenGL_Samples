#include "Shader_PT.h"
#include "Common.h"


namespace OpenGLSamples::Based {

	Shader_PT::Shader_PT()
	{
	}
	Shader_PT::~Shader_PT()
	{
	}

	int Shader_PT::inInit()
	{

		return 0;
	}

	int Shader_PT::inUpdate()
	{
		auto tL = world.getLightObjects()[0];
		auto tC = world.getCamera()[0];

		SetUniformValue(tL->color, "lightColor");
		SetUniformValue(tL->position, "lightPos");
		SetUniformValue(tC->position, "viewPos");

		return 0;
	}

}
