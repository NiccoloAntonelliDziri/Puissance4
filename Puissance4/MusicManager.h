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

		// Valeur volume entre 0 et 100
		// (100 par défaut quand la musique play on peut que le baisser)
		void SetVolume(int volume);

		// Met le volume du son à zéro
		void Mute();

		// Met le volume du son à sa valeur définie
		void DeMute();

		// Si enable == true met la musique en loop mode
		// Si false le disactive
		void EnableLoop(bool enable);

	private:
		sf::Music _gameMusic;
		int _volume;

		MusicStatus _status;
	};
}