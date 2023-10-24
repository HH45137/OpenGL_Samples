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

	private:

	};

}
