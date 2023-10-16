#pragma once


namespace OpenGLSamples {
	namespace Based {

		class Texture
		{
		public:
			virtual bool init() = 0;

			virtual void use() = 0;

			virtual void close() = 0;

		public:
			//ÌùÍ¼µÄOpenGL¾ä±ú
			uint32_t handle;

		private:

		};
	}
}