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

			//顶点数据
			std::vector<Type::Vertex> vertexes;

			//顶点相互联系的数据
			std::vector<uint32_t> indices;
		};
	}
}
