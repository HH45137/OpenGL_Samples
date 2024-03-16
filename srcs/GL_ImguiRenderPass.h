#pragma once

#include "RenderPass.h"
#include "RendererObject.h"
#include "GL_World.h"


namespace OpenGLSamples {
	namespace Based {

		class GL_ImguiRenderPass : public RenderPass
		{
		public:
			GL_ImguiRenderPass() = default;
			~GL_ImguiRenderPass() = default;

			bool init();

			void render();

			void close();

		private:

		};

	}
}
