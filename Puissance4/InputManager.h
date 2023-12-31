#pragma once

#include <SFML/Graphics.hpp>

namespace Puissance4Modulable
{
	// G�re tous les input
	class InputManager
	{
	public:
		InputManager() = default;
		~InputManager() = default;

		// Retourne true si le sprite object est click� avec le boutton button de la souris
		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::Event& event, sf::RenderWindow& window);

		// Retourne la position de la souris dans la fenetre
		sf::Vector2i GetMousePosition(sf::RenderWindow& window) const;

		bool IsMouseClickedInArea(sf::IntRect area, sf::Mouse::Button button, sf::Event& event, sf::RenderWindow& window);

	private:
		bool _lockMouseClicked;
	};

}