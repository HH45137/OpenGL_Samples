#include <iostream>
#include "GL_App.h"

using namespace std;
using namespace OpenGLSamples;
using namespace OpenGLSamples::Based;

int main()
{
	GL_App app;

	try {
		app.init(1280, 720, "OpenGL base app");
		app.run();
		app.close();
	}
	catch (const std::exception& e) {
		cout << e.what() << "\n";
	}

	return 0;
}
