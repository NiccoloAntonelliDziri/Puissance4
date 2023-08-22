#include "Puissance4.h"

int main()
{
	using namespace Puissance4Modulable;
	Plateau jeu(7,6,4);
	Player joueur;
	Uniform bot;
	faireJouer2BotsEntreEux(jeu, joueur, bot);
}
