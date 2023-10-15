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
		GLint id = 0;

	public:
		Shader(std::string vertexSourceCodePath, std::string fragmentSourceCodePath);

		Shader();

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
	};

	//��ȡ��ɫ������
	std::string Shader::ReadShaderCode(const char* path)
	{
		std::string ret;
		std::ifstream fs;
		std::stringstream buf;
		fs.open(path);
		if (fs.is_open()) {
			buf << fs.rdbuf();
			ret = buf.str();
		}
		else {
			printf("Read shader source code erro");
		}
		fs.close();
		return ret;
	}

	//�����ɫ�������Ƿ�ɹ�
	GLint Shader::ShaderIsCompile(GLint shader)
	{
		GLint success;	//�Ƿ�ɹ�����
		GLchar infoLog[512];	//���������Ϣ
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);	//����Ƿ����ɹ�
		if (!success) {
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cout << "Shader compile erro:" << infoLog << std::endl;
		}
		return success;
	}

	//�����ɫ�������Ƿ�ɹ�
	GLint Shader::ShaderIsLink(GLint shaderProgram)
	{
		GLint success;	//�Ƿ�ɹ�����
		GLchar infoLog[512];	//���������Ϣ
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);	//����Ƿ����ɹ�
		if (!success) {
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			std::cout << "Shader link erro:" << infoLog << std::endl;
		}
		return success;
	}

	Shader::Shader(std::string vertexSourceCodePath, std::string fragmentSourceCodePath)
	{
		//-----��ȡ��ɫ��-----
		std::string vertexShaderSource = ReadShaderCode(vertexSourceCodePath.c_str());
		std::string frgmentShaderSource = ReadShaderCode(fragmentSourceCodePath.c_str());
		const char* vertexShaderCode = vertexShaderSource.c_str();
		const char* frgmentShaderCode = frgmentShaderSource.c_str();

		//-----������ɫ��-----
		GLint vertexShader, fagmentShader;
		//������ɫ��
		fagmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		//����Դ�뵽��ɫ��
		glShaderSource(vertexShader, 1, &vertexShaderCode, NULL);
		glShaderSource(fagmentShader, 1, &frgmentShaderCode, NULL);
		//������ɫ��
		glCompileShader(vertexShader);
		glCompileShader(fagmentShader);
		//�����ɫ�������Ƿ�ɹ�
		ShaderIsCompile(vertexShader);
		ShaderIsCompile(fagmentShader);

		//-------��ɫ������-------
		//�����������
		this->id = glCreateProgram();
		//����ɫ�����ӵ������������
		glAttachShader(this->id, vertexShader);
		glAttachShader(this->id, fagmentShader);
		glLinkProgram(this->id);
		//�����ɫ�������Ƿ�ɹ�
		ShaderIsLink(this->id);
		//ɾ���Ѿ�����Ҫ����ɫ������
		glDeleteShader(vertexShader);
		glDeleteShader(fagmentShader);
	}

	Shader::Shader() {}

	//������ɫ��Uniformֵ Int32
	void Shader::SetUniformValue(GLint intVal, const char* name)
	{
		//����uniform��λ��
		GLint up = glGetUniformLocation(this->id, name);
		//����ֵ
		glUniform1i(up, intVal);
	}

	//������ɫ��Uniformֵ UInt32
	void Shader::SetUniformValue(GLuint uintVal, const char* name)
	{
		//����uniform��λ��
		GLint up = glGetUniformLocation(this->id, name);
		//����ֵ
		glUniform1ui(up, uintVal);
	}

	//������ɫ��Uniformֵ Float vec4
	void Shader::SetUniformValue(float x, float y, float z, float w, const char* name)
	{
		//����uniform��λ��
		GLint up = glGetUniformLocation(this->id, name);
		//����ֵ
		glUniform4f(up, x, y, z, w);
	}
	void Shader::SetUniformValue(glm::fvec4 vec4, const char* name)
	{
		//����uniform��λ��
		GLint up = glGetUniformLocation(this->id, name);
		//����ֵ
		glUniform4f(up, vec4.x, vec4.y, vec4.z, vec4.w);
	}

	//������ɫ��Uniformֵ mat4
	void Shader::SetUniformValue(glm::mat4 mat4Val, const char* name)
	{
		//����uniform��λ��
		GLint up = glGetUniformLocation(this->id, name);
		//����ֵ
		glUniformMatrix4fv(up, 1, GL_FALSE, glm::value_ptr(mat4Val));
	}

	//������ɫ��Uniformֵ vec3
	void Shader::SetUniformValue(glm::vec3 vec3Val, const char* name)
	{
		//����uniform��λ��
		GLint up = glGetUniformLocation(this->id, name);
		//����ֵ
		glUniform3f(up, vec3Val.x, vec3Val.y, vec3Val.z);
	}

	//������ɫ��Uniformֵ Float
	void Shader::SetUniformValue(float fVal, const char* name)
	{
		//����uniform��λ��
		GLint up = glGetUniformLocation(this->id, name);
		//����ֵ
		glUniform1f(up, fVal);
	}

	//ʹ����ɫ��
	void Shader::Use()
	{
		glUseProgram(this->id);
	}

	//�ر���ɫ��
	void Shader::Close()
	{
		glDeleteProgram(id);
	}

}