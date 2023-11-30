#include "LightObject.h"
#include "Common.h"

OpenGLSamples::Based::LightObject::LightObject(glm::vec3 _position, glm::vec3 _rotation, float _illumination)
{
	this->meshPath = MESHS_BASE_DIR + "light_model.obj";
	this->texturePath = TEXTURE_BASE_DIR + "light_color.png";
	this->vsPath = SHADER_BASE_DIR + "light_vs.glsl";
	this->fsPath = SHADER_BASE_DIR + "light_fs.glsl";

	this->position = _position;
	this->rotation = _rotation;
	this->scaling = glm::vec3(1.0);

	this->type = Type::OBJECT_TYPE::LIGHT_OBJECT;
}

int OpenGLSamples::Based::LightObject::shaderInit()
{


	return 0;
}

int OpenGLSamples::Based::LightObject::shaderUpdate()
{


	return 0;
}
