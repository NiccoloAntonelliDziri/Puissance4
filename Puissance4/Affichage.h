#pragma once

#include <iostream>
#include <string>
#include "Plateau.h"

namespace Puissance4Modulable {

	// Affiche le numéro correspondant à chaque colonne
	void numerosColonnes(const Plateau& jeu);

	// Affiche le plateau de jeu
	void plateau(const Plateau& jeu);

	// Affiche le prochain joueur
	void joueurQuiDoitJouer(const Plateau& jeu);

	// Affiche le numéro des colonnes, le plateau et le prochain joueur
	void affAll(const Plateau& jeu);
}

