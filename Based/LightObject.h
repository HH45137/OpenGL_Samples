#pragma once

#include "RendererObject.h"

namespace OpenGLSamples::Based {

	class LightObject : public RendererObject
	{
	public:
		LightObject(glm::vec3 _position, glm::vec3 _rotation, float _illumination);
		LightObject() = default;
		~LightObject() = default;

		int render();

		int matrixUpdate();
		int setGLState();

	public:
		float illumination;	//光照强度
		glm::vec3 color;

	private:
		int choiceShaderType();

		//记住！必须要先初始化矩阵为1，不然要出大问题
		glm::mat4 viewMat = glm::mat4(1.0f);
		glm::mat4 projectionMat = glm::mat4(1.0f);
		glm::mat4 modelMat = glm::mat4(1.0f);
	};
}