#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_glfw.h"

#include "GL_ImguiRenderPass.h"
#include "GL_App.h"


namespace OpenGLSamples::Based {

	bool GL_ImguiRenderPass::init()
	{
		/*-------------------设置Imgui-------------------*/
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		(void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

		ImGui::StyleColorsDark();

		//ImGui_ImplGlfw_InitForOpenGL(window, true); //会报错，或许是因为GLFW的版本问题？
		ImGui_ImplOpenGL3_Init();

		return true;
	}

	void GL_ImguiRenderPass::render()
	{

	}

	void GL_ImguiRenderPass::close()
	{

	}

}