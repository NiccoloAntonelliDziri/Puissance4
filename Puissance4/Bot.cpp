#include "Bot.h"

using namespace std;

int puissance4::bots::Player::genMove(const grilleDeJeu::Plateau& jeu)
{
    affichageConsole::all(jeu);
    int col = -1;
    cout << "Entrer num colonne: ";
    cin >> col;
    return col;
}

int puissance4::bots::Uniform::genMove(const grilleDeJeu::Plateau& jeu)
{
    random_device rd;
    default_random_engine eng(rd());

    vector<int> tab = creerTabCoupsPossibles(jeu);

    uniform_int_distribution<int> distrib(0, tab.size() - 1);

    return tab[distrib(eng)];
}

std::vector<int> puissance4::bots::Uniform::creerTabCoupsPossibles(const grilleDeJeu::Plateau& jeu) const
{
    std::vector<int> tab;
    for (int i = 0; i < jeu.getLargeur(); i++)
    {
        if (jeu.isColValide(i))
        {
            tab.push_back(i);
        }
    }
    return tab;
}




