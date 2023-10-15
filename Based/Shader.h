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
	};

	//读取着色器代码
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

	//检测着色器编译是否成功
	GLint Shader::ShaderIsCompile(GLint shader)
	{
		GLint success;	//是否成功编译
		GLchar infoLog[512];	//储存错误消息
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);	//检查是否编译成功
		if (!success) {
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cout << "Shader compile erro:" << infoLog << std::endl;
		}
		return success;
	}

	//检测着色器链接是否成功
	GLint Shader::ShaderIsLink(GLint shaderProgram)
	{
		GLint success;	//是否成功编译
		GLchar infoLog[512];	//储存错误消息
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);	//检查是否编译成功
		if (!success) {
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			std::cout << "Shader link erro:" << infoLog << std::endl;
		}
		return success;
	}

	Shader::Shader(std::string vertexSourceCodePath, std::string fragmentSourceCodePath)
	{
		//-----读取着色器-----
		std::string vertexShaderSource = ReadShaderCode(vertexSourceCodePath.c_str());
		std::string frgmentShaderSource = ReadShaderCode(fragmentSourceCodePath.c_str());
		const char* vertexShaderCode = vertexShaderSource.c_str();
		const char* frgmentShaderCode = frgmentShaderSource.c_str();

		//-----编译着色器-----
		GLint vertexShader, fagmentShader;
		//创建着色器
		fagmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		//附加源码到着色器
		glShaderSource(vertexShader, 1, &vertexShaderCode, NULL);
		glShaderSource(fagmentShader, 1, &frgmentShaderCode, NULL);
		//编译着色器
		glCompileShader(vertexShader);
		glCompileShader(fagmentShader);
		//检测着色器编译是否成功
		ShaderIsCompile(vertexShader);
		ShaderIsCompile(fagmentShader);

		//-------着色器程序-------
		//创建程序对象
		this->id = glCreateProgram();
		//将着色器附加到程序对象并链接
		glAttachShader(this->id, vertexShader);
		glAttachShader(this->id, fagmentShader);
		glLinkProgram(this->id);
		//检测着色器链接是否成功
		ShaderIsLink(this->id);
		//删除已经不需要的着色器对象
		glDeleteShader(vertexShader);
		glDeleteShader(fagmentShader);
	}

	Shader::Shader() {}

	//设置着色器Uniform值 Int32
	void Shader::SetUniformValue(GLint intVal, const char* name)
	{
		//查找uniform的位置
		GLint up = glGetUniformLocation(this->id, name);
		//设置值
		glUniform1i(up, intVal);
	}

	//设置着色器Uniform值 UInt32
	void Shader::SetUniformValue(GLuint uintVal, const char* name)
	{
		//查找uniform的位置
		GLint up = glGetUniformLocation(this->id, name);
		//设置值
		glUniform1ui(up, uintVal);
	}

	//设置着色器Uniform值 Float vec4
	void Shader::SetUniformValue(float x, float y, float z, float w, const char* name)
	{
		//查找uniform的位置
		GLint up = glGetUniformLocation(this->id, name);
		//设置值
		glUniform4f(up, x, y, z, w);
	}
	void Shader::SetUniformValue(glm::fvec4 vec4, const char* name)
	{
		//查找uniform的位置
		GLint up = glGetUniformLocation(this->id, name);
		//设置值
		glUniform4f(up, vec4.x, vec4.y, vec4.z, vec4.w);
	}

	//设置着色器Uniform值 mat4
	void Shader::SetUniformValue(glm::mat4 mat4Val, const char* name)
	{
		//查找uniform的位置
		GLint up = glGetUniformLocation(this->id, name);
		//设置值
		glUniformMatrix4fv(up, 1, GL_FALSE, glm::value_ptr(mat4Val));
	}

	//设置着色器Uniform值 vec3
	void Shader::SetUniformValue(glm::vec3 vec3Val, const char* name)
	{
		//查找uniform的位置
		GLint up = glGetUniformLocation(this->id, name);
		//设置值
		glUniform3f(up, vec3Val.x, vec3Val.y, vec3Val.z);
	}

	//设置着色器Uniform值 Float
	void Shader::SetUniformValue(float fVal, const char* name)
	{
		//查找uniform的位置
		GLint up = glGetUniformLocation(this->id, name);
		//设置值
		glUniform1f(up, fVal);
	}

	//使用着色器
	void Shader::Use()
	{
		glUseProgram(this->id);
	}

	//关闭着色器
	void Shader::Close()
	{
		glDeleteProgram(id);
	}

}