#pragma once

#include "RenderPass.h"
#include "RendererObject.h"


namespace OpenGLSamples {
	namespace Based {

		class GL_ImguiRenderPass : public RenderPass
		{
		public:
			bool init(Type::win_info_s& winInfo);

			void render();

			void close();

		private:

		};

	}
}
