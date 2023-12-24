#pragma once
#include "Camera.h"

using namespace OpenGLSamples::Based;

namespace OpenGLSamples {
	namespace Input {

		static bool isStopMouseInput = true;
		class InputProcess
		{
		public:
			InputProcess() = default;
			~InputProcess() = default;

			//处理摄像机相关的设备输入
			static void processCameraInput(GLFWwindow* _window, shared_ptr<Camera> _camera) {

				if (glfwGetKey(_window, GLFW_KEY_SPACE) == GLFW_TRUE) {
					isStopMouseInput = !isStopMouseInput;
				}
				if (isStopMouseInput) { return; }

				//========键盘操作========
				float _speed = 0.4;

				if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS) { _camera->position += _speed * _camera->front; }
				if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS) { _camera->position -= _speed * _camera->front; }

				if (glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS) { _camera->position -= glm::normalize(glm::cross(_camera->front, _camera->up)) * _speed; }
				if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS) { _camera->position += glm::normalize(glm::cross(_camera->front, _camera->up)) * _speed; }


				//========鼠标操作========
				glm::vec2 cursorOffset = _camera->currentCursorPos - _camera->lastCursorPos;	//计算鼠标移动的值
				cursorOffset.y *= -1.0f;	//反转Y轴
				_camera->lastCursorPos = _camera->currentCursorPos;

				//设置视角灵敏度
				float sensitivity = 0.01f;
				cursorOffset *= sensitivity;

				//Camera的俯仰角和偏航角
				double yaw = 0.0f, pitch = 0.0f;
				glfwGetCursorPos(_window, &yaw, &pitch);

				//限制角度
				if (pitch > 600.0f) { pitch = 600.0f; }
				if (pitch < 400.0f) { pitch = 400.0f; }
				//std::cout << pitch << "\t" << yaw << "\n";

				yaw += cursorOffset.x;
				pitch += cursorOffset.y;

				//计算出方向向量
				glm::vec3 frontTemp;
				frontTemp.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
				frontTemp.y = sin(glm::radians(pitch));
				frontTemp.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
				frontTemp = glm::normalize(frontTemp);

				_camera->front = frontTemp;
			}

		private:

		};
	}
}
