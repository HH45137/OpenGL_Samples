#include <format>

#include "GL_ImguiRenderPass.h"
#include "GL_App.h"

using namespace OpenGLSamples::Based;


ImGuiIO* io = NULL;

namespace OpenGLSamples::Based {

	bool GL_ImguiRenderPass::init(Type::win_info_s& winInfo, GL_World& world)
	{
		this->worldObjects = &world;

		/*-------------------设置Imgui-------------------*/
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		io = &ImGui::GetIO();
		(void)io;
		(*io).ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		(*io).ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
		(*io).IniFilename = NULL;	//不保存 imgui.ini 文件

		ImGui::StyleColorsDark();

		if (winInfo.handle == nullptr) {
			cout << "window handle is nullptr!\n";
			return false;
		}

		ImGui_ImplGlfw_InitForOpenGL((GLFWwindow*)winInfo.handle, true); //会报错，或许是因为GLFW的版本问题？
		ImGui_ImplOpenGL3_Init();

		return true;
	}

	void GL_ImguiRenderPass::render()
	{
		//启动ImGui帧
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		//ImGui Begin 到 End
		{
			ImGui::Begin("Imgui window");

			ImGui::Text("This is some option");
			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / (*io).Framerate, (*io).Framerate);

			int indexTemp = 0;
			for (auto& item : *worldObjects->getRenderObjects()) {
				RendererObject* renderObjItem = &item;

				if (renderObjItem->type == Type::OBJECT_TYPE::RENDER_OBJECT) {

					float* pos[3] = { &renderObjItem->position.x,&renderObjItem->position.y ,&renderObjItem->position.z };
					float* rot[3] = { &renderObjItem->rotation.x,&renderObjItem->rotation.y ,&renderObjItem->rotation.z };
					float* siz[3] = { &renderObjItem->scaling.x,&renderObjItem->scaling.y ,&renderObjItem->scaling.z };

					std::string title = std::format("Object:{0} ", indexTemp);
					ImGui::Text(title.c_str());
					//位置
					ImGui::SliderFloat3((title + "Position:").c_str(), *pos, -100.0f, 100.0f);
					//旋转
					ImGui::SliderFloat3((title + "Rotation axis:").c_str(), *rot, 0.0f, 1.0f);
					ImGui::SliderFloat((title + "Rotation angle:").c_str(), &renderObjItem->rotationAngle, 0.0f, 360.0f);
					//缩放
					ImGui::SliderFloat((title + "Scaling:").c_str(), &renderObjItem->scaling.x, -0.0f, 20.0f);
					renderObjItem->scaling = glm::vec3(renderObjItem->scaling.x);
				}
				indexTemp++;
			}

			{
				Camera* cameraTemp = worldObjects->getCamera();
				float* pos[3] = { &cameraTemp->position.x,&cameraTemp->position.y ,&cameraTemp->position.z };
				float* rot[3] = { &cameraTemp->rotation.x,&cameraTemp->rotation.y ,&cameraTemp->rotation.z };

				std::string title = std::format("Camera:{0} ", 0);
				ImGui::Text(title.c_str());
				//位置
				ImGui::SliderFloat3((title + "Position:").c_str(), *pos, -100.0f, 100.0f);
				//旋转
				ImGui::SliderFloat3((title + "Rotation axis:").c_str(), *rot, 0.0f, 1.0f);
				ImGui::SliderFloat((title + "Rotation angle:").c_str(), &cameraTemp->rotationAngle, 0.0f, 360.0f);
			}

			ImGui::End();
		}

		//渲染Imgui
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void GL_ImguiRenderPass::close()
	{
		//关闭ImGui
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

}