#pragma once

#include <iostream>
#include "Affichage.h"
#include "Plateau.h"
#include "Bot.h"

namespace puissance4 {

	// Boucle principale d'une partie de puissance4
	// Gère les égalités et victoires des deux joueurs
	// Vérifie si la colonne générée par genMove est valide
	// Ajoute le jeton sur la colonne générée à jeu
	// Affiche la grille de jeu à chaque fin de partie par défaut, pour désactiver mettre affEndGame à false
	void faireJouer2BotsEntreEux(grilleDeJeu::Plateau& jeu, bots::Bot& botR, bots::Bot& botY, bool affEndGame = true);
}