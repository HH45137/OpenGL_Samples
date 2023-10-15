#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Type.h"
#include "Texture.h"


namespace OpenGLSamples {
	namespace Based {

		class GL_Texture : public Texture
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
			//贴图文件路径
			std::string filePath;

		private:
			//贴图的OpenGL句柄
			uint32_t handle;

		};
	}
}
