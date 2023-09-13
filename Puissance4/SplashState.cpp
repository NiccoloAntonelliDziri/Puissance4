#include <sstream>
#include "SplashState.h"
#include "DEFINITIONS.h"

#include "MainMenuState.h"

#include <iostream>

namespace Puissance4Modulable
{
	SplashState::SplashState(GameDataRef data) : _data(data)
	{
	}

	void SplashState::Init()
	{
		this->_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUD_FILEPATH);
		this->_data->assets.LoadTexture("Logo", SPLASH_SCREEN_LOGO_PATH);


		this->_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
		this->_logo.setTexture(this->_data->assets.GetTexture("Logo"));

		// Lisse la texture du logo pour l'aggrandissement
		this->_data->assets.SetTextureSmooth("Logo", true);

		// Taille du logo
		this->_logo.scale(2, 2);

		// Positionne le logo au centre de l'écran
		this->_logo.setPosition(SCREEN_WIDHT / 2 - this->_logo.getGlobalBounds().width / 2,
			SCREEN_HEIGHT / 2 - this->_logo.getGlobalBounds().height / 2);
	}

	void SplashState::HandleInput()
	{
		sf::Event event;
		while (this->_data->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				this->_data->window.close();
			}
		}
	}

	void SplashState::Update(float dt)
	{
		if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) {
			// Switch to main menu
			this->_data->machine.AddState(StateRef(std::make_unique<MainMenuState>(_data)),true);
		}
	}

	void SplashState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_logo);

		this->_data->window.display();
	}
}
