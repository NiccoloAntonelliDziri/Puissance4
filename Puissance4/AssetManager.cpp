#include "AssetManager.h"

namespace Puissance4Modulable
{
	void AssetManager::LoadTexture(std::string name, std::string fileName)
	{
		sf::Texture tex;
		if (tex.loadFromFile(fileName)) {
			this->_textures[name] = tex;
		}
	}

	sf::Texture& AssetManager::GetTexture(std::string name)
	{
		return this->_textures.at(name);
	}

	void AssetManager::SetTextureSmooth(std::string name, bool smooth)
	{
		this->_textures.at(name).setSmooth(smooth);
	}

	void AssetManager::LoadFont(std::string name, std::string fileName)
	{
		sf::Font font;
		if (font.loadFromFile(fileName)) {
			this->_fonts[name] = font;
		}
	}

	sf::Font& AssetManager::GetFont(std::string name)
	{
		return this->_fonts.at(name);
	}

	void AssetManager::LoadSound(std::string name, std::string fileName)
	{
		if (this->_soundBuffer[name].loadFromFile(fileName))
		{
			this->_sounds[name].setBuffer(this->_soundBuffer.at(name));
		}
	}

	void AssetManager::Play(std::string name)
	{
		this->_sounds[name].play();
	}
}