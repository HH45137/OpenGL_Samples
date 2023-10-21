#pragma once
#include "gl_App.h"


namespace OpenGLSamples {
	namespace Based {

		class RenderPipeline
		{
		public:
			virtual void init(GL_App& app) = 0;

			virtual void render() = 0;

			virtual void close() = 0;

		public:

		private:

		};

	}
}
