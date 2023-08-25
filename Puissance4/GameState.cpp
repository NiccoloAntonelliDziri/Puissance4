#include "GameState.h"
#include "DEFINITIONS.h"

#include "PauseState.h"
#include "GameOverState.h"

#include "Plateau.h"

#include <iostream>

namespace Puissance4Modulable {

	GameState::GameState(GameDataRef data) : _data(data)
	{

	}

	GameState::~GameState()
	{
	}

	void GameState::Init()
	{
		gameState = STATE_PLAYING;
		turn = PLAYER_PIECE;

		this->_data->assets.LoadTexture("Pause Button", PAUSE_BUTTON);
		this->_data->assets.LoadTexture("Grid Sprites", GAME_GRID_TILES);
		this->_data->assets.LoadTexture("Red and yellow pieces", RED_AND_YELLOW_PIECES);

		// On recharge pas la texture
		// Si besoin il faut load GAME_BACKGROUND_FILEPATH
		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));

		_pauseButton.setTexture(this->_data->assets.GetTexture("Pause Button"));

			// Centrage background CHANGE CA si on change de background
		this->_background.setPosition(SCREEN_WIDHT / 2 - this->_background.getGlobalBounds().width / 2,
			SCREEN_HEIGHT / 2 - this->_background.getGlobalBounds().height / 2);

		_pauseButton.setPosition(this->_data->window.getSize().x - _pauseButton.getGlobalBounds().width,
			_pauseButton.getPosition().y);

		InitGrid();
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

		this->_data->window.draw(this->_gridEmpty[0]);

		this->_data->window.display();
	}

	void GameState::InitGrid()
	{
		this->_gridEmpty = std::make_unique<sf::Sprite[]>(this->_data->jeu.getTaille());
		int topRight = this->_data->jeu.getTaille() - 1;
		int topLeft = this->_data->jeu.getHauteur() - 1;
		int bottomRight = this->_data->jeu.getTaille() - this->_data->jeu.getHauteur();
		int bottomLeft = 0;

		// Bottom left corner
		this->_gridEmpty[bottomLeft].setTexture(this->_data->assets.GetTexture("Grid Sprites"));
		this->_gridEmpty[bottomLeft].setTextureRect(sf::IntRect(64 * 3, 0, 64, 64));

		// Bottom right corner
		this->_gridEmpty[bottomRight].setTexture(this->_data->assets.GetTexture("Grid Sprites"));
		this->_gridEmpty[bottomRight].setTextureRect(sf::IntRect(64 * 4, 0, 64, 64));

		// Top left corner
		this->_gridEmpty[topLeft].setTexture(this->_data->assets.GetTexture("Grid Sprites"));
		this->_gridEmpty[topLeft].setTextureRect(sf::IntRect(64 * 1, 0, 64, 64));

		// Top right corner
		this->_gridEmpty[topRight].setTexture(this->_data->assets.GetTexture("Grid Sprites"));
		this->_gridEmpty[topRight].setTextureRect(sf::IntRect(64 * 2, 0, 64, 64));

		for (int i = 0; i < _data->jeu.getTaille(); i++)
		{
			if (i != bottomLeft or i != bottomRight or i != topLeft or i != topRight)
			{
				this->_gridEmpty[i].setTexture(this->_data->assets.GetTexture("Grid Sprites"));
				this->_gridEmpty[i].setTextureRect(sf::IntRect(64 * 0, 0, 64, 64));
			}
		}

	}
}

