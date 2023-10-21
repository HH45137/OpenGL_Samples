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
		mesh.filePath = meshPath;
		if (!mesh.init()) {
			cout << "Mesh init error!\n";
			return false;
		}

		texture.filePath = texturePath;
		if (!texture.init()) {
			cout << "Texture init error!\n";
			return false;
		}

		shader = Shader(vsPath, fsPath);
		if (shader.id == -1) {
			cout << "Shader init error!\n";
			return false;
		}

		return true;
	}

}

