#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/hash.hpp>

using namespace std;


namespace OpenGLSamples {
	namespace Type {

		//窗口信息
		struct win_info_s {
			int width, height;
			string title;
			void* handle;
		};

		//顶点
		struct Vertex {
			glm::vec3 pos;
			glm::vec2 texCoord;
			glm::vec3 normal;

			bool operator==(const Vertex& other) const {
				return pos == other.pos && texCoord == other.texCoord && normal == other.normal;
			}
		};

		//物体类型
		enum OBJECT_TYPE {
			RENDER_OBJECT = 1,
			CAMERA,
			LIGHT_OBJECT,
			OBJECT_TYPE_COUNT
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
