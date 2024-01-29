#include "RendererObject.h"
#include "gl_App.h"
#include "GL_SceneRenderPass.h"
#include "InputProcess.h"
#include "Common.h"
#include "Shader_Phong.h"

using namespace OpenGLSamples::Based;

namespace OpenGLSamples::Based {

	RendererObject::RendererObject(std::string _meshName, std::string _textureName, std::string _vsName, std::string _fsName, glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scaling)
	{
		this->meshPath = MESHS_BASE_DIR + _meshName;
		this->texturePath = TEXTURE_BASE_DIR + _textureName;
		this->vsPath = SHADER_BASE_DIR + _vsName;
		this->fsPath = SHADER_BASE_DIR + _fsName;

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

		choiceShaderType();
		shader->init(vsPath, fsPath);
		if (shader->id == -1) {
			cout << "Shader init error!\n";
			return false;
		}

		setGLState();

		return true;
	}

	int RendererObject::render()
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

	int RendererObject::matrixUpdate()
	{
		//记住！必须要先初始化矩阵为1，不然要出大问题
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

	int RendererObject::setGLState()
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

		return 0;
	}

	int RendererObject::choiceShaderType()
	{
		shader = new Shader_Phong();

		return 0;
	}

}

