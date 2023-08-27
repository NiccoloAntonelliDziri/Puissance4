#pragma once

#include "State.h"
#include "Game.h"

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

		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _7x6Button;

		sf::Text _textLargeur;
		sf::Text _textHauteur;
		sf::Text _textPuissance;

		int _choixLargeur;
		int _choixHauteur;
		int _choixPuissance;
	};

}