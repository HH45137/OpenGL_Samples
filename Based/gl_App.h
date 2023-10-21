#pragma once

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "App.h"
#include "Type.h"
#include "RenderPipeline.h"


namespace OpenGLSamples {
	namespace Based {

		const int WIN_WIDTH = 1280, WIN_HEIGHT = 720, FOV = 90;

		//OpenGL App
		class GL_App : public App
		{
		public:
			Type::win_info_s info;
			GLFWwindow* window_handle;

		public:
			GL_App();
			~GL_App();

			bool init(int _width, int _height, string _title);

			void run();

			void close();

		private:
			RenderPipeline* pipeline;

		private:
			bool initWin();

			bool initGL();

		};
	}
}