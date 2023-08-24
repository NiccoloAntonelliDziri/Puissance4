#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace Puissance4Modulable
{
	class MainMenuState : public State
	{
	public:
		MainMenuState(GameDataRef data);

		void Init() override;

		void HandleInput() override;

		void Update(float dt) override;

		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _playButton;
		sf::Sprite _title;
	};
}