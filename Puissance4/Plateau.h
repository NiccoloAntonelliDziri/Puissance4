#pragma once

#include <algorithm>

// Représente le contenu d'une cellule du plateau
enum class Cell { ROUGE, JAUNE, VIDE };

namespace Puissance4Modulable {
	/*
	* Classe qui représente une grille de puissance 4 de taille modulable
	*
	* Exemple pour une grille de 7*6:
	*	5  11 17 23 29 35 41
	*	4  10 16 22 28 34 40
	*	3  9  15 21 27 33 39
	*	2  8  14 20 26 32 38
	*	1  7  13 19 25 31 37
	*	0  6  12 18 24 30 36
	*
	*/
	class Plateau {
	private:
		// Dimensions du plateau:
		int LARGEUR; // Largeur du plateau de jeu
		int HAUTEUR; // Hauteur du plateau de jeu

		int PUISSANCE; // Nombre de jetons qu'il faut aligner pour gagner una partie

		int nbMoves = 0; // Nombre de coups joués depuis le début de la partie

		int* colonnes; // Tableau avec le nombre de jetons dans chaque colonne du plateau
		Cell* plateau; // Grille de jeu
	public:
		Plateau(int largeur = 7, int hauteur = 6, int puissance = 4) :
			LARGEUR(largeur), HAUTEUR(hauteur), PUISSANCE(puissance)
			{
			colonnes = new int[LARGEUR];
			plateau = new Cell[LARGEUR * HAUTEUR];

			// Initialisation à 0 du plateau
			for (int i = 0; i < largeur * hauteur; i++) plateau[i] = Cell::VIDE;
			for (int i = 0; i < largeur; i++) colonnes[i] = 0;
		}

		//// Constructeur de copie
		Plateau(const Plateau& other) :
			LARGEUR(other.LARGEUR), HAUTEUR(other.HAUTEUR), PUISSANCE(other.PUISSANCE),
			nbMoves(other.nbMoves) {

			colonnes = new int[LARGEUR];
			plateau = new Cell[LARGEUR * HAUTEUR];
				
			std::copy(other.colonnes, other.colonnes + LARGEUR, colonnes);
			std::copy(other.plateau, other.plateau + (LARGEUR * HAUTEUR), plateau);
		}
			
		// Copy assignement operator
		Plateau& operator=(const Plateau& other) {
			if (&other != this) {
				delete[] colonnes;
				delete[] plateau;
				colonnes = nullptr;
				plateau = nullptr;

				LARGEUR = other.LARGEUR;
				HAUTEUR = other.HAUTEUR;
				PUISSANCE = other.PUISSANCE;
				nbMoves = other.nbMoves;

				colonnes = new int[LARGEUR];
				plateau = new Cell[LARGEUR * HAUTEUR];

				std::copy(other.colonnes, other.colonnes + LARGEUR, colonnes);
				std::copy(other.plateau, other.plateau + (LARGEUR * HAUTEUR), plateau);
			}
			return *this;
		}

		// move constructor
		Plateau(Plateau&& other) noexcept :
			LARGEUR(7), HAUTEUR(6), PUISSANCE(4),
			nbMoves(0),
			colonnes(nullptr), plateau(nullptr){

			colonnes = other.colonnes;
			plateau = other.plateau;

			LARGEUR = other.LARGEUR;
			HAUTEUR = other.HAUTEUR;
			PUISSANCE = other.PUISSANCE;
			nbMoves = other.nbMoves;

			other.colonnes = nullptr;
			other.plateau = nullptr;
			other.nbMoves = 0;
		}

		// Move assignement operator
		Plateau const& operator=(Plateau&& other) noexcept{
			if (this != &other)
			{
				delete[] colonnes;
				delete[] plateau;

				colonnes = other.colonnes;
				plateau = other.plateau;

				LARGEUR = other.LARGEUR;
				HAUTEUR = other.HAUTEUR;
				PUISSANCE = other.PUISSANCE;
				nbMoves = other.nbMoves;

				other.colonnes = nullptr;
				other.plateau = nullptr;
				other.nbMoves = 0;
			}
			return *this;
		}

		~Plateau() {
			delete[] colonnes;
			delete[] plateau;
		}

		// Met le cell dans la cellule la plus basse de la colonne col
		// NE PAS appeler avec une colonne non jouable
		void ajouteCell(int col);

		// Retourne true si detecte un alignement suivant une des 4 directions
		// NE PAS appeler si col n'est pas une colonne valide
		bool isWinningMove(int col) const;

		// Retourne true si une colonne est jouable et false sinon
		inline bool isColValide(int col) const { return colonnes[col] < HAUTEUR and col >= 0 and col < LARGEUR; }

		inline int getLargeur() const { return LARGEUR; }
		inline int getHauteur() const { return HAUTEUR; }
		inline int getTaille() const { return LARGEUR * HAUTEUR; }
		inline int getPuissance() const { return PUISSANCE; }
		inline int getNbMoves() const { return nbMoves; }

		inline int getNbJetonsParCol(int col) const { return colonnes[col]; }
		inline Cell getCell(int cellule) const { return plateau[cellule]; }

	};
}// namespace