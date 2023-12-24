#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/hash.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std;


namespace OpenGLSamples {
	namespace Type {

		//窗口信息
		struct win_info_s {
			int width, height;
			string title;
			void* handle;

			bool init(int _width, int _height, string _title) 
			{
				if (_width <= 0 || _height <= 0 || _title.empty()) { return false; }
				width = _width; height = _height; title = _title;

				glfwInit();
				glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
				glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
				glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
				glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

				handle = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
				if (handle == NULL) {
					glfwTerminate();
					return false;
				}

				glfwMakeContextCurrent((GLFWwindow*)handle);

				if (gladLoadGL() != true) { return false; }

				return true;
			}
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
