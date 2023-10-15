#pragma once

#include "RenderPass.h"
#include "RendererObject.h"


namespace OpenGLSamples {
	namespace Based {

		class GL_SceneRenderPass : public RenderPass
		{
		public:
			void init();

			void use();

			void close();

		private:
			std::vector<RendererObject> objects;
		};

	}
}
