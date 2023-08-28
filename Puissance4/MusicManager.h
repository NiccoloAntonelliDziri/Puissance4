#pragma once

#include <SFML/Audio.hpp>
#include <iostream>	

namespace Puissance4Modulable {

	enum class MusicStatus
	{
		DoesntExist,
		Stopped,
		Paused,
		Playing,
	};

	class MusicManager
	{
	public:
		MusicManager();
		~MusicManager() = default;

		void OpenMusic(std::string filePath);

		bool IsPlaying() const;

		void Play();

	private:
		sf::Music _gameMusic;

		MusicStatus _status;
	};
}