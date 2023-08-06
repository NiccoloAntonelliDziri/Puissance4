#pragma once

#include <iostream>
#include "Affichage.h"
#include "Plateau.h"
#include "Bot.h"

namespace puissance4 {

	// Boucle principale d'une partie de puissance4
	// G�re les �galit�s et victoires des deux joueurs
	// V�rifie si la colonne g�n�r�e par genMove est valide
	// Ajoute le jeton sur la colonne g�n�r�e � jeu
	// Affiche la grille de jeu � chaque fin de partie par d�faut, pour d�sactiver mettre affEndGame � false
	void faireJouer2BotsEntreEux(grilleDeJeu::Plateau& jeu, bots::Bot& botR, bots::Bot& botY, bool affEndGame = true);
}