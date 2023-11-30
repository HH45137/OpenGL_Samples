#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/random.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Type.h"

namespace OpenGLSamples::Based {

	class Camera
	{
	public:
		Camera() = default;
		Camera(glm::vec3 _position, glm::vec3 _rotation);

		~Camera() = default;

	public:
		Type::OBJECT_TYPE type = Type::OBJECT_TYPE::CAMERA;

		float rotationAngle = 0;							//��ת�Ƕ�
		glm::vec3 position = glm::vec3(0.0f);				//λ��	
		glm::vec3 rotation = glm::vec3(0.0f, 1.0f, 0.0f);	//��ת

		glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);
		glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

		glm::vec2 lastCursorPos;	//��һ֡���������
		glm::vec2 currentCursorPos;	//��ǰ֡���������

	private:

	};

}
