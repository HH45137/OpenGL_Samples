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
			objects.push_back((std::any)&_object);
		}

		void set(LightObject _object) {
			objects.push_back((std::any)&_object);
		}

		void set(std::vector<std::any>& _objects) {
			objects = _objects;
		}

		void set(Camera _camera) {
			camera = _camera;
		}

		std::vector<std::any>* get() {
			return &objects;
		}

		Camera* getCamera() {
			return &camera;
		}

		void clear() {
			objects.clear();
		}

	private:
		std::vector<std::any> objects;

		Camera camera;

	};

}