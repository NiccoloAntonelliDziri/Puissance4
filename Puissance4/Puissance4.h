#pragma once

#include <iostream>
#include "Affichage.h"
#include "Plateau.h"
#include "Bot.h"

namespace puissance4 {

	// Boucle principale d'une partie de puissance4
	void faireJouer2BotsEntreEux(grilleDeJeu::Plateau& jeu, bots::Bot& botR, bots::Bot& botY);
}