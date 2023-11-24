#pragma once

#include "RendererObject.h"
#include "Camera.h"
#include "LightObject.h"


namespace OpenGLSamples::Based {

	class GL_World
	{
	public:
		GL_World() = default;
		~GL_World() = default;

		void set(RendererObject _object) {
			objects.push_back((void*)&_object);
		}

		void set(LightObject _object) {
			objects.push_back((void*)&_object);
		}

		void set(std::vector<void*>& _objects) {
			objects = _objects;
		}

		void set(Camera _camera) {
			camera = _camera;
		}

		std::vector<void*>* get() {
			return &objects;
		}

		Camera* getCamera() {
			return &camera;
		}

		void clear() {
			objects.clear();
		}

	private:
		std::vector<void*> objects;

		Camera camera;

	};

}