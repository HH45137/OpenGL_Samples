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
			//��ͼ�ļ�·��
			std::string filePath;

		private:
			//��ͼ��OpenGL���
			uint32_t handle;

		};
	}
}
