#include "GL_App.h"
#include "Type.h"
#include "Common.h"


namespace OpenGLSamples::Based {

	Type::win_info_s winInfo = {};

	bool GL_App::init(int _width, int _height, string _title)
	{
		cout << "Window info: " << "\n\twidth = " << _width << "\n\theight = " << _height << "\n";

		if (!winInfo.init(_width, _height, _title)) {
			cout << "Init window error!\n";
			return false;
		}

		/*-------------------设置深度缓冲和视口-------------------*/
		glViewport(0, 0, WIN_WIDTH, WIN_HEIGHT);
		glEnable(GL_DEPTH_TEST);

		return true;
	}

	void GL_App::run()
	{
		while (!glfwWindowShouldClose((GLFWwindow*)winInfo.handle)) {
			glfwPollEvents();

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glfwSwapBuffers((GLFWwindow*)winInfo.handle);
		}
	}

	void GL_App::close()
	{
		std::cout << "App is close\n";

		glfwDestroyWindow((GLFWwindow*)winInfo.handle);
		glfwTerminate();
	}
}
