#pragma once

#include "RenderPass.h"
#include "RendererObject.h"


namespace OpenGLSamples {
	namespace Based {

		class GL_SceneRenderPass : public RenderPass
		{
		public:
			GL_SceneRenderPass() = default;
			~GL_SceneRenderPass() = default;

			bool init();

			void render();

			void close();

		private:

		};

	}
}