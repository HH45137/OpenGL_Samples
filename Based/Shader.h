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

		//��ʼ����ɫ��
		void init(std::string _vertexSourceCodePath, std::string _fragmentSourceCodePath);

		//��ȡ��ɫ������
		std::string ReadShaderCode(const char* path);

		//�����ɫ�������Ƿ�ɹ�
		GLint ShaderIsCompile(GLint shader);

		//�����ɫ�������Ƿ�ɹ�
		GLint ShaderIsLink(GLint shaderProgram);

		//������ɫ��Uniformֵ Int32
		void SetUniformValue(GLint, const char* name);

		//������ɫ��Uniformֵ uint32
		void SetUniformValue(GLuint uintVal, const char* name);

		//������ɫ��Uniformֵ Float vec4
		void SetUniformValue(float x, float y, float z, float w, const char* name);
		void SetUniformValue(glm::fvec4 vec4, const char* name);

		//������ɫ��Uniformֵ mat4
		void SetUniformValue(glm::mat4 mat4Val, const char* name);

		//������ɫ��Uniformֵ vec3
		void SetUniformValue(glm::vec3 vec3Val, const char* name);

		//������ɫ��Uniformֵ Float
		void SetUniformValue(float fVal, const char* name);

		//ʹ����ɫ��
		void Use();

		//�ر���ɫ��
		void Close();

		virtual int inInit();
		virtual int inUpdate();

	private:

	};

}