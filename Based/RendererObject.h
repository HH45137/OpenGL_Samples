#pragma once

#include "GL_Mesh.h"
#include "GL_Texture.h"
#include "Shader.h"


namespace OpenGLSamples::Based {

	class RendererObject
	{
	public:
		bool init();
		void render();
		void close();

		RendererObject();
		~RendererObject();

	public:
		GL_Mesh mesh = GL_Mesh("..\\assets\\CornellBox.obj");
		GL_Texture texture = GL_Texture("..\\assets\\CornellBox_Color.png");
		Shader shader = Shader("..\\assets\\model_vs.glsl", "..\\assets\\model_fs.glsl");

	private:
		glm::vec3 position = {};	//位置	
		glm::vec3 rotation = {};	//旋转
		glm::vec3 scaling = {};		//大小
	};

}
