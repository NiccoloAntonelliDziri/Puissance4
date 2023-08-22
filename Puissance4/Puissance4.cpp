#include "Puissance4.h"

void Puissance4Modulable::faireJouer2BotsEntreEux(Plateau& jeu, Bot& botR, Bot& botY, bool affEndGame)
{
	while (jeu.getNbMoves() != jeu.getTaille()) {
		Bot& bot = jeu.getNbMoves() % 2 == 0 ? botR : botY;
		int col = bot.genMove(jeu);
		if (jeu.isColValide(col))
		{
			if (jeu.getNbMoves() + 1 == jeu.getTaille()) { // Egalité
				jeu.ajouteCell(col);
				std::cout << std::endl;
				ifAffEndGame(affEndGame, jeu);
				std::cout << "Egalite" << std::endl;
				break;
			}
			else if (jeu.isWinningMove(col)) // Victoire d'un des joueurs
			{
				jeu.ajouteCell(col);
				std::cout << std::endl;
				ifAffEndGame(affEndGame, jeu);
				std::cout << "Victoire " << (jeu.getNbMoves() % 2 == 0 ? "Jaune" : "Rouge") << std::endl;
				break;
			}
			else
			{
				jeu.ajouteCell(col);
			}
		}
		else
		{
			std::cout << "La colonne " << col << " n'est pas valide" << std::endl;
		}
	}
}

void Puissance4Modulable::ifAffEndGame(bool affEndGame, const Plateau& jeu)
{
	if (affEndGame) Puissance4Modulable::affAll(jeu);
}
