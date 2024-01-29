#include <format>

#include "GL_ImguiRenderPass.h"
#include "GL_App.h"
#include "Common.h"

using namespace OpenGLSamples::Based;


ImGuiIO* io = NULL;

namespace OpenGLSamples::Based {

	bool GL_ImguiRenderPass::init()
	{
		/*-------------------����Imgui-------------------*/
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		io = &ImGui::GetIO();
		(void)io;
		(*io).ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		(*io).ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
		(*io).IniFilename = NULL;	//������ imgui.ini �ļ�

		ImGui::StyleColorsDark();

		if (winInfo.handle == nullptr) {
			cout << "window handle is nullptr!\n";
			return false;
		}

		ImGui_ImplGlfw_InitForOpenGL((GLFWwindow*)winInfo.handle, true);
		ImGui_ImplOpenGL3_Init();

		return true;
	}

	void GL_ImguiRenderPass::render()
	{
		//����ImGui֡
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		//ImGui Begin �� End
		{
			ImGui::Begin("Imgui window");

			ImGui::Text("This is some option");
			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / (*io).Framerate, (*io).Framerate);

			//��ͨ��Ⱦ�������
			int indexTempRO = 0;
			for (auto item : world.getRenderObjects()) {

				float* pos[3] = { &item->position.x,&item->position.y ,&item->position.z };
				float* rot[3] = { &item->rotation.x,&item->rotation.y ,&item->rotation.z };
				float* siz[3] = { &item->scaling.x,&item->scaling.y ,&item->scaling.z };

				std::string title = std::format("Object:{0} ", indexTempRO);
				ImGui::Text(title.c_str());
				//λ��
				ImGui::SliderFloat3((title + "Position:").c_str(), *pos, -100.0f, 100.0f);
				//��ת
				ImGui::SliderFloat3((title + "Rotation axis:").c_str(), *rot, 0.0f, 1.0f);
				ImGui::SliderFloat((title + "Rotation angle:").c_str(), &item->rotationAngle, 0.0f, 360.0f);
				//����
				ImGui::SliderFloat((title + "Scaling:").c_str(), &item->scaling.x, -0.0f, 20.0f);
				item->scaling = glm::vec3(item->scaling.x);

				indexTempRO++;
			}

			//�ƹ����
			int indexTempLO = 0;
			for (auto item : world.getLightObjects()) {

				float* pos[3] = { &item->position.x,&item->position.y ,&item->position.z };
				float* color[3] = { &item->color.r,&item->color.g ,&item->color.b };

				std::string title = std::format("Light:{0} ", indexTempLO);
				ImGui::Text(title.c_str());
				//λ��
				ImGui::SliderFloat3((title + "Position:").c_str(), *pos, -100.0f, 100.0f);
				//��ɫ
				ImGui::SliderFloat3((title + "Color:").c_str(), *color, 0.0f, 1.0f);

				indexTempLO++;
			}

			//Camera���
			int indexTempCO = 0;
			for (auto item : world.getCamera()) {
				float* pos[3] = { &item->position.x,&item->position.y ,&item->position.z };

				std::string title = std::format("Camera:{0} ", 0);
				ImGui::Text(title.c_str());
				//λ��
				ImGui::SliderFloat3((title + "Position:").c_str(), *pos, -100.0f, 100.0f);
			}

			ImGui::End();
		}

		//��ȾImgui
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void GL_ImguiRenderPass::close()
	{
		//�ر�ImGui
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

}