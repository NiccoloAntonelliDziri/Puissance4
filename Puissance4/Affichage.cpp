#include "Affichage.h"

void Puissance4Modulable::numerosColonnes(const Plateau& jeu)
{
	for (int i = 0; i < jeu.getLargeur(); i++)
	{
		std::cout << i << "  ";
	}
	std::cout << std::endl;
}

void Puissance4Modulable::plateau(const Plateau& jeu)
{
	using namespace std;
	for (int i = jeu.getHauteur() - 1; i >= 0 ; i--)
	{
		for (int j = 0; j < jeu.getLargeur(); j++)
		{
			switch (jeu.getCell(i + j * jeu.getHauteur()))
			{
			case Cell::VIDE:
				std::cout << "[] ";
				break;
			case Cell::ROUGE:
				std::cout << "R  ";
				break;
			case Cell::JAUNE:
				std::cout << "J  ";
				break;
			default:
				std::cout << "e  ";
				break;
			}
		}
		std::cout << std::endl;
	}
}

void Puissance4Modulable::joueurQuiDoitJouer(const Plateau& jeu)
{
	std::cout << "Joueur: " << (jeu.getNbMoves() % 2 == 0 ? "Rouge" : "Jaune") << std::endl;
}

void Puissance4Modulable::affAll(const Plateau& jeu)
{
	numerosColonnes(jeu);
	plateau(jeu);
	joueurQuiDoitJouer(jeu);
	std::cout << std::endl;
}
