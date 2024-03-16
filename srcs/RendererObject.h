#pragma once

#include "GL_Mesh.h"
#include "GL_Texture.h"
#include "Shader.h"
#include "Type.h"
#include "Camera.h"
#include "Shader_Phong.h"
#include "Material.h"


namespace OpenGLSamples::Based {

	class RendererObject
	{
	public:
		RendererObject(std::string _meshName, Material _material, glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scaling);

		RendererObject() = default;
		~RendererObject() = default;

		bool init();
		int render();

		int matrixUpdate();
		int setGLState();

	public:
		Type::OBJECT_TYPE type = Type::OBJECT_TYPE::RENDER_OBJECT;

		std::string meshPath;
		GL_Mesh mesh;

		Material material;

		float rotationAngle = 0;							//旋转角度
		glm::vec3 position = glm::vec3(0.0f);				//位置	
		glm::vec3 rotation = glm::vec3(0.0f, 1.0f, 0.0f);	//旋转
		glm::vec3 scaling = glm::vec3(1.0f);				//大小

	private:
		int choiceShaderType();

		//记住！必须要先初始化矩阵为1，不然要出大问题
		glm::mat4 viewMat = glm::mat4(1.0f);
		glm::mat4 projectionMat = glm::mat4(1.0f);
		glm::mat4 modelMat = glm::mat4(1.0f);
	};

}
