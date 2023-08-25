#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

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
		// Initialise la grille
		void InitGrid();

		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _pauseButton;

		std::unique_ptr<sf::Sprite[]> _gridEmpty; // Grille vide
		std::unique_ptr<sf::Sprite[]> _gridCellPieces; // Tableau dynamique des pièces

		int turn;
		int gameState;
	};
}