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
		float illumination;	//π‚’’«ø∂»

	private:
		int choiceShaderType();
	};
}