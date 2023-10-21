#include "GL_App.h"
#include "GL_RenderPipeline.h"
#include "GL_World.h"
#include "Type.h"


bool initWin(OpenGLSamples::Type::win_info_s& info) {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	info.handle = glfwCreateWindow(info.width, info.height, info.title.c_str(), nullptr, nullptr);
	if (info.handle == NULL) {
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent((GLFWwindow*)info.handle);

	if (gladLoadGL() != true) { return false; }

	return true;
}

namespace OpenGLSamples::Based {

	GL_App::GL_App()
	{

	}

	GL_App::~GL_App()
	{

	}

	bool GL_App::init(int _width, int _height, string _title, GL_World& world)
	{
		if (_width <= 0 || _height <= 0 || _title.empty()) { return false; }
		info.width = _width; info.height = _height; info.title = _title;
		cout << "Window info: " << "\n\twidth = " << _width << "\n\theight = " << _height << "\n";

		if (!initWin(this->info)) {
			cout << "Init window error!\n";
			return false;
		}

		//初始化渲染管线
		if (!pipeline.init(this->info, world)) {
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
		while (!glfwWindowShouldClose((GLFWwindow*)info.handle)) {
			glfwPollEvents();

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			//调用渲染管线
			pipeline.render();

			glfwSwapBuffers((GLFWwindow*)info.handle);
		}
	}

	void GL_App::close()
	{
		std::cout << "App is close\n";

		//关闭渲染管线
		pipeline.close();

		glfwDestroyWindow((GLFWwindow*)info.handle);
		glfwTerminate();
	}
}
