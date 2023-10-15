#include "GL_Texture.h"


namespace OpenGLSamples::Based {

	bool GL_Texture::init()
	{


		return true;
	}

	void GL_Texture::use()
	{

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
