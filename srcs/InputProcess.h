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

			//�����������ص��豸����
			static void processCameraInput(GLFWwindow* _window, shared_ptr<Camera> _camera) {

				if (glfwGetKey(_window, GLFW_KEY_SPACE) == GLFW_TRUE) {
					isStopMouseInput = !isStopMouseInput;
				}
				if (isStopMouseInput) { return; }

				//========���̲���========
				float _speed = 0.4;

				if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS) { _camera->position += _speed * _camera->front; }
				if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS) { _camera->position -= _speed * _camera->front; }

				if (glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS) { _camera->position -= glm::normalize(glm::cross(_camera->front, _camera->up)) * _speed; }
				if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS) { _camera->position += glm::normalize(glm::cross(_camera->front, _camera->up)) * _speed; }


				//========������========
				glm::vec2 cursorOffset = _camera->currentCursorPos - _camera->lastCursorPos;	//��������ƶ���ֵ
				cursorOffset.y *= -1.0f;	//��תY��
				_camera->lastCursorPos = _camera->currentCursorPos;

				//�����ӽ�������
				float sensitivity = 0.01f;
				cursorOffset *= sensitivity;

				//Camera�ĸ����Ǻ�ƫ����
				double yaw = 0.0f, pitch = 0.0f;
				glfwGetCursorPos(_window, &yaw, &pitch);

				//���ƽǶ�
				if (pitch > 600.0f) { pitch = 600.0f; }
				if (pitch < 400.0f) { pitch = 400.0f; }
				//std::cout << pitch << "\t" << yaw << "\n";

				yaw += cursorOffset.x;
				pitch += cursorOffset.y;

				//�������������
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
