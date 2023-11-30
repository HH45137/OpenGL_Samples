#include "GL_SceneRenderPass.h"
#include "RendererObject.h"
#include "gl_App.h"

using namespace OpenGLSamples::Based;


namespace OpenGLSamples::Based {

	bool GL_SceneRenderPass::init(Type::win_info_s& winInfo, GL_World& world)
	{
		this->worldObjects = &world;
		this->winInfo = &winInfo;

		//初始化普通模型
		for (RendererObject& item : *worldObjects->getRenderObjects())
		{
			if (!item.init()) {
				cout << "RenderObject init error!\n";
				return false;
			}
		}

		return true;
	}

	void GL_SceneRenderPass::render()
	{
		//渲染普通模型
		for (RendererObject& item : *worldObjects->getRenderObjects()) {
			item.render(this->winInfo, this->worldObjects->getCamera());
		}
	}

	void GL_SceneRenderPass::close()
	{

	}
}
