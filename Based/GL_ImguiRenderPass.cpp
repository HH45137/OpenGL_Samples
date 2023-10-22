#include <format>

#include "GL_ImguiRenderPass.h"
#include "GL_App.h"


ImGuiIO* io = NULL;

namespace OpenGLSamples::Based {

	bool GL_ImguiRenderPass::init(Type::win_info_s& winInfo, GL_World& world)
	{
		this->objects = &world.get();

		/*-------------------设置Imgui-------------------*/
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		io = &ImGui::GetIO();
		(void)io;
		(*io).ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		(*io).ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

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

			for (size_t i = 0; i < (*objects).size(); i++) {
				RendererObject& item = (*objects)[i];

				float* pos[3] = { &item.position.x,&item.position.y ,&item.position.z };
				float* rot[3] = { &item.rotation.x,&item.rotation.y ,&item.rotation.z };
				float* siz[3] = { &item.scaling.x,&item.scaling.y ,&item.scaling.z };

				std::string title = std::format("Object:{0}", i);
				ImGui::Text(title.c_str());
				ImGui::SliderFloat3((title + "Position:").c_str(), *pos, -100.0f, 100.0f);
				ImGui::SliderFloat3((title + "Rotation axis:").c_str(), *rot, 0.0f, 1.0f);
				ImGui::SliderFloat((title + "Rotation angle:").c_str(), &item.rotationAngle, 0.0f, 360.0f);
				ImGui::SliderFloat3((title + "Scaling").c_str(), *siz, -0.0f, 20.0f);
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