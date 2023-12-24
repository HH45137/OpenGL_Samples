#pragma once

#include <iostream>
#include <vector>
#include <map>

#include "RenderPass.h"
#include "GL_World.h"


namespace OpenGLSamples {
	namespace Based {

		class GL_RenderPipeline
		{
		public:
			GL_RenderPipeline() = default;
			~GL_RenderPipeline() = default;

			bool init();

			void render();

			void close();

		private:
			std::vector<RenderPass*> renderPass;

		};

	}
}
