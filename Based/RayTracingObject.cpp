#include "RayTracingObject.h"
#include "Common.h"
#include "InputProcess.h"
#include "gl_App.h"
#include "Shader_PT.h"


OpenGLSamples::Based::RayTracingObject::RayTracingObject(glm::vec3 _position, float _radius)
{
	this->meshPath = MESHS_BASE_DIR + "light_model.obj";
	this->texturePath = TEXTURE_BASE_DIR + "light_color.png";
	this->vsPath = SHADER_BASE_DIR + "pathtracing_vs.glsl";
	this->fsPath = SHADER_BASE_DIR + "pathtracing_fs.glsl";

	this->position = _position;
	this->rotation = glm::vec3(1.0);
	this->scaling = glm::vec3(1.0);

	this->radius = _radius;

	this->type = Type::OBJECT_TYPE::RAYTRACING_OBJECT;
}

int OpenGLSamples::Based::RayTracingObject::render()
{
	shader->Use();
	texture.use();

	glBindVertexArray(mesh.VAO);

	matrixUpdate();
	shader->inUpdate();

	glDrawElements(GL_TRIANGLES, mesh.vertexCount, GL_UNSIGNED_INT, (GLvoid*)0);
	glBindVertexArray(0);

	return 0;
}

int OpenGLSamples::Based::RayTracingObject::matrixUpdate()
{
	//��ס������Ҫ�ȳ�ʼ������Ϊ1����ȻҪ��������
	glm::mat4 viewMat = glm::mat4(1.0f);
	glm::mat4 projectionMat = glm::mat4(1.0f);
	glm::mat4 modelMat = glm::mat4(1.0f);

	modelMat = glm::translate(modelMat, position);
	modelMat = glm::rotate(modelMat, glm::radians(rotationAngle), rotation);
	modelMat = glm::scale(modelMat, scaling);

	auto camreaTemp = world.getCamera()[0];
	Input::InputProcess::processCameraInput((GLFWwindow*)winInfo.handle, camreaTemp);
	viewMat = glm::lookAt(camreaTemp->position, camreaTemp->position + camreaTemp->front, camreaTemp->up);
	projectionMat = glm::perspective((float)FOV, WIN_WIDTH / (float)WIN_HEIGHT, 0.1f, 1000.0f);

	shader->SetUniformValue(modelMat, "model");
	shader->SetUniformValue(viewMat, "view");
	shader->SetUniformValue(projectionMat, "projection");

	return 0;
}

int OpenGLSamples::Based::RayTracingObject::setGLState()
{
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
	shader->Use();
	shader->SetUniformValue(texture.handle, "texture01");

	return 0;
}

int OpenGLSamples::Based::RayTracingObject::choiceShaderType()
{
	shader = new Shader_PT();

	return 0;
}