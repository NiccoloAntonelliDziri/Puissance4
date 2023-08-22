# Puissance4

Puissance 4 modulable.
Les dimensions du plateau (largeur et hauteur) ainsi que le nombre de jetons qu'il faut aligner pour gagner (puissance) sont réglables pour chaque partie.
Le but du jeu est d'aligner "puissance" jetons en ligne, colonne, ou diagonale pour gagner.

## Jouer une partie

Déclarer un plateau de jeu (ici largeur: 7, hauteur: 6, puissance: 4).
Déclarer un plusieurs bots (qui incluent les joueurs humains).

```c++
int main()
{
	using namespace Puissance4Modulable;
	Plateau jeu(7,6,4);
	Player joueur;
	Uniform bot;
	faireJouer2BotsEntreEux(jeu, joueur, bot);
	return 0;
}
```

Pour 2 joueurs humain il suffit de déclarer un seul `Player joueur;` et le passer dans les deux paramètres de la fonction `faireJouer2BotsEntreEux(jeu, joueur, joueur);`
