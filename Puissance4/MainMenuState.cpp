#include "MainMenuState.h"
#include "DEFINITIONS.h"

#include "GameState.h"
#include "SelectState.h"
#include "SettingsState.h"

#include <Windows.h>
#include <shellapi.h>


namespace Puissance4Modulable {

	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{
	}

	void MainMenuState::Init()
	{
		this->_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUD_FILEPATH);
		this->_data->assets.LoadTexture("Pause Background", PAUSE_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Play Button", MAIN_MENU_PLAY_BUTTON);
		this->_data->assets.LoadTexture("Game Title", MAIN_MENU_TITLE_PATH);
		this->_data->assets.LoadTexture("Github Button", GITHUB_BUTTON);
		this->_data->assets.LoadTexture("Settings Button", SETTINGS_BUTTON);

		this->_data->assets.LoadFont("ChakraPetch Bold", FONT_CHAKRAPETCH_BOLD_PATH);
		this->_data->assets.LoadFont("ChakraPetch Regular", FONT_CHAKRAPETCH_REGULAR_PATH);

		this->_data->assets.LoadSound("Button Pressed", SOUND_BUTTONS_FILE);

		this->_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
		this->_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
		this->_title.setTexture(this->_data->assets.GetTexture("Game Title"));
		this->_githubButton.setTexture(this->_data->assets.GetTexture("Github Button"));
		this->_settings.setTexture(this->_data->assets.GetTexture("Settings Button"));

		// Centrage background
		this->_background.setPosition(SCREEN_WIDHT / 2 - this->_background.getGlobalBounds().width / 2,
			SCREEN_HEIGHT / 2 - this->_background.getGlobalBounds().height / 2);

		// Positionne play button au centre
		this->_playButton.setPosition(SCREEN_WIDHT / 2 - this->_playButton.getGlobalBounds().width / 2,
			SCREEN_HEIGHT / 2 - this->_playButton.getGlobalBounds().height / 2);

		// Bas à droite
		this->_githubButton.setPosition(this->_data->window.getSize().x - _githubButton.getGlobalBounds().width,
			this->_data->window.getSize().y - _githubButton.getGlobalBounds().height);

		// Positionne au centre mais en haut
		this->_title.setPosition(SCREEN_WIDHT / 2 - this->_title.getGlobalBounds().width / 2,
			this->_title.getGlobalBounds().height * 0.1);

		// En haut à droite
		this->_settings.setPosition(this->_data->window.getSize().x - _settings.getGlobalBounds().width,
			_settings.getPosition().y);

		// Début musique du jeu
		if (!this->_data->music.IsPlaying())
		{
			this->_data->music.OpenMusic(GAME_MUSIC);
			this->_data->music.EnableLoop(true);
			this->_data->music.Play();
		}
	}

	void MainMenuState::HandleInput()
	{
		sf::Event event;
		while (this->_data->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				this->_data->window.close();
			}
			if (this->_data->input.IsSpriteClicked(this->_playButton, sf::Mouse::Left, event, this->_data->window))
			{
				this->_data->assets.Play("Button Pressed");
				this->_data->machine.AddState(StateRef(std::make_unique<SelectState>(_data)), true);
			}
			if (this->_data->input.IsSpriteClicked(this->_githubButton, sf::Mouse::Left,event, this->_data->window))
			{
				this->_data->assets.Play("Button Pressed");
				ShellExecute(0, 0, L"https://github.com/NiccoloAntonelliDziri/Puissance4", 0, 0, SW_SHOW);
			}
			if (this->_data->input.IsSpriteClicked(this->_settings, sf::Mouse::Left, event, this->_data->window))
			{
				this->_data->assets.Play("Button Pressed");
				this->_data->machine.AddState(StateRef(std::make_unique<SettingsState>(_data)), false);
			}
		}
	}

	void MainMenuState::Update(float dt)
	{
	}

	void MainMenuState::Draw(float dt)
	{
		this->_data->window.clear();

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_playButton);
		this->_data->window.draw(this->_title);
		this->_data->window.draw(this->_githubButton);
		this->_data->window.draw(this->_settings);

		this->_data->window.display();
	}
}
