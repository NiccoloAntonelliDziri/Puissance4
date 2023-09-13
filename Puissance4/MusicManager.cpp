#include "MusicManager.h"

namespace Puissance4Modulable {

	MusicManager::MusicManager() 
	{
		_volume = 100;
		_isMusicMuted = false;
		_status = MusicStatus::DoesntExist;
	}

	void MusicManager::OpenMusic(std::string filePath)
	{
		if (!_gameMusic.openFromFile(filePath))
		{
			std::cout << "Erreur chargement musique" << std::endl;
		}
	}

	bool MusicManager::IsPlaying() const
	{
		if (_status == MusicStatus::Playing)
		{
			return true;
		}
		return false;
	}

	void MusicManager::Play()
	{
		_gameMusic.play();
		_status = MusicStatus::Playing;
	}

	void MusicManager::SetVolume(int volume)
	{
		_volume = volume;
		_gameMusic.setVolume(volume);
	}

	void MusicManager::Mute()
	{
		_gameMusic.setVolume(0);
		this->_isMusicMuted = true;
	}

	void MusicManager::DeMute()
	{
		_gameMusic.setVolume(_volume);
		this->_isMusicMuted = false;
	}

	bool MusicManager::IsMuted()
	{
		return this->_isMusicMuted;
	}

	void MusicManager::EnableLoop(bool enable)
	{
		_gameMusic.setLoop(enable);
	}
}
