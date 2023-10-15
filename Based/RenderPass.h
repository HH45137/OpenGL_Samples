#pragma once


namespace OpenGLSamples {
	namespace Based {

		class RenderPass
		{
		public:
			virtual void init() = 0;

			virtual void use() = 0;

			virtual void close() = 0;

		private:

		};

	}
}