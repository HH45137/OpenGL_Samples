#include "GL_SceneRenderPass.h"
#include "RendererObject.h"
#include "gl_App.h"

using namespace OpenGLSamples::Based;


GLFWwindow* windowHandle = nullptr;	//窗口句柄

//处理摄像机相关的设备输入
void processCameraInput(GLFWwindow* _window, Camera* _camera) {

	//========键盘操作========
	float _speed = 0.7;

	if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS) { _camera->position += _speed * _camera->front; }
	if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS) { _camera->position -= _speed * _camera->front; }

	if (glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS) { _camera->position -= glm::normalize(glm::cross(_camera->front, _camera->up)) * _speed; }
	if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS) { _camera->position += glm::normalize(glm::cross(_camera->front, _camera->up)) * _speed; }


	//========鼠标操作========
	glm::vec2 cursorOffset = _camera->currentCursorPos - _camera->lastCursorPos;	//计算鼠标移动的值
	cursorOffset.y *= -1.0f;	//反转Y轴
	_camera->lastCursorPos = _camera->currentCursorPos;

	//设置视角灵敏度
	float sensitivity = 0.05f;
	cursorOffset *= sensitivity;

	//Camera的俯仰角和偏航角
	double yaw = 0.0f, pitch = 0.0f;
	glfwGetCursorPos(_window, &yaw, &pitch);
	yaw += cursorOffset.x;
	pitch += cursorOffset.y;

	//计算出方向向量
	glm::vec3 frontTemp;
	frontTemp.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
	frontTemp.y = sin(glm::radians(pitch));
	frontTemp.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	frontTemp = glm::normalize(frontTemp);
	//限制角度
	std::cout << frontTemp.x << "\t" << frontTemp.y << "\t" << frontTemp.z << "\n";

	_camera->front = frontTemp;
}

namespace OpenGLSamples::Based {

	bool GL_SceneRenderPass::init(Type::win_info_s& winInfo, GL_World& world)
	{
		windowHandle = (GLFWwindow*)winInfo.handle;

		this->worldObjects = &world;

		for (auto& item : *worldObjects->get())
		{
			if (!item.init()) {
				cout << "RenderObject init error!\n";
				return false;
			}

			//-----设置各种顶点Buffer-----
			glGenVertexArrays(1, &item.mesh.VAO);
			glGenBuffers(1, &item.mesh.VBO);
			glGenBuffers(1, &item.mesh.EBO);

			glBindVertexArray(item.mesh.VAO);

			//-----顶点数据-----
			glBindBuffer(GL_ARRAY_BUFFER, item.mesh.VBO);
			glBufferData(GL_ARRAY_BUFFER, item.mesh.vertexes.size() * sizeof(Type::Vertex), item.mesh.vertexes.data(), GL_STATIC_DRAW);

			//-----设置顶点数据-----
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Type::Vertex), (GLvoid*)0);
			glEnableVertexAttribArray(0);

			//-----设置贴图坐标数据-----
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Type::Vertex), (GLvoid*)(3 * sizeof(GLfloat)));
			glEnableVertexAttribArray(1);

			glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Type::Vertex), (GLvoid*)(5 * sizeof(GLfloat)));
			glEnableVertexAttribArray(2);

			//-----顶点索引数据-----
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, item.mesh.EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, item.mesh.indices.size() * sizeof(GLuint), item.mesh.indices.data(), GL_STATIC_DRAW);

			glEnableVertexAttribArray(0);

			glBindBuffer(GL_ARRAY_BUFFER, 0);

			glBindVertexArray(0);

			if (!item.texture.init()) {
				return false;
			}

			//设置贴图
			item.texture.use();
			item.shader.Use();
			item.shader.SetUniformValue(item.texture.handle, "texture01");
		}

		return true;
	}

	void GL_SceneRenderPass::render()
	{
		Camera* cameraTemp = worldObjects->getCamera();

		for (auto& item : *worldObjects->get()) {
			item.shader.Use();
			item.texture.use();

			glBindVertexArray(item.mesh.VAO);

			//记住！必须要先初始化矩阵为1，不然要出大问题
			glm::mat4 viewMat = glm::mat4(1.0f);
			glm::mat4 projectionMat = glm::mat4(1.0f);
			glm::mat4 modelMat = glm::mat4(1.0f);

			modelMat = glm::translate(modelMat, item.position);
			modelMat = glm::rotate(modelMat, glm::radians(item.rotationAngle), item.rotation);
			modelMat = glm::scale(modelMat, item.scaling);

			processCameraInput(windowHandle, cameraTemp);
			viewMat = glm::lookAt(cameraTemp->position, cameraTemp->position + cameraTemp->front, cameraTemp->up);
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
