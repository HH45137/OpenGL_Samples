#include "RendererObject.h"
#include "gl_App.h"
#include "GL_SceneRenderPass.h"


using namespace OpenGLSamples::Based;

//�����������ص��豸����
void processCameraInput(GLFWwindow* _window, Camera* _camera) {

	if (glfwGetKey(_window, GLFW_KEY_SPACE) == GLFW_TRUE) {
		return;
	}

	//========���̲���========
	float _speed = 0.7;

	if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS) { _camera->position += _speed * _camera->front; }
	if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS) { _camera->position -= _speed * _camera->front; }

	if (glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS) { _camera->position -= glm::normalize(glm::cross(_camera->front, _camera->up)) * _speed; }
	if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS) { _camera->position += glm::normalize(glm::cross(_camera->front, _camera->up)) * _speed; }


	//========������========
	glm::vec2 cursorOffset = _camera->currentCursorPos - _camera->lastCursorPos;	//��������ƶ���ֵ
	cursorOffset.y *= -1.0f;	//��תY��
	_camera->lastCursorPos = _camera->currentCursorPos;

	//�����ӽ�������
	float sensitivity = 0.02f;
	cursorOffset *= sensitivity;

	//Camera�ĸ����Ǻ�ƫ����
	double yaw = 0.0f, pitch = 0.0f;
	glfwGetCursorPos(_window, &yaw, &pitch);

	//���ƽǶ�
	if (pitch > 600.0f) { pitch = 600.0f; }
	if (pitch < 400.0f) { pitch = 400.0f; }
	//std::cout << pitch << "\t" << yaw << "\n";

	yaw += cursorOffset.x;
	pitch += cursorOffset.y;

	//�������������
	glm::vec3 frontTemp;
	frontTemp.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
	frontTemp.y = sin(glm::radians(pitch));
	frontTemp.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	frontTemp = glm::normalize(frontTemp);

	_camera->front = frontTemp;
}

namespace OpenGLSamples::Based {

	RendererObject::RendererObject(std::string _meshPath, std::string _texturePath, std::string _vsPath, std::string _fsPath, glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scaling)
	{
		this->meshPath = _meshPath;
		this->texturePath = _texturePath;
		this->vsPath = _vsPath;
		this->fsPath = _fsPath;

		this->position = _position;
		this->rotation = _rotation;
		this->scaling = _scaling;
	}

	bool RendererObject::init()
	{
		mesh.filePath = meshPath;
		if (!mesh.init()) {
			cout << "Mesh init error!\n";
			return false;
		}

		texture.filePath = texturePath;
		if (!texture.init()) {
			cout << "Texture init error!\n";
			return false;
		}

		shader = Shader(vsPath, fsPath);
		if (shader.id == -1) {
			cout << "Shader init error!\n";
			return false;
		}


		//-----���ø��ֶ���Buffer-----
		glGenVertexArrays(1, &mesh.VAO);
		glGenBuffers(1, &mesh.VBO);
		glGenBuffers(1, &mesh.EBO);

		glBindVertexArray(mesh.VAO);

		//-----��������-----
		glBindBuffer(GL_ARRAY_BUFFER, mesh.VBO);
		glBufferData(GL_ARRAY_BUFFER, mesh.vertexes.size() * sizeof(Type::Vertex), mesh.vertexes.data(), GL_STATIC_DRAW);

		//-----���ö�������-----
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Type::Vertex), (GLvoid*)0);
		glEnableVertexAttribArray(0);

		//-----������ͼ��������-----
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Type::Vertex), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);

		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Type::Vertex), (GLvoid*)(5 * sizeof(GLfloat)));
		glEnableVertexAttribArray(2);

		//-----������������-----
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.indices.size() * sizeof(GLuint), mesh.indices.data(), GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(0);

		if (!texture.init()) {
			return false;
		}

		//������ͼ
		texture.use();
		shader.Use();
		shader.SetUniformValue(texture.handle, "texture01");
		shaderInit();

		return true;
	}

	int RendererObject::render(Type::win_info_s& winInfo, Camera* _camera)
	{
		shader.Use();
		texture.use();

		glBindVertexArray(mesh.VAO);

		matrixUpdate(winInfo, _camera);
		shaderUpdate();

		glDrawElements(GL_TRIANGLES, mesh.vertexCount, GL_UNSIGNED_INT, (GLvoid*)0);
		glBindVertexArray(0);

		return 0;
	}

	int RendererObject::shaderInit()
	{


		return 0;
	}

	int RendererObject::shaderUpdate()
	{


		return 0;
	}

	int RendererObject::matrixUpdate(Type::win_info_s& winInfo, Camera* _camera)
	{
		//��ס������Ҫ�ȳ�ʼ������Ϊ1����ȻҪ��������
		glm::mat4 viewMat = glm::mat4(1.0f);
		glm::mat4 projectionMat = glm::mat4(1.0f);
		glm::mat4 modelMat = glm::mat4(1.0f);

		modelMat = glm::translate(modelMat, position);
		modelMat = glm::rotate(modelMat, glm::radians(rotationAngle), rotation);
		modelMat = glm::scale(modelMat, scaling);

		processCameraInput((GLFWwindow*)winInfo.handle, _camera);
		viewMat = glm::lookAt(_camera->position, _camera->position + _camera->front, _camera->up);
		projectionMat = glm::perspective((float)FOV, WIN_WIDTH / (float)WIN_HEIGHT, 0.1f, 1000.0f);

		shader.SetUniformValue(modelMat, "model");
		shader.SetUniformValue(viewMat, "view");
		shader.SetUniformValue(projectionMat, "projection");

		return 0;
	}

}

