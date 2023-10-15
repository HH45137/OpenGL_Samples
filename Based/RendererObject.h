#pragma once

#include "GL_Mesh.h"


namespace OpenGLSamples::Based {

	class RendererObject
	{
	public:
		bool init();
		void close();

		RendererObject();
		~RendererObject();

	public:
		Mesh* mesh = new GL_Mesh("");

	private:

	};

}
