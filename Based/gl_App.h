#pragma once

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Type.h"


namespace OpenGLSamples {
	namespace Based {

		const int WIN_WIDTH = 1920, WIN_HEIGHT = 1080, FOV = 70;

		//OpenGL App
		class GL_App
		{
		public:
			GL_App() = default;
			~GL_App() = default;

			bool init(int _width, int _height, string _title);

			void run();

			void close();

		private:

		};
	}
}