#include "PauseState.h"

#include "DEFINITIONS.h"

#include "GameState.h"
#include "MainMenuState.h"

#include <iostream>

namespace Puissance4Modulable {

	PauseState::PauseState(GameDataRef data) : _data(data)
	{
	}

	void PauseState::Init()
	{
		this->_data->assets.LoadTexture("Pause Background", PAUSE_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Resume Button", RESUME_BUTTON);
		this->_data->assets.LoadTexture("Home Button", HOME_BUTTON);

		this->_background.setTexture(this->_data->assets.GetTexture("Pause Background"));
		this->_resumeButton.setTexture(this->_data->assets.GetTexture("Resume Button"));
		this->_homeButton.setTexture(_data->assets.GetTexture("Home Button"));

		// Diviser par 3 car il ya plusieurs bouttons a afficher 
		this->_resumeButton.setPosition(this->_data->window.getSize().x / 2 - this->_resumeButton.getLocalBounds().width / 2,
			this->_data->window.getSize().y / 3 - this->_resumeButton.getLocalBounds().height / 2);
		// ducoup ici on multiplie par 2 (fraction 2/3) pour le positionner à coté
		this->_homeButton.setPosition(this->_data->window.getSize().x / 2 - this->_homeButton.getLocalBounds().width / 2,
			this->_data->window.getSize().y / 3 * 2 - this->_homeButton.getLocalBounds().height / 2);
	}

	void PauseState::HandleInput()
	{
		sf::Event event;
		while (this->_data->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				this->_data->window.close();
			}
			if (this->_data->input.IsSpriteClicked(this->_resumeButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->assets.Play("Button Pressed");
				this->_data->machine.RemoveState();
			}
			if (this->_data->input.IsSpriteClicked(this->_homeButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->assets.Play("Button Pressed");

				this->_data->machine.RemoveState();
				this->_data->machine.AddState(StateRef(std::make_unique<MainMenuState>(_data)), true);
			}
		}
	}

	void PauseState::Update(float dt)
	{
	}

	void PauseState::Draw(float dt)
	{
		this->_data->window.clear();

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_resumeButton);
		this->_data->window.draw(this->_homeButton);

		this->_data->window.display();
	}
}
