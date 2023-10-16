#include "GL_SceneRenderPass.h"
#include "RendererObject.h"
#include "gl_App.h"


namespace OpenGLSamples::Based {

	bool GL_SceneRenderPass::init()
	{
		RendererObject ro;
		ro.mesh = GL_Mesh("..\\assets\\CornellBox.obj");
		ro.texture = GL_Texture("..\\assets\\CornellBox_Color.png");
		ro.shader = Shader("..\\assets\\model_vs.glsl", "..\\assets\\model_fs.glsl");

		objects.push_back(ro);

		for (auto& item : objects)
		{
			item.position = glm::vec3(0.0f, 0.0f, 0.0f);
			item.rotation = glm::vec3(0.0f, 0.0f, 0.0f);
			item.scaling = glm::vec3(1.0f);

			if (!item.mesh.init()) {
				return false;
			}

			if (!item.texture.init()) {
				return false;
			}

			//设置贴图
			item.shader.Use();
			item.shader.SetUniformValue(item.texture.handle, "texture01");
		}
	}

	void GL_SceneRenderPass::render()
	{
		for (auto& item : objects) {
			item.shader.Use();
			item.texture.use();
			item.mesh.use();

			//记住！必须要先初始化矩阵为1，不然要出大问题
			glm::mat4 viewMat = glm::mat4(1.0f);
			glm::mat4 projectionMat = glm::mat4(1.0f);
			glm::mat4 modelMat = glm::mat4(1.0f);

			modelMat = glm::translate(modelMat, item.position);
			modelMat = glm::rotate(modelMat, glm::radians(0.0f), item.rotation);
			modelMat = glm::scale(modelMat, item.scaling);

			viewMat = glm::translate(viewMat, glm::vec3(0, 0, -10));
			projectionMat = glm::perspective((float)FOV, WIN_WIDTH / (float)WIN_HEIGHT, 0.1f, 1000.0f);

			item.shader.SetUniformValue(modelMat, "model");
			item.shader.SetUniformValue(viewMat, "view");
			item.shader.SetUniformValue(projectionMat, "projection");

			glDrawElements(GL_TRIANGLES, item.mesh.vertexCount, GL_UNSIGNED_INT, (GLvoid*)0);
			glBindVertexArray(0);
		}
	}

	void GL_SceneRenderPass::close()
	{

	}
}
