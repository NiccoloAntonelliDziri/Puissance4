#pragma once

#include <iostream>
#include <string> // Pour le nom du Bot
#include "Plateau.h"
#include "Affichage.h"

namespace puissance4 {
	namespace bots {

		class Bot {
		public:
			Bot(std::string nomBot) : nomBot(nomBot){}

			~Bot() = default;

			virtual int genMove(const grilleDeJeu::Plateau& jeu) = 0;

		private:
			std::string nomBot;
		};

		/*
		* Pas un bot à proprement parler mais c'est l'utilisateur qui choisit quelle colonne jouer
		*/
		class Player : public Bot {
		public:
			Player() : Bot("humain"){}

			int genMove(const grilleDeJeu::Plateau& jeu) override;
		};
	}
}

