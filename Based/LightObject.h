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
		float illumination;	//����ǿ��
		glm::vec3 color;

	private:
		int choiceShaderType();

		//��ס������Ҫ�ȳ�ʼ������Ϊ1����ȻҪ��������
		glm::mat4 viewMat = glm::mat4(1.0f);
		glm::mat4 projectionMat = glm::mat4(1.0f);
		glm::mat4 modelMat = glm::mat4(1.0f);
	};
}