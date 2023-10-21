#pragma once


namespace OpenGLSamples {
	namespace Based {

		class RenderPipeline
		{
		public:
			virtual void init() = 0;

			virtual void render() = 0;

			virtual void close() = 0;

		public:

		private:

		};

	}
}
