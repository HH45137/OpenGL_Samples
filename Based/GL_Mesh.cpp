#include <glad/glad.h>
#include <unordered_map>
#include <glm/gtx/hash.hpp>

#define TINYOBJLOADER_IMPLEMENTATION
#include <tiny_obj_loader.h>

#include "GL_Mesh.h"
#include "Type.h"


namespace OpenGLSamples::Based {

	bool GL_Mesh::init()
	{
		if (filePath.empty()) { cout << "Mesh path is empty!\n"; return false; };

		if (!loadObjFile(filePath)) { cout << "Mesh load is error!\n"; return false; }

		vertexCount = indices.size();
	}

	void GL_Mesh::close()
	{

	}

	GL_Mesh::GL_Mesh(std::string _path)
	{
		filePath = _path;
	}

	GL_Mesh::GL_Mesh()
	{
	}

	GL_Mesh::~GL_Mesh()
	{
	}

	bool GL_Mesh::loadObjFile(string _path)
	{
		tinyobj::attrib_t attrib;
		std::vector<tinyobj::shape_t> shapes;
		std::vector<tinyobj::material_t> materials;

		std::vector<tinyobj::index_t> uvIndices;

		std::string waring, error;

		//Load obj file
		bool isLoad = tinyobj::LoadObj(&attrib, &shapes, &materials, &waring, &error, _path.c_str(), _path.c_str(), true, false);
		if (!isLoad) {
			std::cout << "Load error!" << "\n";
			std::cout << "\t" << waring << "\n";
			std::cout << "\t" << error << "\n";

			return false;
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

		return true;
	}

}

