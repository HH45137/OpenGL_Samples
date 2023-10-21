#pragma once

#include "Type.h"


namespace OpenGLSamples {
	namespace Based {

		class RenderPass
		{
		public:
			virtual bool init(Type::win_info_s& winInfo) = 0;

			virtual void render() = 0;

			virtual void close() = 0;

		public:

		private:

		};

	}
}