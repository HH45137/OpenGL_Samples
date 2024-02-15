#include "Material.h"
#include "Shader_Phong.h"
#include "Common.h"


namespace OpenGLSamples::Based {

	Material::Material(std::string _textureName, std::string _vsName, std::string _fsName)
	{
		this->texturePath = TEXTURE_BASE_DIR + _textureName;
		this->vsPath = SHADER_BASE_DIR + _vsName;
		this->fsPath = SHADER_BASE_DIR + _fsName;
	}

	int Material::init()
	{
		texture.filePath = texturePath;
		if (!texture.init()) {
			cout << "Texture init error!\n";
			return false;
		}

		shader->init(vsPath, fsPath);
		if (shader->id == -1) {
			cout << "Shader init error!\n";
			return false;
		}

		return true;
	}

	int Material::update()
	{
		shader->Use();
		texture.use();

		shader->inUpdate();

		return 1;
	}

	int Material::clean()
	{
		texture.close();
		shader->Close();

		return 1;
	}

}
