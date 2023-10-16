#pragma once

#include <glm/glm.hpp>
#include <iostream>
#include <vector>
#include <string>

#include "Mesh.h"
#include "Type.h"


namespace OpenGLSamples {
	namespace Based {

		class GL_Mesh : public Mesh
		{
		public:
			bool init();

			void use();

			void close();

			GL_Mesh(std::string _path);

			GL_Mesh();
			~GL_Mesh();

		private:
			bool loadObjFile(string _path);

		public:
			//ģ���ļ�·��
			std::string filePath;

		private:
			uint32_t VBO, VAO, EBO;

			//��������
			std::vector<Type::Vertex> vertexes;

			//�����໥��ϵ������
			std::vector<uint32_t> indices;
		};
	}
}
