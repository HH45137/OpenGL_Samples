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
		1.0f,  1.0f,  0.0f,	// ���Ͻ�
		1.0f,  -1.0f, 0.0f,	// ���½�
		-1.0f, -1.0f, 0.0f,	// ���½�
		-1.0f, 1.0f,  0.0f	// ���Ͻ�
	};
	unsigned int indices[] = {
		// ע��������0��ʼ! 
		// ����������(0,1,2,3)���Ƕ�������vertices���±꣬
		// �����������±��������ϳɾ���

		0, 1, 3, // ��һ��������
		1, 2, 3  // �ڶ���������
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
		planeShader.SetUniformValue(glm::vec3(0.0f, 0.0f, -1.0f), "SpherePos");
		planeShader.SetUniformValue(0.2f, "SphereRadius");

		planeShader.SetUniformValue(glm::vec3(-2.0f, -1.0f, -1.0f), "camera01.lower_left_corner");
		planeShader.SetUniformValue(glm::vec3(4.0f, 0.0f, 0.0f), "camera01.horizontal");
		planeShader.SetUniformValue(glm::vec3(0.0f, 2.0f, 0.0f), "camera01.vertical");
		planeShader.SetUniformValue(glm::vec3(0.0f, 0.0f, 0.0f), "camera01.origin");

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

		/*-------------------������Ȼ�����ӿ�-------------------*/
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
