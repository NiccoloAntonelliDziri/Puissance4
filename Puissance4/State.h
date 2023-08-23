#pragma once

namespace Puissance4Modulable {

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

		virtual void Pause() {};
		virtual void Resume() {};
	};
};
