#include "GL_SceneRenderPass.h"
#include "RendererObject.h"
#include "gl_App.h"
#include "Common.h"

using namespace OpenGLSamples::Based;


namespace OpenGLSamples::Based {

	bool GL_SceneRenderPass::init()
	{
		//初始化普通模型
		for (auto item : world.getRenderObjects())
		{
			if (!item->init()) {
				cout << "RenderObject init error!\n";
				return false;
			}
		}

		//初始化灯光模型
		for (auto item : world.getLightObjects())
		{
			if (!item->init()) {
				cout << "LightObject init error!\n";
				return false;
			}
		}

		return true;
	}

	void GL_SceneRenderPass::render()
	{
		//渲染普通模型
		int roIndex = 0;
		for (auto item : world.getRenderObjects()) {
			item->render(roIndex);
			roIndex++;
		}

		//渲染灯光模型
		int loIndex = 0;
		for (auto item : world.getLightObjects()) {
			item->render(loIndex);
			loIndex++;
		}
	}

	void GL_SceneRenderPass::close()
	{

	}
}
