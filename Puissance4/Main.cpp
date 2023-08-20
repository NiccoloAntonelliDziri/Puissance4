#include "Puissance4.h"

int main()
{
	using namespace puissance4;
	grilleDeJeu::Plateau jeu(7,6,4);
	bots::Player joueur;
	bots::Uniform bot;
	faireJouer2BotsEntreEux(jeu, joueur, bot);
}
