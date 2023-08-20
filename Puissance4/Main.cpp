#include "Puissance4.h"

int main()
{
	using namespace puissance4;
	grilleDeJeu::Plateau jeu;
	bots::Player joueur;
	bots::Uniform bot;
	faireJouer2BotsEntreEux(jeu, joueur, bot);
}
