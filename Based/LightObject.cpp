#include "LightObject.h"
#include "Common.h"
#include "InputProcess.h"
#include "gl_App.h"

namespace OpenGLSamples::Based {

	LightObject::LightObject(glm::vec3 _position, glm::vec3 _rotation, float _illumination)
	{
		this->meshPath = MESHS_BASE_DIR + "light_model.obj";

		this->material = Material("light_color.png", "light_vs.glsl", "light_fs.glsl");

		this->position = _position;
		this->rotation = _rotation;
		this->scaling = glm::vec3(1.0);

		this->illumination = _illumination;

		this->type = Type::OBJECT_TYPE::LIGHT_OBJECT;
	}

	int LightObject::render()
	{
		glBindVertexArray(mesh.VAO);

		matrixUpdate();

		choiceShaderType();
		material.update();

		glDrawElements(GL_TRIANGLES, mesh.vertexCount, GL_UNSIGNED_INT, (GLvoid*)0);
		glBindVertexArray(0);

		return 0;
	}

	int LightObject::matrixUpdate()
	{
		viewMat = glm::mat4(1.0f);
		projectionMat = glm::mat4(1.0f);
		modelMat = glm::mat4(1.0f);

		modelMat = glm::translate(modelMat, position);
		modelMat = glm::rotate(modelMat, glm::radians(rotationAngle), rotation);
		modelMat = glm::scale(modelMat, scaling);

		auto camreaTemp = world.getCamera()[0];
		Input::InputProcess::processCameraInput((GLFWwindow*)winInfo.handle, camreaTemp);
		viewMat = glm::lookAt(camreaTemp->position, camreaTemp->position + camreaTemp->front, camreaTemp->up);
		projectionMat = glm::perspective((float)FOV, WIN_WIDTH / (float)WIN_HEIGHT, 0.1f, 1000.0f);

		material.shader->SetUniformValue(modelMat, "model");
		material.shader->SetUniformValue(viewMat, "view");
		material.shader->SetUniformValue(projectionMat, "projection");

		return 0;
	}

	int LightObject::setGLState()
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

		return 0;
	}

	int LightObject::choiceShaderType()
	{
		material.shader = new Shader();

		return 0;
	}
}