#pragma once

#include "RenderPass.h"
#include "RendererObject.h"


namespace OpenGLSamples {
	namespace Based {

		class GL_SceneRenderPass : public RenderPass
		{
		public:
			bool init();

			void render();

			void close();

		private:
			std::vector<RendererObject> objects;
		};

	}
}
