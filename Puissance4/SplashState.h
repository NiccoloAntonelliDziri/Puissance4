#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace Puissance4Modulable {

	// State du splash screen
	class SplashState : public State
	{
	public:
		SplashState(GameDataRef data);

		// Initialise le splash screen
		// Charge la texture et cr�e le sprite _background
		void Init() override;

		// G�re les events relatifs au splash screen
		void HandleInput() override;

		// Switch to main menu
		void Update(float dt) override;

		// Dessine la f�netre splash screen
		void Draw(float dt) override;

	private:
		GameDataRef _data;

		sf::Clock _clock;

		sf::Sprite _background;
		sf::Sprite _logo;
	};
}