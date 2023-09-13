#pragma once

namespace Puissance4Modulable {

	// Classe virtuelle qui permet d'avoir plusieurs comportements pour les �tats de la f�netre
	class State
	{
	public:
		// Initialise �tat
		virtual void Init() = 0;

		virtual void HandleInput() = 0;

		// Apres avoir input de utilisateur met � jour le jeu
		virtual void Update(float dt) = 0;

		// Dessine application
		virtual void Draw(float dt) = 0;

		// Met en pause l'�tat
		virtual void Pause() {};

		// Enl�ve la pause
		virtual void Resume() {};
	};
};
