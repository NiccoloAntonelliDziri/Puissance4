#include "SelectState.h"
#include "DEFINITIONS.h"

#include "GameState.h"

#include <iostream>

namespace Puissance4Modulable {

	SelectState::SelectState(GameDataRef data) : _data(data)
	{
	}

	void SelectState::Init()
	{
		this->_data->assets.LoadTexture("7x6 Button", BUTTON_7_X_6);

		// On recharge pas la texture
		// Si besoin il faut load GAME_BACKGROUND_FILEPATH
		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));

		this->_7x6Button.setTexture(this->_data->assets.GetTexture("7x6 Button"));

		// Centrage background CHANGE CA si on change de background
		this->_background.setPosition(SCREEN_WIDHT / 2 - this->_background.getGlobalBounds().width / 2,
			SCREEN_HEIGHT / 2 - this->_background.getGlobalBounds().height / 2);

		// Positionne play button au centre
		this->_7x6Button.setPosition(SCREEN_WIDHT / 2 - this->_7x6Button.getGlobalBounds().width / 2,
			SCREEN_HEIGHT / 2 - this->_7x6Button.getGlobalBounds().height / 2);
	}

	void SelectState::HandleInput()
	{
		sf::Event event;
		while (this->_data->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				this->_data->window.close();
			}
			if (this->_data->input.IsSpriteClicked(this->_7x6Button, sf::Mouse::Left, this->_data->window))
			{
				InitPlateau(7, 6, 4);

				// Switch to game menu
				this->_data->machine.AddState(StateRef(std::make_unique<GameState>(_data)), true);
			}
		}
	}

	void SelectState::Update(float dt)
	{
	}

	void SelectState::Draw(float dt)
	{
		this->_data->window.clear();

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_7x6Button);

		this->_data->window.display();
	}

	void SelectState::InitPlateau(int largeur, int hauteur, int puissance)
	{
		this->_data->jeu = Plateau(largeur, hauteur, puissance);
	}
}
