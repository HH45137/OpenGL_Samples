#pragma once

#include "GL_Mesh.h"
#include "GL_Texture.h"
#include "Shader.h"


namespace OpenGLSamples::Based {

	class RendererObject
	{
	public:
		RendererObject(GL_Mesh _mesh, GL_Texture _texture, Shader _shader, glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scaling);

		//RendererObject() = default;
		~RendererObject() = default;

	public:
		GL_Mesh mesh;
		GL_Texture texture;
		Shader shader;

		glm::vec3 position = {};	//位置	
		glm::vec3 rotation = {};	//旋转
		glm::vec3 scaling = {};		//大小

	private:

	};

}
