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

		// Idem
		_pauseButton.setTexture(this->_data->assets.GetTexture("Pause Button"));

			// Centrage background CHANGE CA si on change de background
		this->_background.setPosition(SCREEN_WIDHT / 2 - this->_background.getGlobalBounds().width / 2,
			SCREEN_HEIGHT / 2 - this->_background.getGlobalBounds().height / 2);

		_pauseButton.setPosition(this->_data->window.getSize().x - _pauseButton.getGlobalBounds().width,
			_pauseButton.getPosition().y);

		_pos.x = SCREEN_WIDHT / 2 - TAILLE_BOUTONS_STANDARD * this->_data->jeu.getLargeur() / 2;
		_pos.y = SCREEN_HEIGHT/ 2 - TAILLE_BOUTONS_STANDARD * this->_data->jeu.getHauteur() / 2;

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
		DrawGrid();

		this->_data->window.display();
	}

	void GameState::InitGrid()
	{
		this->_grid = std::make_unique<sf::Sprite[]>(this->_data->jeu.getTaille());

		int topRight = this->_data->jeu.getTaille() - 1;
		int topLeft = this->_data->jeu.getHauteur() - 1;
		int bottomRight = this->_data->jeu.getTaille() - this->_data->jeu.getHauteur();
		int bottomLeft = 0;

		sf::Texture texture = this->_data->assets.GetTexture("Grid Sprites");

		// Bottom left corner
		this->_grid[bottomLeft].setTexture(this->_data->assets.GetTexture("Grid Sprites"));
		this->_grid[bottomLeft].setTextureRect(sf::IntRect(64 * 3, 0, 64, 64));

		// Bottom right corner
		this->_grid[bottomRight].setTexture(this->_data->assets.GetTexture("Grid Sprites"));
		this->_grid[bottomRight].setTextureRect(sf::IntRect(TAILLE_BOUTONS_STANDARD * 4, 0, TAILLE_BOUTONS_STANDARD, TAILLE_BOUTONS_STANDARD));

		// Top left corner
		this->_grid[topLeft].setTexture(this->_data->assets.GetTexture("Grid Sprites"));
		this->_grid[topLeft].setTextureRect(sf::IntRect(TAILLE_BOUTONS_STANDARD * 1, 0, TAILLE_BOUTONS_STANDARD, TAILLE_BOUTONS_STANDARD));

		// Top right corner
		this->_grid[topRight].setTexture(this->_data->assets.GetTexture("Grid Sprites"));
		this->_grid[topRight].setTextureRect(sf::IntRect(TAILLE_BOUTONS_STANDARD * 2, 0, TAILLE_BOUTONS_STANDARD, TAILLE_BOUTONS_STANDARD));

		for (int i = 0; i < this->_data->jeu.getTaille(); i++)
		{
			if (i != bottomLeft and i != bottomRight and i != topLeft and i != topRight)
			{
				this->_grid[i].setTexture(this->_data->assets.GetTexture("Grid Sprites"));
				this->_grid[i].setTextureRect(sf::IntRect(TAILLE_BOUTONS_STANDARD * 0, 0, TAILLE_BOUTONS_STANDARD, TAILLE_BOUTONS_STANDARD));
			}
		}
	}

	void GameState::DrawGrid()
	{
		sf::Vector2f position = _pos;
		for (int i = this->_data->jeu.getHauteur() - 1; i >= 0; i--)
		{
			for (int j = 0; j < this->_data->jeu.getLargeur(); j++)
			{
				int numCell = i + j * this->_data->jeu.getHauteur();

				this->_grid[numCell].setPosition(position);
				this->_data->window.draw(_grid[numCell]);

				position.x += TAILLE_BOUTONS_STANDARD;

			}
			position.x = _pos.x;
			position.y += TAILLE_BOUTONS_STANDARD;
		}
	}
}

