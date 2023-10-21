#pragma once

#include "RenderPass.h"
#include "RendererObject.h"
#include "GL_World.h"


namespace OpenGLSamples {
	namespace Based {

		class GL_ImguiRenderPass : public RenderPass
		{
		public:
			bool init(Type::win_info_s& winInfo, GL_World& world);

			void render();

			void close();

		private:

		};

	}
}
