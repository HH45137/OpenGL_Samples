#include <glad/glad.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include "GL_Texture.h"


namespace OpenGLSamples::Based {

	bool GL_Texture::init()
	{
		if (filePath.empty()) {
			std::cout << "Failed get texture" << std::endl;
			return false;
		}

		glGenTextures(1, &handle);
		glBindTexture(GL_TEXTURE_2D, handle);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		// set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int width, height, nrChannels;
		//stbi_set_flip_vertically_on_load(true);

		unsigned char* data = stbi_load(filePath.c_str(), &width, &height, &nrChannels, 0);
		if (data) {
			if (nrChannels == 3) {
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			}
			if (nrChannels == 4) {
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			}

			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			std::cout << "Failed to load texture" << std::endl;
			return false;
		}
		stbi_image_free(data);

		return true;
	}

	void GL_Texture::use()
	{
		glBindTexture(GL_TEXTURE_2D, handle);
	}

	void GL_Texture::close()
	{

	}

	GL_Texture::GL_Texture(std::string _path)
	{
		filePath = _path;
	}

	GL_Texture::GL_Texture()
	{
	}

	GL_Texture::~GL_Texture()
	{
	}

}
