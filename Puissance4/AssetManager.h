#pragma once

#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

namespace Puissance4Modulable
{
	// Classe qui gère les différentes ressources
	// Sauvegardés dans une std::map
	// Permet de load et d'accéder à la réfénce d'une texture déja existante
	// Assets gérés: Textures, Fonts
	class AssetManager
	{
	public:
		AssetManager() = default;
		~AssetManager() = default;

		// Charge une texture et la sauvegarde dans la map _textures
		// Prend le nom de la texture et le nom+path du fichier en arguments
		void LoadTexture(std::string name, std::string fileName);

		// Retourne une référence vers la texture
		sf::Texture& GetTexture(std::string name);

		// Lisse la texture name si smooth = true
		// Et desactive si smooth = false
		void SetTextureSmooth(std::string name, bool smooth);

		// Charge une font et la sauvegarde dans la map _fonts
		// Prend le nom de la font et le nom+path du fichier en arguments
		void LoadFont(std::string name, std::string fileName);

		// Retourne une référence vers la font
		sf::Font& GetFont(std::string name);

		// Charge un son et le sauvegarde dans la map _sounds
		// Prend le nom du son et le nom+path du fichier en arguments
		void LoadSound(std::string name, std::string fileName);

		// Joue le son name
		void Play(std::string name);

	private:
		// Prend le nom de la texture et y assigne la texture
		std::map<std::string, sf::Texture> _textures;
		// Prend le nom de la police d'écriture et y assigne la font
		std::map<std::string, sf::Font> _fonts;
		// Prend le nom du son et y assigne le son
		std::map<std::string, sf::SoundBuffer> _soundBuffer;

		std::map<std::string, sf::Sound> _sounds;
	};
}