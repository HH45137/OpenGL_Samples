#pragma once

#include "GL_Mesh.h"
#include "GL_Texture.h"
#include "Shader.h"
#include "Type.h"
#include "Camera.h"
#include "Shader_Phong.h"


namespace OpenGLSamples::Based {

	class RendererObject
	{
	public:
		RendererObject(std::string _meshName, std::string _textureName, std::string _vsName, std::string _fsName, glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scaling);

		RendererObject() = default;
		~RendererObject() = default;

		bool init();
		int render(Type::win_info_s* _winInfo, Camera* _camera);

		int matrixUpdate(Type::win_info_s* _winInfo, Camera* _camera);
		int setGLState();

	public:
		Type::OBJECT_TYPE type = Type::OBJECT_TYPE::RENDER_OBJECT;

		std::string meshPath;
		std::string texturePath;
		std::string vsPath, fsPath;

		GL_Mesh mesh;
		GL_Texture texture;
		Shader_Phong* shader;

		float rotationAngle = 0;							//旋转角度
		glm::vec3 position = glm::vec3(0.0f);				//位置	
		glm::vec3 rotation = glm::vec3(0.0f, 1.0f, 0.0f);	//旋转
		glm::vec3 scaling = glm::vec3(1.0f);				//大小

	private:

	};

}
