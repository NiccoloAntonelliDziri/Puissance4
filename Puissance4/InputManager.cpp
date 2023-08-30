#include "InputManager.h"

namespace Puissance4Modulable
{
	bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::Event& event, sf::RenderWindow& window)
	{
		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == button)
			{
				sf::IntRect tempRect(object.getPosition().x, object.getPosition().y,
					object.getGlobalBounds().width, object.getGlobalBounds().height);

				if (tempRect.contains(sf::Mouse::getPosition(window)))
				{
					return true;
				}
			}
		}
		return false;
	}

	sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow& window) const
	{
		return sf::Mouse::getPosition(window);
	}

	bool InputManager::IsMouseClickedInArea(sf::IntRect area, sf::Mouse::Button button, sf::Event& event, sf::RenderWindow& window)
	{
		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == button)
			{
				if (area.contains(sf::Mouse::getPosition(window)))
				{
					return true;
				}
			}
		}
		return false;
	}
}