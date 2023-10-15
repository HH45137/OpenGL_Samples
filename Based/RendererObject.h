#pragma once

#include "GL_Mesh.h"
#include "GL_Texture.h"


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

	private:

	};

}
