#pragma once

#include <SFML/Graphics.hpp>

namespace Puissance4Modulable
{
	// Gère tous les input
	class InputManager
	{
	public:
		InputManager() = default;
		~InputManager() = default;

		// Retourne true si le sprite object est clické avec le boutton button de la souris
		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window) const;

		// Retourne la position de la souris dans la fenetre
		sf::Vector2i GetMousePosition(sf::RenderWindow& window) const;

	};

}