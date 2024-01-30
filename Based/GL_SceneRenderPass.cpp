#include "GL_SceneRenderPass.h"
#include "RendererObject.h"
#include "gl_App.h"
#include "Common.h"

using namespace OpenGLSamples::Based;


namespace OpenGLSamples::Based {

	bool GL_SceneRenderPass::init()
	{
		//��ʼ����ͨģ��
		for (auto item : world.getRenderObjects())
		{
			if (!item->init()) {
				cout << "RenderObject init error!\n";
				return false;
			}
		}

		//��ʼ���ƹ�ģ��
		for (auto item : world.getLightObjects())
		{
			if (!item->init()) {
				cout << "LightObject init error!\n";
				return false;
			}
		}

		//��ʼ��RTģ��
		for (auto item : world.getRayTracingObjects())
		{
			if (!item->init()) {
				cout << "RayTracingObject init error!\n";
				return false;
			}
		}

		return true;
	}

	void GL_SceneRenderPass::render()
	{
		//��Ⱦ��ͨģ��
		for (auto item : world.getRenderObjects()) {
			item->render();
		}

		//��Ⱦ�ƹ�ģ��
		for (auto item : world.getLightObjects()) {
			item->render();
		}

		//��ȾRTģ��
		for (auto item : world.getRayTracingObjects()) {
			item->render();
		}
	}

	void GL_SceneRenderPass::close()
	{

	}
}
