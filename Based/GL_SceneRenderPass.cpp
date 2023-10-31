#include "GL_SceneRenderPass.h"
#include "RendererObject.h"
#include "gl_App.h"

using namespace OpenGLSamples::Based;


GLFWwindow* windowHandle = nullptr;	//���ھ��

glm::mat4 processCameraInput(GLFWwindow* _window, Camera _camera, float _speed) {

	glm::mat4 viewMat = glm::lookAt(_camera.position, _camera.position + _camera.front, _camera.up);

	return viewMat;
}

Camera* cameraTemp = nullptr;	//��ʱ����Camera����

namespace OpenGLSamples::Based {

	bool GL_SceneRenderPass::init(Type::win_info_s& winInfo, GL_World& world)
	{
		windowHandle = (GLFWwindow*)winInfo.handle;

		//��õ�ǰ������Camera
		cameraTemp = world.getCamera();

		this->objects = &world.get();

		for (auto& item : *objects)
		{
			if (!item.init()) {
				cout << "RenderObject init error!\n";
				return false;
			}

			//-----���ø��ֶ���Buffer-----
			glGenVertexArrays(1, &item.mesh.VAO);
			glGenBuffers(1, &item.mesh.VBO);
			glGenBuffers(1, &item.mesh.EBO);

			glBindVertexArray(item.mesh.VAO);

			//-----��������-----
			glBindBuffer(GL_ARRAY_BUFFER, item.mesh.VBO);
			glBufferData(GL_ARRAY_BUFFER, item.mesh.vertexes.size() * sizeof(Type::Vertex), item.mesh.vertexes.data(), GL_STATIC_DRAW);

			//-----���ö�������-----
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Type::Vertex), (GLvoid*)0);
			glEnableVertexAttribArray(0);

			//-----������ͼ��������-----
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Type::Vertex), (GLvoid*)(3 * sizeof(GLfloat)));
			glEnableVertexAttribArray(1);

			glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Type::Vertex), (GLvoid*)(5 * sizeof(GLfloat)));
			glEnableVertexAttribArray(2);

			//-----������������-----
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, item.mesh.EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, item.mesh.indices.size() * sizeof(GLuint), item.mesh.indices.data(), GL_STATIC_DRAW);

			glEnableVertexAttribArray(0);

			glBindBuffer(GL_ARRAY_BUFFER, 0);

			glBindVertexArray(0);

			if (!item.texture.init()) {
				return false;
			}

			//������ͼ
			item.texture.use();
			item.shader.Use();
			item.shader.SetUniformValue(item.texture.handle, "texture01");
		}

		return true;
	}

	void GL_SceneRenderPass::render()
	{
		for (auto& item : *objects) {
			item.shader.Use();
			item.texture.use();

			glBindVertexArray(item.mesh.VAO);

			//��ס������Ҫ�ȳ�ʼ������Ϊ1����ȻҪ��������
			glm::mat4 viewMat = glm::mat4(1.0f);
			glm::mat4 projectionMat = glm::mat4(1.0f);
			glm::mat4 modelMat = glm::mat4(1.0f);

			modelMat = glm::translate(modelMat, item.position);
			modelMat = glm::rotate(modelMat, glm::radians(item.rotationAngle), item.rotation);
			modelMat = glm::scale(modelMat, item.scaling);

			viewMat = processCameraInput(windowHandle, *cameraTemp, 1.0f);
			projectionMat = glm::perspective((float)FOV, WIN_WIDTH / (float)WIN_HEIGHT, 0.1f, 1000.0f);

			item.shader.SetUniformValue(modelMat, "model");
			item.shader.SetUniformValue(viewMat, "view");
			item.shader.SetUniformValue(projectionMat, "projection");

			glDrawElements(GL_TRIANGLES, item.mesh.vertexCount, GL_UNSIGNED_INT, (GLvoid*)0);
			glBindVertexArray(0);
		}
	}

	void GL_SceneRenderPass::close()
	{

	}
}
