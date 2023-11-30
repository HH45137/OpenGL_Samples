#pragma once

#include "RendererObject.h"
#include "Camera.h"
#include "LightObject.h"
#include <any>


namespace OpenGLSamples::Based {

	class GL_World
	{
	public:
		GL_World() = default;
		~GL_World() = default;

		void set(RendererObject _object) {
			objects.push_back(_object);
		}

		void set(LightObject _light) {
			objects.push_back(_light);
		}

		void set(Camera _camera) {
			camera = _camera;
		}

		std::vector<RendererObject>* getRenderObjects() {
			return &objects;
		}

		std::vector<LightObject>* getLightObjects() {
			return &lights;
		}

		Camera* getCamera() {
			return &camera;
		}

		void clear() {
			objects.clear();
			lights.clear();
		}

	private:
		std::vector<RendererObject> objects;
		std::vector<LightObject> lights;

		Camera camera;

	};

}