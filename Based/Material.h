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

		int use();

		int clean();

	private:
		std::string texturePath;
		std::string vsPath, fsPath;

		GL_Texture texture;
		Shader* shader;

	private:
		int choiceShaderType();
	};
}
