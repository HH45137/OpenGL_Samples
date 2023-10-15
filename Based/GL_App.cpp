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
		
		isExit = false;

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
}
