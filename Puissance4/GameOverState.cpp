#include <sstream>
#include "GameOverState.h"
#include "DEFINITIONS.h"
#include "GameState.h"
#include "MainMenuState.h"


namespace Puissance4Modulable
{
	GameOverState::GameOverState(GameDataRef data) : _data(data)
	{
	}

	void GameOverState::Init()
	{
		this->_data->assets.LoadTexture("Retry Button", RETRY_BUTTON);
		this->_data->assets.LoadTexture("Home Button", HOME_BUTTON);

		this->_retryButton.setTexture(this->_data->assets.GetTexture("Retry Button"));
		this->_homeButton.setTexture(_data->assets.GetTexture("Home Button"));

		// Diviser par 3 car il ya plusieurs bouttons a afficher 
		this->_retryButton.setPosition(this->_data->window.getSize().x / 2 - this->_retryButton.getLocalBounds().width / 2,
			this->_data->window.getSize().y / 3 - this->_retryButton.getLocalBounds().height / 2);
		// ducoup ici on multiplie par 2 (fraction 2/3) pour le positionner à coté
		this->_homeButton.setPosition(this->_data->window.getSize().x / 2 - this->_homeButton.getLocalBounds().width / 2,
			this->_data->window.getSize().y / 3 * 2 - this->_homeButton.getLocalBounds().height / 2);
	}

	void GameOverState::HandleInput()
	{
		sf::Event event;
		while (this->_data->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				this->_data->window.close();
			}
			if (this->_data->input.IsSpriteClicked(this->_retryButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(StateRef(std::make_unique<GameState>(_data)), true);
			}
			if (this->_data->input.IsSpriteClicked(this->_homeButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(StateRef(std::make_unique<MainMenuState>(_data)), true);
			}
		}
	}

	void GameOverState::Update(float dt)
	{
	}

	void GameOverState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);
		
		this->_data->window.draw(this->_retryButton);
		this->_data->window.draw(this->_homeButton);

		this->_data->window.display();
	}

}