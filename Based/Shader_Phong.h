#pragma once
#include "Shader.h"


namespace OpenGLSamples::Based {

	class Shader_Phong : public Shader
	{
	public:
		Shader_Phong(std::string vertexSourceCodePath, std::string fragmentSourceCodePath);
		Shader_Phong();
		~Shader_Phong();

		int inInit();
		int inUpdate();

	private:

	};
}