#include "Plateau.h"

void Puissance4Modulable::Plateau::ajouteCell(int col)
{
	plateau[colonnes[col] + col * HAUTEUR] = (Cell)(nbMoves % 2);
	colonnes[col]++;
	nbMoves++;
}

bool Puissance4Modulable::Plateau::isWinningMove(int col) const
{
	auto current_cell = (Cell)(nbMoves % 2);

	// Vertical
	if (colonnes[col] + 1 >= PUISSANCE) {
		int i;
		for (i = 1; i < PUISSANCE; i++)
		{
			if (plateau[col * HAUTEUR + colonnes[col] - i] != current_cell) break;
		}
		if (i == PUISSANCE) return true;
	}

	for (int dy = -1; dy <= 1; dy++) {    // Iterate on horizontal (dy = 0) or two diagonal directions (dy = -1 or dy = 1).
		int nb = 0;                       // counter of the number of stones of current player surronding the played stone in tested direction.
		for (int dx = -1; dx <= 1; dx += 2) // count continuous stones of current player on the left, then right of the played column.
			for (int x = col + dx, y = colonnes[col] + dx * dy; x >= 0 && x < LARGEUR && y >= 0 && y < LARGEUR && plateau[y + HAUTEUR * x] == current_cell; nb++) {
				x += dx;
				y += dx * dy;
			}
		if (nb >= PUISSANCE - 1) return true; // there is an aligment if at least 3 other stones of the current user 
		// are surronding the played stone in the tested direction.
	}
	return false;
}

void Puissance4Modulable::Plateau::reInit(int largeur, int hauteur, int puissance)
{
	LARGEUR = largeur;
	HAUTEUR = hauteur;
	PUISSANCE = puissance;

	nbMoves = 0;

	delete[] plateau;
	delete[] colonnes;

	colonnes = new int[LARGEUR];
	plateau = new Cell[LARGEUR * HAUTEUR];

	// Initialisation � 0 du plateau
	for (int i = 0; i < largeur * hauteur; i++) plateau[i] = Cell::VIDE;
	for (int i = 0; i < largeur; i++) colonnes[i] = 0;
}
