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
		Mesh* mesh = new GL_Mesh("..\\assets\\CornellBox.obj");
		Texture* texture = new GL_Texture("..\\assets\\CornellBox_Color.png");
		Shader shader = Shader("..\\assets\\model_vs.glsl", "..\\assets\\model_fs.glsl");

	private:

	};

}
