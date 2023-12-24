#include "GL_RenderPipeline.h"
#include "GL_SceneRenderPass.h"
#include "GL_ImguiRenderPass.h"


namespace OpenGLSamples::Based {

	bool GL_RenderPipeline::init(Type::win_info_s& winInfo, GL_World& world)
	{
		//������Pass
		auto scenePass = new GL_SceneRenderPass();
		if (!scenePass->init()) {
			return false;
		}
		renderPass.push_back(scenePass);

		////�����Pass
		//auto postPass = new GL_PostRenderPass();
		//postPass->init();
		//renderPass.push_back(postPass);

		auto imguiPass = new GL_ImguiRenderPass();
		if (!imguiPass->init()) {
			return false;
		}
		renderPass.push_back(imguiPass);

	}

	void GL_RenderPipeline::render()
	{
		for (size_t i = 0; i < renderPass.size(); i++) {
			renderPass[i]->render();
		}

	}

	void GL_RenderPipeline::close()
	{
		for (size_t i = 0; i < renderPass.size(); i++) {
			renderPass[i]->close();
		}

	}

}
