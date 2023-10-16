#include "RendererObject.h"
#include "gl_App.h"

namespace OpenGLSamples::Based {

	bool RendererObject::init()
	{
		if (!mesh->init()) {
			return false;
		}

		if (!texture->init()) {
			return false;
		}

		return true;
	}

	void RendererObject::render()
	{
		shader.Use();
		texture->use();
		mesh->use();

		//记住！必须要先初始化矩阵为1，不然要出大问题
		glm::mat4 viewMat = glm::mat4(1.0f);
		glm::mat4 projectionMat = glm::mat4(1.0f);
		glm::mat4 modelMat = glm::mat4(1.0f);

		modelMat = glm::translate(modelMat, position);
		modelMat = glm::rotate(modelMat, glm::radians(0.0f), rotation);
		modelMat = glm::scale(modelMat, scaling);

		viewMat = glm::translate(viewMat, camera.position);
		projectionMat = glm::perspective((float)FOV, WIN_WIDTH / (float)WIN_HEIGHT, 0.1f, 1000.0f);
	}

	void RendererObject::close()
	{

	}

	RendererObject::RendererObject()
	{

	}

	RendererObject::~RendererObject()
	{

	}

}

