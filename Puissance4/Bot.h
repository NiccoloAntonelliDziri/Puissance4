#pragma once

#include <iostream>
#include <vector>
#include <random>
#include "Plateau.h"
#include "Affichage.h"

namespace puissance4 {
	namespace bots {

		// Classe mère de tous les bots
		class Bot {
		public:
			Bot() = default;

			virtual ~Bot() = default;

			virtual int genMove(const grilleDeJeu::Plateau& jeu) = 0;
		};

		// Pas un bot à proprement parler mais c'est l'utilisateur qui choisit quelle colonne jouer
		class Player : public Bot {
		public:
			Player() = default;

			// Demande au joueur d'entrer le coup qu'il veut jouer
			int genMove(const grilleDeJeu::Plateau& jeu) override;
		};

		// Classe mère des bots qui utilisent de l'aléatoire
		class Random : public Bot {
		public:
			Random() = default;
		};

		class Uniform : public Random {
		public:
			Uniform() = default;

			// Retourne une colonne valide aléatoire selon une disttibution uniforme
			int genMove(const grilleDeJeu::Plateau& jeu) override;

		protected:
			// Crée un tableau dans tab avec les coups qu'il est possible de jouer
			std::vector<int> creerTabCoupsPossibles(const grilleDeJeu::Plateau& jeu) const;

		};
	}
}

