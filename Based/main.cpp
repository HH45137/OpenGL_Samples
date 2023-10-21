#include <iostream>

#include "GL_App.h"
#include "GL_World.h"

using namespace std;
using namespace OpenGLSamples;
using namespace OpenGLSamples::Based;


int main()
{
	GL_World world01;
	world01.set();

	GL_App app;

	try {
		app.init(WIN_WIDTH, WIN_HEIGHT, "OpenGL base app");
		app.run();
		app.close();
	}
	catch (const std::exception& e) {
		cout << e.what() << "\n";
	}

	return 0;
}
