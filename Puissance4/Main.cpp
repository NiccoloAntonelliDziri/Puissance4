#include "Puissance4.h"

int main()
{
	using namespace puissance4;
	grilleDeJeu::Plateau jeu;
	bots::Player bot;
	bots::Uniform rnd;
	puissance4::faireJouer2BotsEntreEux(jeu, bot, rnd);
}
