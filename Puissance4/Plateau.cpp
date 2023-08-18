#include "Plateau.h"

void puissance4::grilleDeJeu::Plateau::ajouteCell(int col)
{
	plateau[colonnes[col] + col * HAUTEUR] = (Cell)(nbMoves % 2);
	colonnes[col]++;
	nbMoves++;
}

bool puissance4::grilleDeJeu::Plateau::isWinningMove(int col) const
{
	auto current_cell = (Cell)(nbMoves % 2);

	// Vertical
	if (colonnes[col] >= PUISSANCE - 1) {
		int i;
		for (i = 1; i < PUISSANCE; i++)
		{
			if (plateau[col - i] != current_cell) break;
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
