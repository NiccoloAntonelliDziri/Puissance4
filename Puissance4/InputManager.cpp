#include "InputManager.h"

namespace Puissance4Modulable
{
	bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window) const
	{
		if (sf::Mouse::isButtonPressed(button))
		{
			sf::IntRect tempRect(object.getPosition().x, object.getPosition().y,
				object.getGlobalBounds().width, object.getGlobalBounds().height);

			if (tempRect.contains(sf::Mouse::getPosition(window)))
			{
				return true;
			}
		}
		return false;
	}

	sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow& window) const
	{
		return sf::Mouse::getPosition(window);
	}


}