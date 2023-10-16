#pragma once


namespace OpenGLSamples {
	namespace Based {

		class Mesh
		{
		public:
			virtual bool init() = 0;

			virtual void use() = 0;

			virtual void close() = 0;

		private:

		};
	}
}