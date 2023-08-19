#pragma once

#include <iostream>
#include <string>
#include "Plateau.h"

namespace puissance4 {
	namespace affichageConsole {
		
		// Affiche le num�ro correspondant � chaque colonne
		void numerosColonnes(const grilleDeJeu::Plateau& jeu);

		// Affiche le plateau de jeu
		void plateau(const grilleDeJeu::Plateau& jeu);

		// Affiche le prochain joueur
		void joueurQuiDoitJouer(const grilleDeJeu::Plateau& jeu);

		// Affiche le num�ro des colonnes, le plateau et le prochain joueur
		void all(const grilleDeJeu::Plateau& jeu);
	}
}

