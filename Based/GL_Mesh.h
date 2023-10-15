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
			void init();

			void use();

			void close();

		private:
			void loadObjFile();

		private:
			uint32_t VBO, VAO, EBO;

			//��������
			std::vector<Type::Vertex> vertexes;

			//�����໥��ϵ������
			std::vector<uint32_t> indices;
		};
	}
}
