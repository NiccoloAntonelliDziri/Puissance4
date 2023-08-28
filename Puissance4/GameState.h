#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

#include "Bot.h"

namespace Puissance4Modulable
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		~GameState();

		void Init() override;

		void HandleInput() override;

		void Update(float dt) override;

		void Draw(float dt) override;

	private:
		// Initialise setTexture et setTextureRect pour toutes les cellules de la grille
		// en fonction de sa taille effective dynamiquement
		void InitGrid();

		// Dessine la grille
		// AUCUNE VERIFICATION DE SI LA GRILLE ENTIERE RENTRE DANS LA FENETRE
		// COMPORTEMENT INDETERMINE SI PLUS GRAND QUE LA FENETRE
		void DrawGrid();

		void InitGridPieces();

		void CheckAndPlacePiece();

		void CheckIfPlayerIsGoingToWin(int col);

		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _pauseButton;
		
		std::unique_ptr<sf::Sprite[]> _grid;
		std::unique_ptr<sf::Sprite[]> _cells;

		sf::Vector2f _pos; // coord du coin en haut à gauche de _grid
		sf::IntRect _gridArea;

		int gameState;
		int turn;

		sf::Clock _clock;

		sf::Text _gameOverText;
	};
}