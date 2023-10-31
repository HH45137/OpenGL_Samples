#include <format>

#include "GL_ImguiRenderPass.h"
#include "GL_App.h"

using namespace OpenGLSamples::Based;


ImGuiIO* io = NULL;

namespace OpenGLSamples::Based {

	Camera* cameraTemp = nullptr;	//��ʱ����Camera����

	bool GL_ImguiRenderPass::init(Type::win_info_s& winInfo, GL_World& world)
	{
		cameraTemp = world.getCamera();

		this->objects = &world.get();

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

		ImGui_ImplGlfw_InitForOpenGL((GLFWwindow*)winInfo.handle, true); //�ᱨ����������ΪGLFW�İ汾���⣿
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

			for (size_t i = 0; i < (*objects).size(); i++) {
				RendererObject& item = (*objects)[i];

				if (item.type == Type::OBJECT_TYPE::RENDER_OBJECT) {

					float* pos[3] = { &item.position.x,&item.position.y ,&item.position.z };
					float* rot[3] = { &item.rotation.x,&item.rotation.y ,&item.rotation.z };
					float* siz[3] = { &item.scaling.x,&item.scaling.y ,&item.scaling.z };

					std::string title = std::format("Object:{0} ", i);
					ImGui::Text(title.c_str());
					//λ��
					ImGui::SliderFloat3((title + "Position:").c_str(), *pos, -100.0f, 100.0f);
					//��ת
					ImGui::SliderFloat3((title + "Rotation axis:").c_str(), *rot, 0.0f, 1.0f);
					ImGui::SliderFloat((title + "Rotation angle:").c_str(), &item.rotationAngle, 0.0f, 360.0f);
					//����
					ImGui::SliderFloat((title + "Scaling:").c_str(), &item.scaling.x, -0.0f, 20.0f);
					item.scaling = glm::vec3(item.scaling.x);
				}
			}

			{
				float* pos[3] = { &cameraTemp->position.x,&cameraTemp->position.y ,&cameraTemp->position.z };
				float* rot[3] = { &cameraTemp->rotation.x,&cameraTemp->rotation.y ,&cameraTemp->rotation.z };

				std::string title = std::format("Camera:{0} ", 0);
				ImGui::Text(title.c_str());
				//λ��
				ImGui::SliderFloat3((title + "Position:").c_str(), *pos, -100.0f, 100.0f);
				//��ת
				ImGui::SliderFloat3((title + "Rotation axis:").c_str(), *rot, 0.0f, 1.0f);
				ImGui::SliderFloat((title + "Rotation angle:").c_str(), &cameraTemp->rotationAngle, 0.0f, 360.0f);
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