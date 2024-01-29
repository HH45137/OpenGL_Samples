#include <iostream>

#include "GL_App.h"
#include "Common.h"

using namespace std;
using namespace OpenGLSamples;
using namespace OpenGLSamples::Based;


int main()
{
	world.set(
		"PC_Mesh.obj",
		"PC_Texture.png",
		"phong_vs.glsl", "phong_fs.glsl",
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3(1.0f)
	);
	world.set(
		"CornellBox.obj",
		"CornellBox_Color.png",
		"phong_vs.glsl", "phong_fs.glsl",
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3(1.0f)
	);
	world.set(
		"Price.obj",
		"price_texture_1k.png",
		"phong_vs.glsl", "phong_fs.glsl",
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3(5.0f)
	);
	world.set(
		glm::vec3(0.0f, 2.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f),
		0.8f
	);
	world.set(
		glm::vec3(75.0f, 46.0f, -5.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
	);

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
