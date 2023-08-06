#include "Bot.h"

int puissance4::bots::Player::genMove(const grilleDeJeu::Plateau& jeu)
{
    int col = -1;
    affichageConsole::all(jeu);
    DemanderColonne:
    std::cout << "Entrer num colonne: ";
    std::cin >> col;
    if (!jeu.isColValide(col)) {
        std::cout << "La colonne " << col << " n'est pas valide";
        goto DemanderColonne;
    }
    return col;
}
