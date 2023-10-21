#pragma once


namespace OpenGLSamples {
	namespace Based {

		class RenderPass
		{
		public:
			virtual bool init() = 0;

			virtual void render() = 0;

			virtual void close() = 0;

		public:
			void* window_handle;

		private:

		};

	}
}