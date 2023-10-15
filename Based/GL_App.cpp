#include "GL_App.h"


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

		if (initWin()) {
			cout << "Init window error!\n";
			return false;
		}

		if (initGL()) {
			cout << "Init OpenGL error!\n";
			return false;
		}

		return true;
	}

	void GL_App::run()
	{
		while (!isExit) {

		}
	}

	void GL_App::close()
	{

	}

	bool GL_App::initWin() {

		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

		window = glfwCreateWindow(info.width, info.height, info.title.c_str(), nullptr, nullptr);
		if (window == nullptr) {
			glfwTerminate();
			return false;
		}

		glfwMakeContextCurrent(window);

		if (gladLoadGL() != true) { return false; }

		return true;
	}

	bool GL_App::initGL() {

		return true;
	}
}
