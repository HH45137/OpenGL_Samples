#pragma once

#include <glm/glm.hpp>
#include <iostream>
#include <vector>
#include <string>

#include "Type.h"


namespace OpenGLSamples {
	namespace Based {

		class GL_Mesh
		{
		public:
			bool init();

			void close();

			GL_Mesh(std::string _path);

			GL_Mesh();
			~GL_Mesh();

		private:
			bool loadObjFile(string _path);

		public:
			uint32_t VBO, VAO, EBO;

			//ģ���ļ�·��
			std::string filePath;

			//��������
			int vertexCount;

			//��������
			std::vector<Type::Vertex> vertexes;

			//�����໥��ϵ������
			std::vector<uint32_t> indices;

		private:

		};
	}
}
