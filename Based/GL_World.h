#pragma once

#include "RendererObject.h"
#include "Camera.h"


namespace OpenGLSamples::Based {

	class GL_World
	{
	public:
		GL_World() = default;
		~GL_World() = default;

		void set(RendererObject _object) {
			objects.push_back(_object);
		}

		void set(std::vector<RendererObject>& _objects) {
			objects = _objects;
		}

		void set(Camera _camera) {
			camera = _camera;
		}

		std::vector<RendererObject>* get() {
			return &objects;
		}

		Camera* getCamera() {
			return &camera;
		}

		void clear() {
			objects.clear();
		}

	private:
		std::vector<RendererObject> objects;

		Camera camera;

	};

}