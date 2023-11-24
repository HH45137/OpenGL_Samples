#include <iostream>

#include "GL_App.h"
#include "GL_World.h"

using namespace std;
using namespace OpenGLSamples;
using namespace OpenGLSamples::Based;


int main()
{
	GL_World world01;
	world01.set(
		RendererObject(
			"..\\assets\\CornellBox.obj",
			"..\\assets\\CornellBox_Color.png",
			"..\\assets\\model_vs.glsl", "..\\assets\\model_fs.glsl",
			glm::vec3(0.0f, 0.0f, 0.0f),
			glm::vec3(0.0f, 1.0f, 0.0f),
			glm::vec3(1.0f)));
	//world01.set(
	//	RendererObject(
	//		"..\\assets\\PC_Mesh.obj",
	//		"..\\assets\\PC_Texture.png",
	//		"..\\assets\\model_vs.glsl", "..\\assets\\model_fs.glsl",
	//		glm::vec3(0.0f, 0.0f, 0.0f),
	//		glm::vec3(0.0f, 1.0f, 0.0f),
	//		glm::vec3(5.0f))
	//);
	world01.set(
		RendererObject(
			"..\\assets\\Price.obj",
			"..\\assets\\price_texture_1k.png",
			"..\\assets\\model_vs.glsl", "..\\assets\\model_fs.glsl",
			glm::vec3(0.0f, 0.0f, 0.0f),
			glm::vec3(0.0f, 1.0f, 0.0f),
			glm::vec3(5.0f)));

	world01.set(
		LightObject(
			glm::vec3(0.0f, 2.0f, 0.0f),
			glm::vec3(0.0f, 1.0f, 0.0f),
			0.8f
		)
	);

	world01.set(
		Camera(
			glm::vec3(0.0f, 0.0f, 0.0f),
			glm::vec3(0.0f, 1.0f, 0.0f)));

	GL_App app;

	try {
		app.init(WIN_WIDTH, WIN_HEIGHT, "OpenGL base app", world01);
		app.run();
		app.close();
	}
	catch (const std::exception& e) {
		cout << e.what() << "\n";
	}

	return 0;
}
