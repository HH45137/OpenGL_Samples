#include "GL_App.h"
#include "Type.h"
#include "Common.h"

#include "Shader.h"


namespace OpenGLSamples::Based {

	Type::win_info_s winInfo = {};


	//Render fullscreen plane
	Shader planeShader;
	GLuint VAO, VBO, EBO;
	float vertices[] = {
		0.5f, 0.5f, 0.0f,   // 右上角
		0.5f, -0.5f, 0.0f,  // 右下角
		-0.5f, -0.5f, 0.0f, // 左下角
		-0.5f, 0.5f, 0.0f   // 左上角
	};
	unsigned int indices[] = {
		// 注意索引从0开始! 
		// 此例的索引(0,1,2,3)就是顶点数组vertices的下标，
		// 这样可以由下标代表顶点组合成矩形

		0, 1, 3, // 第一个三角形
		1, 2, 3  // 第二个三角形
	};

	void initRender()
	{
		planeShader.init(
			SHADER_BASE_DIR + "pt.vert",
			SHADER_BASE_DIR + "pt.frag"
		);

		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		{
			glBindVertexArray(VAO);

			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

			glEnableVertexAttribArray(0);
		}
	}

	void loopRender()
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		planeShader.Use();

		{
			glBindVertexArray(VAO);

			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			//glDrawArrays(GL_TRIANGLES, 0, 6);

			glBindVertexArray(0);
		}

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
