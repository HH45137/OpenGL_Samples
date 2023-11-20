#pragma once

#include "RendererObject.h"


namespace OpenGLSamples::Based {

	class Camera
	{
	public:
		Camera() = default;
		Camera(glm::vec3 _position, glm::vec3 _rotation);

		~Camera() = default;

	public:
		Type::OBJECT_TYPE type = Type::OBJECT_TYPE::CAMERA;

		float rotationAngle = 0;							//旋转角度
		glm::vec3 position = glm::vec3(0.0f);				//位置	
		glm::vec3 rotation = glm::vec3(0.0f, 1.0f, 0.0f);	//旋转

		glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);
		glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

		glm::vec2 lastCursorPos;	//上一帧的鼠标坐标
		glm::vec2 currentCursorPos;	//当前帧的鼠标坐标

	private:

	};

}
