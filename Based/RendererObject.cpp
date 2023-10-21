#include "RendererObject.h"
#include "gl_App.h"

namespace OpenGLSamples::Based {

	RendererObject::RendererObject(GL_Mesh _mesh, GL_Texture _texture, Shader _shader, glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scaling)
	{
		this->mesh = _mesh;
		this->texture = _texture;
		this->shader = _shader;

		this->position = _position;
		this->rotation = _rotation;
		this->scaling = _scaling;
	}

}

