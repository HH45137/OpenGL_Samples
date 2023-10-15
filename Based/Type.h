#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/hash.hpp>

using namespace std;


namespace OpenGLSamples {
	namespace Type {

		//������Ϣ
		struct win_info_s {
			int width, height;
			string title;
		};

		//����
		struct Vertex {
			glm::vec3 pos;
			glm::vec2 texCoord;
			glm::vec3 normal;

			bool operator==(const Vertex& other) const {
				return pos == other.pos && texCoord == other.texCoord && normal == other.normal;
			}
		};
	}
}

namespace std {
	template<> struct hash<OpenGLSamples::Type::Vertex> {
		size_t operator()(OpenGLSamples::Type::Vertex const& vertex) const {
			return ((hash<glm::vec3>()(vertex.pos)) >> 1) ^ (hash<glm::vec2>()(vertex.texCoord) << 1) ^ (hash<glm::vec3>()(vertex.normal) << 1);
		}
	};
}
