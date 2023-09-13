#pragma once

#include "State.h"
#include "Game.h"

namespace Puissance4Modulable
{
	class SettingsState : public State
	{
	public:
		SettingsState(GameDataRef data);

		void Init() override;

		void HandleInput() override;

		void Update(float dt) override;

		void Draw(float dt);

	private:

		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _resumeButton;
		sf::Sprite _homeButton;
		sf::Sprite _soundOnButton;
		sf::Sprite _soundOffButton;

		sf::Text _settingsStateTitle;
	};
}