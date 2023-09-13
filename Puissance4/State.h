#pragma once

namespace Puissance4Modulable {

	// Classe virtuelle qui permet d'avoir plusieurs comportements pour les états de la fênetre
	class State
	{
	public:
		// Initialise état
		virtual void Init() = 0;

		virtual void HandleInput() = 0;

		// Apres avoir input de utilisateur met à jour le jeu
		virtual void Update(float dt) = 0;

		// Dessine application
		virtual void Draw(float dt) = 0;

		// Met en pause l'état
		virtual void Pause() {};

		// Enlève la pause
		virtual void Resume() {};
	};
};
