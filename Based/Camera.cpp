#include "Camera.h"


namespace OpenGLSamples::Based {

	Camera::Camera()
	{
		type = Type::OBJECT_TYPE::CAMERA;
	}

	Camera::Camera(glm::vec3 _position, glm::vec3 _rotation)
	{
		type = Type::OBJECT_TYPE::CAMERA;

		this->position = _position;
		this->rotation = _rotation;
	}

}
