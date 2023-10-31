#include "Camera.h"


namespace OpenGLSamples::Based {

	Camera::Camera(glm::vec3 _position, glm::vec3 _rotation)
	{
		type = Type::OBJECT_TYPE::CAMERA;

		this->position = _position;
		this->rotation = _rotation;

		glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);
		glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	}

}
