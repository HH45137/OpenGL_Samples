#include "LightObject.h"
#include "Common.h"
#include "InputProcess.h"
#include "gl_App.h"


OpenGLSamples::Based::LightObject::LightObject(glm::vec3 _position, glm::vec3 _rotation, float _illumination)
{
	this->meshPath = MESHS_BASE_DIR + "light_model.obj";
	this->texturePath = TEXTURE_BASE_DIR + "light_color.png";
	this->vsPath = SHADER_BASE_DIR + "light_vs.glsl";
	this->fsPath = SHADER_BASE_DIR + "light_fs.glsl";

	this->position = _position;
	this->rotation = _rotation;
	this->scaling = glm::vec3(1.0);

	this->illumination = _illumination;

	this->type = Type::OBJECT_TYPE::LIGHT_OBJECT;
}

int OpenGLSamples::Based::LightObject::render(Type::win_info_s* _winInfo, Camera* _camera)
{
	shader->Use();
	texture.use();

	glBindVertexArray(mesh.VAO);

	matrixUpdate(_winInfo, _camera);
	shader->inInit();

	glDrawElements(GL_TRIANGLES, mesh.vertexCount, GL_UNSIGNED_INT, (GLvoid*)0);
	glBindVertexArray(0);

	return 0;
}

int OpenGLSamples::Based::LightObject::matrixUpdate(Type::win_info_s* _winInfo, Camera* _camera)
{
	//记住！必须要先初始化矩阵为1，不然要出大问题
	glm::mat4 viewMat = glm::mat4(1.0f);
	glm::mat4 projectionMat = glm::mat4(1.0f);
	glm::mat4 modelMat = glm::mat4(1.0f);

	modelMat = glm::translate(modelMat, position);
	modelMat = glm::rotate(modelMat, glm::radians(rotationAngle), rotation);
	modelMat = glm::scale(modelMat, scaling);

	Input::InputProcess::processCameraInput((GLFWwindow*)_winInfo->handle, _camera);
	viewMat = glm::lookAt(_camera->position, _camera->position + _camera->front, _camera->up);
	projectionMat = glm::perspective((float)FOV, WIN_WIDTH / (float)WIN_HEIGHT, 0.1f, 1000.0f);

	shader->SetUniformValue(modelMat, "model");
	shader->SetUniformValue(viewMat, "view");
	shader->SetUniformValue(projectionMat, "projection");

	return 0;
}

int OpenGLSamples::Based::LightObject::setGLState()
{
	//-----设置各种顶点Buffer-----
	glGenVertexArrays(1, &mesh.VAO);
	glGenBuffers(1, &mesh.VBO);
	glGenBuffers(1, &mesh.EBO);

	glBindVertexArray(mesh.VAO);

	//-----顶点数据-----
	glBindBuffer(GL_ARRAY_BUFFER, mesh.VBO);
	glBufferData(GL_ARRAY_BUFFER, mesh.vertexes.size() * sizeof(Type::Vertex), mesh.vertexes.data(), GL_STATIC_DRAW);

	//-----设置顶点数据-----
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Type::Vertex), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	//-----设置贴图坐标数据-----
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Type::Vertex), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Type::Vertex), (GLvoid*)(5 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	//-----顶点索引数据-----
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.indices.size() * sizeof(GLuint), mesh.indices.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	if (!texture.init()) {
		return false;
	}

	//设置贴图
	texture.use();
	shader->Use();
	shader->SetUniformValue(texture.handle, "texture01");
	shader->inUpdate();

	return 0;
}
