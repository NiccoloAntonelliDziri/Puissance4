#pragma once

#include "State.h"
#include "Game.h"
#include <array>

namespace Puissance4Modulable
{
	class SelectState : public State
	{
	public:
		SelectState(GameDataRef data);

		void Init() override;

		void HandleInput() override;

		void Update(float dt) override;

		void Draw(float dt);

	private:
		void InitPlateau(int largeur, int hauteur, int puissance);

		// Les boutons désactivés sont rendus transparents
		void TransparentArrows();

		// if sign == true -> Ajoute +1
		// if sign == false -> Ajoute -1
		void ChangeValueOfLargeur(bool sign);

		// if sign == true -> Ajoute +1
		// if sign == false -> Ajoute -1
		void ChangeValueOfHauteur(bool sign);

		// if sign == true -> Ajoute +1
		// if sign == false -> Ajoute -1
		void ChangeValueOfPuissance(bool sign);

		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _playButton;
		sf::Sprite _githubButton;
		sf::Sprite _settings;

		std::array<sf::Sprite, 2> _arrowsLargeur; // .at(0) correspond à la flèche vers le haut et .at(1) vers le bas
		std::array<sf::Sprite, 2> _arrowsHauteur; // .at(0) correspond à la flèche vers le haut et .at(1) vers le bas
		std::array<sf::Sprite, 2> _arrowsPuissance; // .at(0) correspond à la flèche vers le haut et .at(1) vers le bas
		sf::Text _textLargeur;
		sf::Text _textHauteur;
		sf::Text _textPuissance;
		sf::Text _valueLargeur;
		sf::Text _valueHauteur;
		sf::Text _valuePuissance;

		int _choixLargeur;
		int _choixHauteur;
		int _choixPuissance;
	};

}