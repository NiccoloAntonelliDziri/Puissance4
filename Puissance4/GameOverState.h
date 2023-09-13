#pragma once

#include "State.h"
#include "Game.h"

namespace Puissance4Modulable
{
	class GameOverState : public State
	{
	public:
		GameOverState(GameDataRef data);

		void Init() override;

		void HandleInput() override;

		void Update(float dt) override;

		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _retryButton;
		sf::Sprite _homeButton;
		sf::Sprite _settings;
	};
}


