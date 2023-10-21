#pragma once

#include "RendererObject.h"


namespace OpenGLSamples::Based {

	class GL_World
	{
	public:
		GL_World() = default;
		~GL_World() = default;

		void set(std::vector<RendererObject>& _objects) {
			objects = _objects;
		}

		std::vector<RendererObject>& get() {
			return objects;
		}

		void clear() {
			objects.clear();
		}

	private:
		std::vector<RendererObject> objects;

	};

}