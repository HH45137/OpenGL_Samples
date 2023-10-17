#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_glfw.h"

#include "GL_ImguiRenderPass.h"
#include "GL_App.h"


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

		ImGui::StyleColorsDark();

		ImGui_ImplGlfw_InitForOpenGL(window, true); //�ᱨ����������ΪGLFW�İ汾���⣿
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