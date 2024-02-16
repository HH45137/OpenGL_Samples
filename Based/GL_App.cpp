#include "GL_App.h"
#include "Type.h"
#include "Common.h"

#include "Shader.h"


namespace OpenGLSamples::Based {

	Type::win_info_s winInfo = {};


	//Render fullscreen plane
	Shader planeShader;
	GLuint VAO;

	void initRender()
	{
		planeShader.init(
			SHADER_BASE_DIR + "pt.vert",
			SHADER_BASE_DIR + "pt.frag"
		);

		glGenVertexArrays(1, &VAO);
	}

	void loopRender()
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		planeShader.Use();

		glBindVertexArray(VAO);

		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glDrawArrays(GL_TRIANGLES, 0, 6);

		glfwSwapBuffers((GLFWwindow*)winInfo.handle);
	}

	bool GL_App::init(int _width, int _height, string _title)
	{
		cout << "Window info: " << "\n\twidth = " << _width << "\n\theight = " << _height << "\n";

		if (!winInfo.init(_width, _height, _title)) {
			cout << "Init window error!\n";
			return false;
		}

		initRender();

		/*-------------------设置深度缓冲和视口-------------------*/
		glViewport(0, 0, WIN_WIDTH, WIN_HEIGHT);
		glEnable(GL_DEPTH_TEST);

		return true;
	}

	void GL_App::run()
	{
		while (!glfwWindowShouldClose((GLFWwindow*)winInfo.handle)) {
			glfwPollEvents();

			loopRender();
		}
	}

	void GL_App::close()
	{
		std::cout << "App is close\n";

		glfwDestroyWindow((GLFWwindow*)winInfo.handle);
		glfwTerminate();
	}
}
