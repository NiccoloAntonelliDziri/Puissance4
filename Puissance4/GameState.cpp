#include "GameState.h"
#include "DEFINITIONS.h"

#include "PauseState.h"
#include "GameOverState.h"

#include <iostream>

namespace Puissance4Modulable {

	GameState::GameState(GameDataRef data) : _data(data)
	{

	}

	GameState::~GameState()
	{
		delete[] _gridCellPieces;
	}

	void GameState::Init()
	{
		gameState = STATE_PLAYING;
		turn = PLAYER_PIECE;

		this->_data->assets.LoadTexture("Pause Button", PAUSE_BUTTON);

		// On recharge pas la texture
		// Si besoin il faut load GAME_BACKGROUND_FILEPATH
		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));

		_pauseButton.setTexture(this->_data->assets.GetTexture("Pause Button"));

		// Centrage background CHANGE CA si on change de background
		this->_background.setPosition(SCREEN_WIDHT / 2 - this->_background.getGlobalBounds().width / 2,
			SCREEN_HEIGHT / 2 - this->_background.getGlobalBounds().height / 2);

		_pauseButton.setPosition(this->_data->window.getSize().x - _pauseButton.getGlobalBounds().width,
			_pauseButton.getPosition().y);
	}

	void GameState::HandleInput()
	{
		sf::Event event;
		while (this->_data->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				this->_data->window.close();
			}
			if (this->_data->input.IsSpriteClicked(this->_pauseButton, sf::Mouse::Left, this->_data->window))
			{
				// Go to Pause State
				this->_data->machine.AddState(StateRef(std::make_unique<PauseState>(_data)), false);
				
				// Game over State
				//this->_data->machine.AddState(StateRef(std::make_unique<GameOverState>(_data)), true);

			}
		}
	}

	void GameState::Update(float dt)
	{
	}

	void GameState::Draw(float dt)
	{
		this->_data->window.clear();

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_pauseButton);

		this->_data->window.display();
	}
}

