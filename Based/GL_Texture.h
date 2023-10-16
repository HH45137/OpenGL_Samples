#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Type.h"


namespace OpenGLSamples {
	namespace Based {

		class GL_Texture
		{
		public:
			bool init();

			void use();

			void close();

			GL_Texture(std::string _path);

			GL_Texture();
			~GL_Texture();

		private:


		public:
			//ÌùÍ¼ÎÄ¼şÂ·¾¶
			std::string filePath;

			unsigned int handle;

		private:

		};
	}
}
