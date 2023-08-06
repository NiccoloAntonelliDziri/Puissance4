#pragma once

#include <iostream>
#include <string>
#include "Plateau.h"

namespace puissance4 {
	namespace affichageConsole {
		
		void numerosColonnes(const grilleDeJeu::Plateau& jeu);

		void plateau(const grilleDeJeu::Plateau& jeu);

		void joueurQuiDoitJouer(const grilleDeJeu::Plateau& jeu);

		void all(const grilleDeJeu::Plateau& jeu);
	}
}

