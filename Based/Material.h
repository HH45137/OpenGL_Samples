#pragma once

#include "GL_Mesh.h"
#include "GL_Texture.h"
#include "Shader.h"


namespace OpenGLSamples::Based {

	class Material
	{
	public:
		Material(std::string _texturePath, std::string _vsPath, std::string _fsPath);
		Material() = default;
		~Material() = default;

		int init();

		int update();

		int clean();

	public:
		GL_Texture texture;
		Shader* shader;

	private:
		std::string texturePath;
		std::string vsPath, fsPath;

	private:
		int choiceShaderType();
	};
}
