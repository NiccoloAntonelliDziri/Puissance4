#include "MusicManager.h"

namespace Puissance4Modulable {
	MusicManager::MusicManager()
	{
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

}
