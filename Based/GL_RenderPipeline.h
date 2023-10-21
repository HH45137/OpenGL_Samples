#pragma once

#include <iostream>
#include <vector>
#include <map>

#include "RenderPipeline.h"
#include "RenderPass.h"


namespace OpenGLSamples {
	namespace Based {

		class GL_RenderPipeline : public RenderPipeline
		{
		public:
			void init(GL_App& app);

			void render();

			void close();

		private:
			std::vector<RenderPass*> renderPass;

		};

	}
}
