#pragma once

#include <iostream>
#include <vector>
#include <map>

#include "RenderPass.h"


namespace OpenGLSamples {
	namespace Based {

		class GL_RenderPipeline
		{
		public:
			GL_RenderPipeline() = default;
			~GL_RenderPipeline() = default;

			void init(Type::win_info_s& winInfo);

			void render();

			void close();

		private:
			std::vector<RenderPass*> renderPass;

		};

	}
}
