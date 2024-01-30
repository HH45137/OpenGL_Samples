#pragma once

#include "RendererObject.h"

namespace OpenGLSamples::Based {

	class RayTracingObject : public RendererObject
	{
	public:
		RayTracingObject(glm::vec3 _position, float _radius);
		RayTracingObject() = default;
		~RayTracingObject() = default;

		int render();

		int matrixUpdate();
		int setGLState();

	public:
		float radius;

	private:
		int choiceShaderType();
	};
}