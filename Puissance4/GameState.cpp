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

		_gameOverText.setFont(this->_data->assets.GetFont("ChakrPetch Bold"));
		//_gameOverText.setStyle(sf::Text::Bold);
		_gameOverText.setFillColor(sf::Color(255, 0, 0, 220));
		_gameOverText.setOutlineThickness(3);
		_gameOverText.setOutlineColor(sf::Color(0, 0, 0, 220));
		_gameOverText.setLetterSpacing(1.5);
		_gameOverText.setCharacterSize(120);


			// Centrage background CHANGE CA si on change de background
		this->_background.setPosition(SCREEN_WIDHT / 2 - this->_background.getGlobalBounds().width / 2,
			SCREEN_HEIGHT / 2 - this->_background.getGlobalBounds().height / 2);

		_pauseButton.setPosition(this->_data->window.getSize().x - _pauseButton.getGlobalBounds().width,
			_pauseButton.getPosition().y);

		_pos.x = SCREEN_WIDHT / 2 - TAILLE_BOUTONS_STANDARD * this->_data->jeu.getLargeur() / 2;
		_pos.y = SCREEN_HEIGHT/ 2 - TAILLE_BOUTONS_STANDARD * this->_data->jeu.getHauteur() / 2;

		InitGrid();
		InitGridPieces();
	}

	void GameState::HandleInput()
	{
		sf::Event event;
		while (this->_data->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				this->_data->window.close();
			};

			if (this->_data->input.IsSpriteClicked(this->_pauseButton, sf::Mouse::Left, event, this->_data->window))
			{
				// Go to Pause State
				this->_data->assets.Play("Button Pressed");
				this->_data->machine.AddState(StateRef(std::make_unique<PauseState>(_data)), false);
			}
			if (gameState == STATE_PLAYING)
			{
				if (turn == PLAYER_PIECE)
				{
					if (this->_data->input.IsMouseClickedInArea(_gridArea, sf::Mouse::Left, event, this->_data->window))
					{
						this->_data->assets.Play("Button Pressed");
						this->CheckAndPlacePiece();
					}
				}
				else if (turn == AI_PIECE)
				{
					this->CheckAndPlacePiece();
				}
			}
		}
	}

	void GameState::Update(float dt)
	{
		if (gameState == STATE_DRAW or gameState == STATE_LOSE or gameState == STATE_WON)
		{
			if (gameState == STATE_DRAW) {
				_gameOverText.setString(L"EGALITE");
				_gameOverText.setPosition(SCREEN_WIDHT / 2 - this->_gameOverText.getGlobalBounds().width / 2,
					SCREEN_HEIGHT / 2 - this->_gameOverText.getGlobalBounds().height / 2);
			}
			if (gameState == STATE_LOSE) {
				_gameOverText.setString(L"PERDU");
				_gameOverText.setPosition(SCREEN_WIDHT / 2 - this->_gameOverText.getGlobalBounds().width / 2,
					SCREEN_HEIGHT / 2 - this->_gameOverText.getGlobalBounds().height / 2);
			}
			if (gameState == STATE_WON) {
				_gameOverText.setString(L"GAGNE");
				_gameOverText.setPosition(SCREEN_WIDHT / 2 - this->_gameOverText.getGlobalBounds().width / 2,
					SCREEN_HEIGHT / 2 - this->_gameOverText.getGlobalBounds().height / 2);
			}
			if (this->_clock.getElapsedTime().asSeconds() > TIME_BEFORE_SHOWING_GAME_OVER)
			{
				this->_data->machine.AddState(StateRef(std::make_unique<GameOverState>(_data)),true);
			}
		}
	}

	void GameState::Draw(float dt)
	{
		this->_data->window.clear();

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_pauseButton);

		DrawGrid();

		for (int i = 0; i < this->_data->jeu.getTaille(); i++)
		{
			this->_data->window.draw(this->_cells[i]);
		}

		this->_data->window.draw(this->_gameOverText);

		this->_data->window.display();
	}

	void GameState::InitGrid()
	{
		this->_grid = std::make_unique<sf::Sprite[]>(this->_data->jeu.getTaille());
		_gridArea = sf::IntRect(_pos.x, _pos.y,
			TAILLE_BOUTONS_STANDARD * this->_data->jeu.getLargeur(),
			TAILLE_BOUTONS_STANDARD * this->_data->jeu.getHauteur());

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

	void GameState::InitGridPieces()
	{
		this->_cells = std::make_unique<sf::Sprite[]>(this->_data->jeu.getTaille());

		sf::Vector2f position = _pos;
		for (int i = this->_data->jeu.getHauteur() - 1; i >= 0; i--)
		{
			for (int j = 0; j < this->_data->jeu.getLargeur(); j++)
			{
				int numCell = i + j * this->_data->jeu.getHauteur();

				this->_cells[numCell].setTexture(this->_data->assets.GetTexture("Red and yellow pieces"));
				//this->_cells[numCell].setTextureRect(sf::IntRect(0, 0, 64, 64));
				this->_cells[numCell].setPosition(position);
				this->_cells[numCell].setColor(sf::Color(255,255,255,0));

				position.x += TAILLE_BOUTONS_STANDARD;

			}
			position.x = _pos.x;
			position.y += TAILLE_BOUTONS_STANDARD;
		}
	}

	void GameState::CheckAndPlacePiece()
	{
		sf::Vector2i touchPoint = this->_data->input.GetMousePosition(this->_data->window);
		
		sf::Vector2f gapOutSideOfGrid = sf::Vector2f((SCREEN_WIDHT - _gridArea.width) / 2,
			(SCREEN_HEIGHT - _gridArea.height) / 2);

		sf::Vector2f gridLocalTouchPos = sf::Vector2f(touchPoint.x - gapOutSideOfGrid.x,
			touchPoint.y - gapOutSideOfGrid.y);

		float gridSectionSize = _gridArea.width / _data->jeu.getLargeur();

		int column;

		if (turn == PLAYER_PIECE)
		{
			for (int i = 1; i <= _data->jeu.getLargeur(); i++)
			{
				if (gridLocalTouchPos.x < gridSectionSize * i) {
					column = i - 1;
					break;
				}
			}
		}
		else if (turn == AI_PIECE)
		{
			// CHANGER POUR POUVOIR SELECTIONNER LES BOTS ET LA DIFFICULTE
			Uniform bot;
			column = bot.genMove(this->_data->jeu);
		}

		if (_data->jeu.isColValide(column))
		{
			if (turn == PLAYER_PIECE)
			{
				int cell = column * _data->jeu.getHauteur() + _data->jeu.getNbJetonsParCol(column);
				_cells[cell].setTextureRect(sf::IntRect(0, 0, TAILLE_BOUTONS_STANDARD, TAILLE_BOUTONS_STANDARD));
				_cells[cell].setColor(sf::Color::White);

				CheckIfPlayerIsGoingToWin(column);

				_data->jeu.ajouteCell(column);

				turn = AI_PIECE;
			}
			else if (turn == AI_PIECE)
			{
				int cell = column * _data->jeu.getHauteur() + _data->jeu.getNbJetonsParCol(column);
				_cells[cell].setTextureRect(sf::IntRect(TAILLE_BOUTONS_STANDARD, 0, TAILLE_BOUTONS_STANDARD, TAILLE_BOUTONS_STANDARD));
				_cells[cell].setColor(sf::Color::White);

				CheckIfPlayerIsGoingToWin(column);

				_data->jeu.ajouteCell(column);

				turn = PLAYER_PIECE;
			}

		}
	}

	void GameState::CheckIfPlayerIsGoingToWin(int col)
	{
		// Egalité
		if (_data->jeu.getNbMoves() + 1 == _data->jeu.getTaille())
		{
			gameState = STATE_DRAW;
		}
		if (_data->jeu.isWinningMove(col))
		{
			if (turn == PLAYER_PIECE)
			{
				gameState = STATE_WON;
			}
			else if (turn == AI_PIECE)
			{
				gameState = STATE_LOSE;
			}
		}

		if (gameState == STATE_DRAW or gameState == STATE_LOSE or gameState == STATE_WON)
		{
			this->_clock.restart();
		}
		
	}
}

