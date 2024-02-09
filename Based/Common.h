#pragma once
#include <iostream>
#include "Type.h"


namespace OpenGLSamples {
	namespace Based {
		const static std::string ASSETS_BASE_DIR = "..\\assets\\";
		const static std::string SHADER_BASE_DIR = ASSETS_BASE_DIR + "shaders\\";
		const static std::string MESHS_BASE_DIR = ASSETS_BASE_DIR + "meshs\\";
		const static std::string TEXTURE_BASE_DIR = ASSETS_BASE_DIR + "textures\\";

		extern Type::win_info_s winInfo;
	}
}