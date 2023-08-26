#include "Bot.h"

using namespace std;

int Puissance4Modulable::Player::genMove(const Plateau& jeu)
{
    //affAll(jeu);
    int col = -1;
    cout << "Entrer num colonne: ";
    cin >> col;
    return col;
}

int Puissance4Modulable::Uniform::genMove(const Plateau& jeu)
{
    random_device rd;
    default_random_engine eng(rd());

    vector<int> tab = creerTabCoupsPossibles(jeu);

    uniform_int_distribution<int> distrib(0, tab.size() - 1);

    return tab[distrib(eng)];
}

std::vector<int> Puissance4Modulable::Uniform::creerTabCoupsPossibles(const Plateau& jeu) const
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




