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
		void InitGridPieces();

		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _pauseButton;

		sf::Sprite _gridTiles;
		sf::Sprite* _gridCellPieces;

		int turn;
		int gameState;
	};
}