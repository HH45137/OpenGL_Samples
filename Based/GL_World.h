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

		void set(std::string _meshName, std::string _textureName, std::string _vsName, std::string _fsName, glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scaling) {
			objects.push_back(std::shared_ptr<RendererObject>(new RendererObject(_meshName, _textureName, _vsName, _fsName, _position, _rotation, _scaling)));
		}

		void set(glm::vec3 _position, glm::vec3 _rotation, float _illumination) {
			lights.push_back(std::shared_ptr<LightObject>(new LightObject(_position, _rotation, _illumination)));
		}

		void set(glm::vec3 _position, glm::vec3 _rotation) {
			cameras.push_back(std::shared_ptr<Camera>(new Camera(_position, _rotation)));
		}

		auto getRenderObjects() {
			return objects;
		}
		auto getRenderObject(int index) {
			if (objects.size() >= index) {
				return objects[objects.size() - 1];
			}
			return objects[index];
		}

		auto getLightObjects() {
			return lights;
		}
		auto getLightObject(int index) {
			if (lights.size() >= index) {
				return lights[lights.size() - 1];
			}
			return lights[index];
		}

		auto getCamera() {
			return cameras;
		}

		void clear() {
			objects.clear();
			lights.clear();
			cameras.clear();
		}

	private:
		std::vector<std::shared_ptr<RendererObject>> objects;
		std::vector<std::shared_ptr<LightObject>> lights;
		std::vector<std::shared_ptr<Camera>> cameras;

	};

}