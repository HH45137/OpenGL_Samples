#pragma once

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Type.h"
#include "GL_RenderPipeline.h"


namespace OpenGLSamples {
	namespace Based {

		const int WIN_WIDTH = 1280, WIN_HEIGHT = 720, FOV = 90;

		//OpenGL App
		class GL_App
		{
		public:
			Type::win_info_s info;

		public:
			GL_App();
			~GL_App();

			bool init(int _width, int _height, string _title, GL_World& world);

			void run();

			void close();

		private:
			GL_RenderPipeline pipeline;

		};
	}
}