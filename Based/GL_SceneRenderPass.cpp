#include "GL_SceneRenderPass.h"
#include "RendererObject.h"


namespace OpenGLSamples::Based {

	void GL_SceneRenderPass::init()
	{
		RendererObject ro;
		ro.init();

		objects.push_back(ro);
	}

	void GL_SceneRenderPass::render()
	{
		for (auto& item : objects) {
			item.render();
		}
	}

	void GL_SceneRenderPass::close()
	{

	}
}
