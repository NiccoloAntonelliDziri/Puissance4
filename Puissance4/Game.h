#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"
#include "Plateau.h"

namespace Puissance4Modulable
{
	struct GameData
	{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
		Plateau jeu;
	};

	using GameDataRef = std::shared_ptr<GameData>;

	class Game
	{
	public:
		Game(int width, int height,std::string title);
		~Game();


	private:
		const float dt = 1.0f / 60.0f; // 60 frame par seconde, dt = temps entre deux frames
		sf::Clock _clock;

		GameDataRef _data = std::make_shared<GameData>();

		void Run();
	};

}