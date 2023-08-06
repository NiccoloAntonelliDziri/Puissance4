#include "Puissance4.h"

int main()
{
	/*Création d'une grille de jeu de taille 7 * 6
	* Et d'un bot Humain pour pouvoir controler les deux joueurs
	*/
	puissance4::grilleDeJeu::Plateau jeu;
	puissance4::bots::Player bot;
	puissance4::faireJouer2BotsEntreEux(jeu, bot, bot);
}
