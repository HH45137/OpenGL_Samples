#include "LightObject.h"

OpenGLSamples::Based::LightObject::LightObject(glm::vec3 _position, glm::vec3 _rotation, float _illumination)
{
	this->meshPath = "..\\assets\\light_model.obj";
	this->texturePath = "..\\assets\\light_color.png";
	this->vsPath = "..\\assets\\model_vs.glsl";
	this->fsPath = "..\\assets\\model_fs.glsl";

	this->position = _position;
	this->rotation = _rotation;
	this->scaling = glm::vec3(1.0);
}

int OpenGLSamples::Based::LightObject::shaderInit()
{


	return 0;
}

int OpenGLSamples::Based::LightObject::shaderUpdate()
{


	return 0;
}
