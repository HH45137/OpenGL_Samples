#include <iostream>

#include "GL_App.h"
#include "Common.h"
#include "Material.h"

using namespace std;
using namespace OpenGLSamples;
using namespace OpenGLSamples::Based;


int main()
{
	Material cb_Material = { "CornellBox_Color.png" ,"phong_vs.glsl", "phong_fs.glsl" };
	Material pr_Material = { "price_texture_1k.png" ,"phong_vs.glsl", "phong_fs.glsl" };

	world.set(
		"CornellBox.obj",
		cb_Material,
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3(1.0f)
	);
	world.set(
		"Price.obj",
		pr_Material,
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
