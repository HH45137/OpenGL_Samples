#include "GL_App.h"
#include "GL_RenderPipeline.h"


namespace OpenGLSamples::Based {

	GL_App::GL_App()
	{

	}

	GL_App::~GL_App()
	{

	}

	bool GL_App::init(int _width, int _height, string _title)
	{
		if (_width <= 0 || _height <= 0 || _title.empty()) { return false; }
		info.width = _width; info.height = _height; info.title = _title;
		cout << "Window info: " << "\n\twidth = " << _width << "\n\theight = " << _height << "\n";

		if (!initWin()) {
			cout << "Init window error!\n";
			return false;
		}

		if (!initGL()) {
			cout << "Init OpenGL error!\n";
			return false;
		}

		/*-------------------������Ȼ�����ӿ�-------------------*/
		glViewport(0, 0, WIN_WIDTH, WIN_HEIGHT);
		glEnable(GL_DEPTH_TEST);

		return true;
	}

	void GL_App::run()
	{
		while (!glfwWindowShouldClose(window)) {
			glfwPollEvents();

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			//������Ⱦ����
			pipeline->render();

			glfwSwapBuffers(window);
		}
	}

	void GL_App::close()
	{
		std::cout << "App is close\n";

		//�ر���Ⱦ����
		pipeline->close();

		glfwDestroyWindow(window);
		glfwTerminate();
	}

	bool GL_App::initWin() {

		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

		window = glfwCreateWindow(info.width, info.height, info.title.c_str(), nullptr, nullptr);
		if (window == NULL) {
			glfwTerminate();
			return false;
		}

		glfwMakeContextCurrent(window);

		if (gladLoadGL() != true) { return false; }

		return true;
	}

	bool GL_App::initGL() {

		//��ʼ����Ⱦ����
		pipeline = new GL_RenderPipeline();
		pipeline->init();

		return true;
	}
}
