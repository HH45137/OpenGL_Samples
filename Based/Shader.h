#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/random.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

namespace OpenGLSamples::Based {

	class Shader
	{
	public:
		GLint id = -1;

	private:

	public:
		Shader();

		//初始化着色器
		void init(std::string _vertexSourceCodePath, std::string _fragmentSourceCodePath);

		//读取着色器代码
		std::string ReadShaderCode(const char* path);

		//检测着色器编译是否成功
		GLint ShaderIsCompile(GLint shader);

		//检测着色器链接是否成功
		GLint ShaderIsLink(GLint shaderProgram);

		//设置着色器Uniform值 Int32
		void SetUniformValue(GLint, const char* name);

		//设置着色器Uniform值 uint32
		void SetUniformValue(GLuint uintVal, const char* name);

		//设置着色器Uniform值 Float vec4
		void SetUniformValue(float x, float y, float z, float w, const char* name);
		void SetUniformValue(glm::fvec4 vec4, const char* name);

		//设置着色器Uniform值 mat4
		void SetUniformValue(glm::mat4 mat4Val, const char* name);

		//设置着色器Uniform值 vec3
		void SetUniformValue(glm::vec3 vec3Val, const char* name);

		//设置着色器Uniform值 Float
		void SetUniformValue(float fVal, const char* name);

		//使用着色器
		void Use();

		//关闭着色器
		void Close();

		virtual int inInit();
		virtual int inUpdate();

	private:

	};

}