#pragma once

#include <iostream>
#include <vector>
#include <random>
#include "Plateau.h"

namespace Puissance4Modulable {

	// Classe m�re de tous les bots
	class Bot {
	public:
		Bot() = default;

		virtual ~Bot() = default;

		virtual int genMove(const Plateau& jeu) = 0;
	};

	// Pas un bot � proprement parler mais c'est l'utilisateur qui choisit quelle colonne jouer
	class Player : public Bot {
	public:
		Player() = default;

		// Demande au joueur d'entrer le coup qu'il veut jouer
		// NE PAS entrer autre chose qu'un entier dans la console
		int genMove(const Plateau& jeu) override;
	};

	// Classe m�re des bots qui utilisent de l'al�atoire
	class Random : public Bot {
	public:
		Random() = default;
	};

	class Uniform : public Random {
	public:
		Uniform() = default;

		// Retourne une colonne valide al�atoire selon une disttibution uniforme
		int genMove(const Plateau& jeu) override;

	protected:
		// Cr�e un tableau dans tab avec les coups qu'il est possible de jouer
		std::vector<int> creerTabCoupsPossibles(const Plateau& jeu) const;

	};
}


