#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_glfw.h"

#include "GL_ImguiRenderPass.h"
#include "GL_App.h"


namespace OpenGLSamples::Based {

	bool GL_ImguiRenderPass::init()
	{
		/*-------------------…Ë÷√Imgui-------------------*/
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		(void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

		ImGui::StyleColorsDark();

		ImGui_ImplGlfw_InitForOpenGL(window, true);
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