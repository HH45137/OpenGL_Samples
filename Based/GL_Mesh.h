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

			//模型文件路径
			std::string filePath;

			//顶点数量
			int vertexCount;

			//顶点数据
			std::vector<Type::Vertex> vertexes;

			//顶点相互联系的数据
			std::vector<uint32_t> indices;

		private:

		};
	}
}
