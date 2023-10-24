#pragma once

#include "RendererObject.h"


namespace OpenGLSamples::Based {

	class Camera : public RendererObject
	{
	public:
		Camera();
		Camera(glm::vec3 _position, glm::vec3 _rotation);

		~Camera() = default;

	public:
		glm::vec3 front;
		glm::vec3 up;

	private:

	};

}
