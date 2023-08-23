#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace Puissance4Modulable {

	// State du splash screen
	class SplashState : public State
	{
	public:
		explicit SplashState(GameDataRef data);

		// Initialise le splash screen
		// Charge la texture et crée le sprite _background
		void Init() override;

		// Gère les events relatifs au splash screen
		void HandleInput();

		// Switch to main menu
		void Update(float dt);

		// Dessine la fênetre splash screen
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Clock _clock;

		sf::Sprite _background;
	};
}