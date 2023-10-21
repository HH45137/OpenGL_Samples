#include "RendererObject.h"
#include "gl_App.h"

namespace OpenGLSamples::Based {

	RendererObject::RendererObject(std::string _meshPath, std::string _texturePath, std::string _vsPath, std::string _fsPath, glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scaling)
	{
		this->meshPath = _meshPath;
		this->texturePath = _texturePath;
		this->vsPath = _vsPath;
		this->fsPath = _fsPath;

		this->position = _position;
		this->rotation = _rotation;
		this->scaling = _scaling;
	}

	bool RendererObject::init()
	{
		if (!mesh.init()) {
			return false;
		}

		if (!texture.init()) {
			return false;
		}

		if (!shader.init()) {
			return false;
		}

		return true;
	}

}

