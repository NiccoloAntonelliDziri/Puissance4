#include "SettingsState.h"


#include "DEFINITIONS.h"

#include "GameState.h"
#include "MainMenuState.h"

#include <iostream>

namespace Puissance4Modulable {

	SettingsState::SettingsState(GameDataRef data) : _data(data)
	{
	}

	void SettingsState::Init()
	{
		this->_data->assets.LoadTexture("Resume Button", RESUME_BUTTON);
		this->_data->assets.LoadTexture("Home Button", HOME_BUTTON);
		this->_data->assets.LoadTexture("Sound Off Button", SOUND_OFF);
		this->_data->assets.LoadTexture("Sound On Button", SOUND_ON);

		this->_background.setTexture(this->_data->assets.GetTexture("Pause Background"));
		this->_resumeButton.setTexture(this->_data->assets.GetTexture("Resume Button"));
		this->_homeButton.setTexture(this->_data->assets.GetTexture("Home Button"));
		this->_soundOffButton.setTexture(this->_data->assets.GetTexture("Sound Off Button"));
		this->_soundOnButton.setTexture(this->_data->assets.GetTexture("Sound On Button"));

		this->_settingsStateTitle.setFont(this->_data->assets.GetFont("ChakraPetch Bold"));

		this->_settingsStateTitle.setString(L"Paramètres");
		this->_settingsStateTitle.setFillColor(sf::Color::Black);
		this->_settingsStateTitle.setCharacterSize(36);

		this->_settingsStateTitle.setPosition(0, 0);

		// Les deux à la même position
		this->_soundOffButton.setPosition(this->_data->window.getSize().x / 2 - this->_soundOffButton.getLocalBounds().width / 2,
			this->_data->window.getSize().y / 4 - this->_soundOffButton.getLocalBounds().height / 2);
		this->_soundOnButton.setPosition(this->_data->window.getSize().x / 2 - this->_soundOnButton.getLocalBounds().width / 2,
			this->_data->window.getSize().y / 4 - this->_soundOnButton.getLocalBounds().height / 2);

		// Diviser par 3 car il ya plusieurs bouttons a afficher 
		this->_resumeButton.setPosition(this->_data->window.getSize().x / 2 - this->_resumeButton.getLocalBounds().width / 2,
			this->_data->window.getSize().y / 4 * 2 - this->_resumeButton.getLocalBounds().height / 2);

		// ducoup ici on multiplie par 2 (fraction 2/3) pour le positionner à coté
		this->_homeButton.setPosition(this->_data->window.getSize().x / 2 - this->_homeButton.getLocalBounds().width / 2,
			this->_data->window.getSize().y / 4 * 3 - this->_homeButton.getLocalBounds().height / 2);

		if (this->_data->music.IsMuted())
		{
			this->_soundOffButton.setColor(sf::Color(0, 0, 0, 255)); // Opaque
			this->_soundOnButton.setColor(sf::Color(0, 0, 0, 0)); // Transparant
		}
		else
		{
			this->_soundOnButton.setColor(sf::Color(0, 0, 0, 255)); // Opaque
			this->_soundOffButton.setColor(sf::Color(0, 0, 0, 0)); // Transparant
		}
	}

	void SettingsState::HandleInput()
	{
		sf::Event event;
		while (this->_data->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				this->_data->window.close();
			}
			if (this->_data->input.IsSpriteClicked(this->_resumeButton, sf::Mouse::Left, event, this->_data->window))
			{
				this->_data->assets.Play("Button Pressed");
				this->_data->machine.RemoveState();
			}
			if (this->_data->input.IsSpriteClicked(this->_homeButton, sf::Mouse::Left, event, this->_data->window))
			{
				this->_data->assets.Play("Button Pressed");

				this->_data->machine.RemoveState();
				this->_data->machine.AddState(StateRef(std::make_unique<MainMenuState>(_data)), true);
			}
			if (this->_data->input.IsSpriteClicked(this->_soundOffButton, sf::Mouse::Left, event, this->_data->window))
			{
				this->_data->assets.Play("Button Pressed");

			}
			// Utilisateur peut cliquer uniquement sur le dernier bouton dessiné, celui-là
			// Le mute est donc géré uniquement dans ce if
			// Les boutons deviennent juste transparent en fonction du mute pour rendre l'illusion que ce n'est pas la même
			if (this->_data->input.IsSpriteClicked(this->_soundOnButton, sf::Mouse::Left, event, this->_data->window))
			{
				this->_data->assets.Play("Button Pressed");

				if (this->_data->music.IsMuted())
				{
					this->_data->music.DeMute();
					this->_soundOffButton.setColor(sf::Color(0, 0, 0, 0)); // Opaque
					this->_soundOnButton.setColor(sf::Color(0, 0, 0, 255)); // Transparant
				}
				else
				{
					this->_data->music.Mute();
					this->_soundOnButton.setColor(sf::Color(0, 0, 0, 0)); // Opaque
					this->_soundOffButton.setColor(sf::Color(0, 0, 0, 255)); // Transparant
				}
			}
		}
	}

	void SettingsState::Update(float dt)
	{
	}

	void SettingsState::Draw(float dt)
	{
		this->_data->window.clear();

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_resumeButton);
		this->_data->window.draw(this->_homeButton);

		this->_data->window.draw(this->_settingsStateTitle);

		this->_data->window.draw(this->_soundOffButton);
	
		this->_data->window.draw(this->_soundOnButton);	


		this->_data->window.display();
	}
}
