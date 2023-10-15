#include <unordered_map>
#include <glm/gtx/hash.hpp>

#define TINYOBJLOADER_IMPLEMENTATION
#include <tiny_obj_loader.h>

#include "GL_Mesh.h"


namespace OpenGLSamples::Based {

	void GL_Mesh::init()
	{

	}

	void GL_Mesh::use()
	{

	}

	void GL_Mesh::close()
	{

	}

	void GL_Mesh::loadObjFile()
	{
		tinyobj::attrib_t attrib;
		std::vector<tinyobj::shape_t> shapes;
		std::vector<tinyobj::material_t> materials;

		std::vector<tinyobj::index_t> uvIndices;

		std::string waring, error;

		//Load obj file
		bool isLoad = tinyobj::LoadObj(&attrib, &shapes, &materials, &waring, &error, path, path, true, false);
		if (!isLoad) {
			std::cout << "Load error!" << "\n";
			std::cout << "\t" << waring << "\n";
			std::cout << "\t" << error << "\n";

			return;
		}

		std::unordered_map<Type::Vertex, uint32_t> uniqueVertices{};

		for (const auto& shape : shapes) {
			for (const auto& index : shape.mesh.indices) {
				Type::Vertex vertex{};

				vertex.pos = {
					attrib.vertices[3 * index.vertex_index + 0],
					attrib.vertices[3 * index.vertex_index + 1],
					attrib.vertices[3 * index.vertex_index + 2]
				};
				vertex.texCoord = {
					attrib.texcoords[2 * index.texcoord_index + 0],
					1.0f - attrib.texcoords[2 * index.texcoord_index + 1],
				};
				vertex.normal = {
					attrib.normals[3 * index.normal_index + 0],
					attrib.normals[3 * index.normal_index + 1],
					attrib.normals[3 * index.normal_index + 2]
				};

				if (uniqueVertices.count(vertex) == 0) {
					uniqueVertices[vertex] = static_cast<uint32_t>(vertexes.size());
					vertexes.push_back(vertex);
				}

				indices.push_back(uniqueVertices[vertex]);
			}
		}
	}

}

