#include "GL_App.h"
#include "GL_RenderPipeline.h"
#include "GL_World.h"
#include "Type.h"
#include "Common.h"


namespace OpenGLSamples::Based {

	GL_App::GL_App()
	{

	}

	GL_App::~GL_App()
	{

	}

	bool GL_App::init(int _width, int _height, string _title)
	{
		cout << "Window info: " << "\n\twidth = " << _width << "\n\theight = " << _height << "\n";

		if (!winInfo.init(_width, _height, _title)) {
			cout << "Init window error!\n";
			return false;
		}

		//初始化渲染管线
		if (!pipeline.init()) {
			cout << "Init OpenGL error!\n";
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

			//调用渲染管线
			pipeline.render();

			glfwSwapBuffers((GLFWwindow*)winInfo.handle);
		}
	}

	void GL_App::close()
	{
		std::cout << "App is close\n";

		//关闭渲染管线
		pipeline.close();

		glfwDestroyWindow((GLFWwindow*)winInfo.handle);
		glfwTerminate();
	}
}
