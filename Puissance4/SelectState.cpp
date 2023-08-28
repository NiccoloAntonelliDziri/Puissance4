#include "SelectState.h"
#include "DEFINITIONS.h"

#include "GameState.h"

#include <iostream>

namespace Puissance4Modulable {

	SelectState::SelectState(GameDataRef data) : _data(data)
	{
	}

	void SelectState::Init()
	{
		this->_data->assets.LoadTexture("Play Button Select Menu", SELECT_MENU_PLAY_BUTTON);
		this->_data->assets.LoadTexture("Up arrow", ARROW_UP);
		this->_data->assets.LoadTexture("Down arrow", ARROW_DOWN);

		this->_data->assets.LoadFont("ChakrPetch Regular", FONT_CHAKRAPETCH_REGULAR_PATH);

		// On recharge pas la texture
		// Si besoin il faut load GAME_BACKGROUND_FILEPATH
		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));

		this->_playButton.setTexture(this->_data->assets.GetTexture("Play Button Select Menu"));

		this->_arrowsHauteur.at(0).setTexture(this->_data->assets.GetTexture("Up arrow"));
		this->_arrowsHauteur.at(1).setTexture(this->_data->assets.GetTexture("Down arrow"));
		this->_arrowsLargeur.at(0).setTexture(this->_data->assets.GetTexture("Up arrow"));
		this->_arrowsLargeur.at(1).setTexture(this->_data->assets.GetTexture("Down arrow"));
		this->_arrowsPuissance.at(0).setTexture(this->_data->assets.GetTexture("Up arrow"));
		this->_arrowsPuissance.at(1).setTexture(this->_data->assets.GetTexture("Down arrow"));

		this->_arrowsLargeur.at(0).setScale(0.5, 0.5);
		this->_arrowsLargeur.at(1).setScale(0.5, 0.5);
		this->_arrowsHauteur.at(0).setScale(0.5, 0.5);
		this->_arrowsHauteur.at(1).setScale(0.5, 0.5);
		this->_arrowsPuissance.at(0).setScale(0.5, 0.5);
		this->_arrowsPuissance.at(1).setScale(0.5, 0.5);

		this->_textHauteur.setFont(this->_data->assets.GetFont("ChakrPetch Regular"));
		this->_textHauteur.setStyle(sf::Text::Bold);
		this->_textHauteur.setString(TEXT_SELECT_HAUTEUR);
		this->_textHauteur.setFillColor(sf::Color::Black);
		this->_textLargeur.setFont(this->_data->assets.GetFont("ChakrPetch Regular"));
		this->_textLargeur.setStyle(sf::Text::Bold);
		this->_textLargeur.setString(TEXT_SELECT_LARGEUR);
		this->_textLargeur.setFillColor(sf::Color::Black);
		this->_textPuissance.setFont(this->_data->assets.GetFont("ChakrPetch Regular"));
		this->_textPuissance.setStyle(sf::Text::Bold);
		this->_textPuissance.setString(TEXT_SELECT_PUISSANCE);
		this->_textPuissance.setFillColor(sf::Color::Black);

		this->_valueHauteur.setFont(this->_data->assets.GetFont("ChakrPetch Regular"));
		this->_valueHauteur.setString(std::to_string(HAUTEUR_PAR_DEFAUT));
		this->_valueHauteur.setFillColor(sf::Color::Black);
		this->_valueLargeur.setFont(this->_data->assets.GetFont("ChakrPetch Regular"));
		this->_valueLargeur.setString(std::to_string(LARGEUR_PAR_DEFAUT));
		this->_valueLargeur.setFillColor(sf::Color::Black);
		this->_valuePuissance.setFont(this->_data->assets.GetFont("ChakrPetch Regular"));
		this->_valuePuissance.setString(std::to_string(PUISSANCE_PAR_DEFAUT));
		this->_valuePuissance.setFillColor(sf::Color::Black);

		this->_choixHauteur = HAUTEUR_PAR_DEFAUT;
		this->_choixLargeur = LARGEUR_PAR_DEFAUT;
		this->_choixPuissance = PUISSANCE_PAR_DEFAUT;

		// Centrage background CHANGE CA si on change de background
		this->_background.setPosition(SCREEN_WIDHT / 2 - this->_background.getGlobalBounds().width / 2,
			SCREEN_HEIGHT / 2 - this->_background.getGlobalBounds().height / 2);

		this->_playButton.setPosition(SCREEN_WIDHT / 2 - this->_playButton.getGlobalBounds().width / 2,
			SCREEN_HEIGHT / 5 * 4 - this->_playButton.getGlobalBounds().height / 2);

		// Position Largeur
		this->_textLargeur.setPosition(SCREEN_WIDHT / 2 - _textLargeur.getGlobalBounds().width / 2 - _valueLargeur.getGlobalBounds().width / 2,
			SCREEN_HEIGHT / 5 - this->_textLargeur.getLocalBounds().height / 2); // Divisé par 5 car 4 boutons
		// Position relative à _textLargeur
		this->_valueLargeur.setPosition(_textLargeur.getPosition().x + _textLargeur.getGlobalBounds().width,
			_textLargeur.getPosition().y);
		// Position relative à _valueLargeur
		this->_arrowsLargeur.at(0).setPosition(_valueLargeur.getPosition().x,
			_valueLargeur.getPosition().y - _valueLargeur.getGlobalBounds().height);
		this->_arrowsLargeur.at(1).setPosition(_valueLargeur.getPosition().x,
			_valueLargeur.getPosition().y + _arrowsLargeur.at(1).getGlobalBounds().height);

		// Position Hauteur
		this->_textHauteur.setPosition(SCREEN_WIDHT / 2 - _textHauteur.getGlobalBounds().width / 2 - _valueHauteur.getGlobalBounds().width / 2,
			SCREEN_HEIGHT / 5 * 2 - this->_textHauteur.getLocalBounds().height / 2); // Divisé par 5 car 4 boutons
		// Position relative à _textLargeur
		this->_valueHauteur.setPosition(_textHauteur.getPosition().x + _textHauteur.getGlobalBounds().width,
			_textHauteur.getPosition().y);
		// Position relative à _valueLargeur
		this->_arrowsHauteur.at(0).setPosition(_valueHauteur.getPosition().x,
			_valueHauteur.getPosition().y - _valueHauteur.getGlobalBounds().height);
		this->_arrowsHauteur.at(1).setPosition(_valueHauteur.getPosition().x,
			_valueHauteur.getPosition().y + _arrowsHauteur.at(1).getGlobalBounds().height);

		// Position Puissance
		this->_textPuissance.setPosition(SCREEN_WIDHT / 2 - _textPuissance.getGlobalBounds().width / 2 - _valuePuissance.getGlobalBounds().width / 2,
			SCREEN_HEIGHT / 5 * 3 - this->_textPuissance.getLocalBounds().height / 2); // Divisé par 5 car 4 boutons
		// Position relative à _textLargeur
		this->_valuePuissance.setPosition(_textPuissance.getPosition().x + _textPuissance.getGlobalBounds().width,
			_textPuissance.getPosition().y);
		// Position relative à _valueLargeur
		this->_arrowsPuissance.at(0).setPosition(_valuePuissance.getPosition().x,
			_valuePuissance.getPosition().y - _valuePuissance.getGlobalBounds().height);
		this->_arrowsPuissance.at(1).setPosition(_valuePuissance.getPosition().x,
			_valuePuissance.getPosition().y + _arrowsPuissance.at(1).getGlobalBounds().height);
	}

	void SelectState::HandleInput()
	{
		sf::Event event;
		while (this->_data->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				this->_data->window.close();
			}
			if (this->_data->input.IsSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
			{
				InitPlateau(_choixLargeur, _choixHauteur, _choixPuissance);

				// Switch to game menu
				this->_data->machine.AddState(StateRef(std::make_unique<GameState>(_data)), true);
			}
			if (this->_data->input.IsSpriteClicked(this->_arrowsHauteur.at(0), sf::Mouse::Left, this->_data->window))
			{ // Hauteur flèche haut
				ChangeValueOfHauteur(true);
				this->_valueHauteur.setString(std::to_string(_choixHauteur));
			}
			if (this->_data->input.IsSpriteClicked(this->_arrowsHauteur.at(1), sf::Mouse::Left, this->_data->window))
			{ // Hauteur flèche bas
				ChangeValueOfHauteur(false);
				this->_valueHauteur.setString(std::to_string(_choixHauteur));
			}

			if (this->_data->input.IsSpriteClicked(this->_arrowsLargeur.at(0), sf::Mouse::Left, this->_data->window))
			{ // Largeur flèche haut
				ChangeValueOfLargeur(true);
				this->_valueLargeur.setString(std::to_string(_choixLargeur));
			}
			if (this->_data->input.IsSpriteClicked(this->_arrowsLargeur.at(1), sf::Mouse::Left, this->_data->window))
			{ // Largeur flèche bas
				ChangeValueOfLargeur(false);
				this->_valueLargeur.setString(std::to_string(_choixLargeur));
			}

			if (this->_data->input.IsSpriteClicked(this->_arrowsPuissance.at(0), sf::Mouse::Left, this->_data->window))
			{ // Puissance flèche haut
				ChangeValueOfPuissance(true);
				this->_valuePuissance.setString(std::to_string(_choixPuissance));
			}
			if (this->_data->input.IsSpriteClicked(this->_arrowsPuissance.at(1), sf::Mouse::Left, this->_data->window))
			{ // Puissance flèche bas
				ChangeValueOfPuissance(false);
				this->_valuePuissance.setString(std::to_string(_choixPuissance));
			}
		}
	}

	void SelectState::Update(float dt) 
	{
		TransparentArrows();
	}

	void SelectState::Draw(float dt)
	{
		this->_data->window.clear();

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_playButton);

		// Dessine Largeur
		this->_data->window.draw(this->_textLargeur);
		this->_data->window.draw(this->_valueLargeur);
		this->_data->window.draw(this->_arrowsLargeur.at(0));
		this->_data->window.draw(this->_arrowsLargeur.at(1));

		// Dessine Hauteur
		this->_data->window.draw(this->_textHauteur);
		this->_data->window.draw(this->_valueHauteur);
		this->_data->window.draw(this->_arrowsHauteur.at(0));
		this->_data->window.draw(this->_arrowsHauteur.at(1));

		// Dessine Hauteur
		this->_data->window.draw(this->_textPuissance);
		this->_data->window.draw(this->_valuePuissance);
		this->_data->window.draw(this->_arrowsPuissance.at(0));
		this->_data->window.draw(this->_arrowsPuissance.at(1));

		this->_data->window.display();
	}

	void SelectState::InitPlateau(int largeur, int hauteur, int puissance)
	{
		this->_data->jeu = Plateau(largeur, hauteur, puissance);
	}

	void SelectState::TransparentArrows()
	{
		unsigned char valeurTransparence = 150;

		// Hauteur
		if (this->_choixHauteur >= MAX_HAUTEUR)
		{
			this->_arrowsHauteur.at(0).setColor(sf::Color(255, 255, 255, valeurTransparence));
		}
		if (this->_choixHauteur <= MIN_HAUTEUR)
		{
			this->_arrowsHauteur.at(1).setColor(sf::Color(255, 255, 255, valeurTransparence));
		}
		if (_choixHauteur > MIN_HAUTEUR and _choixHauteur < MAX_HAUTEUR)
		{
			this->_arrowsHauteur.at(0).setColor(sf::Color(255, 255, 255, 255));
			this->_arrowsHauteur.at(1).setColor(sf::Color(255, 255, 255, 255));
		}

		// Largeur
		if (this->_choixLargeur >= MAX_LARGEUR)
		{
			this->_arrowsLargeur.at(0).setColor(sf::Color(255, 255, 255, valeurTransparence));
		}
		if (this->_choixLargeur <= MIN_LARGEUR)
		{
			this->_arrowsLargeur.at(1).setColor(sf::Color(255, 255, 255, valeurTransparence));
		}
		if (_choixLargeur > MIN_LARGEUR and _choixLargeur < MAX_LARGEUR)
		{
			this->_arrowsLargeur.at(0).setColor(sf::Color(255, 255, 255, 255));
			this->_arrowsLargeur.at(1).setColor(sf::Color(255, 255, 255, 255));
		}

		// Puissance
		if (this->_choixPuissance >= std::min(_choixHauteur,_choixLargeur))
		{
			this->_choixPuissance = std::min(_choixHauteur, _choixLargeur);
			this->_valuePuissance.setString(std::to_string(_choixPuissance));
			this->_arrowsPuissance.at(0).setColor(sf::Color(255, 255, 255, valeurTransparence));
		}
		if (this->_choixPuissance <= 2) // Plus petit alignement possible
		{
			this->_arrowsPuissance.at(1).setColor(sf::Color(255, 255, 255, valeurTransparence));
		}
		if (_choixPuissance > 2) // 2 est le plus petit possible
		{
			this->_arrowsPuissance.at(1).setColor(sf::Color(255, 255, 255, 255));
		}
		if (_choixPuissance < std::min(_choixHauteur, _choixLargeur))
		{
			this->_arrowsPuissance.at(0).setColor(sf::Color(255, 255, 255, 255));
		}
	}

	void SelectState::ChangeValueOfLargeur(bool sign)
	{
		if (_choixLargeur > MIN_LARGEUR and !sign)
		{
			_choixLargeur--;
		}
		if (_choixLargeur < MAX_LARGEUR and sign)
		{
			_choixLargeur++;
		}
	}

	void SelectState::ChangeValueOfHauteur(bool sign)
	{
		if (_choixHauteur > MIN_HAUTEUR and !sign)
		{
			_choixHauteur--;
		}
		if (_choixHauteur < MAX_HAUTEUR and sign)
		{
			_choixHauteur++;
		}
	}

	void SelectState::ChangeValueOfPuissance(bool sign)
	{
		if (_choixPuissance > 2 and !sign)
		{
			_choixPuissance--;
		}
		if (_choixPuissance < std::min(_choixHauteur, _choixLargeur) and sign)
		{
			_choixPuissance++;
		}
	}
}
