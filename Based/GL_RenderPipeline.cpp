#include "GL_RenderPipeline.h"
#include "GL_SceneRenderPass.h"


namespace OpenGLSamples::Based {

	void GL_RenderPipeline::init()
	{
		//场景的Pass
		auto scenePass = new GL_SceneRenderPass();
		scenePass->init();
		renderPass.push_back(scenePass);

		////后处理的Pass
		//auto postPass = new GL_PostRenderPass();
		//postPass->init();
		//renderPass.push_back(postPass);

	}

	void GL_RenderPipeline::render()
	{
		for (size_t i = 0; i < renderPass.size(); i++) {
			renderPass[i]->use();
		}

	}

	void GL_RenderPipeline::close()
	{
		for (size_t i = 0; i < renderPass.size(); i++) {
			renderPass[i]->close();
		}

	}

}
