#pragma once

#include <memory>
#include <stack>

#include "State.h"

namespace Puissance4Modulable {

	using StateRef = std::unique_ptr<State>;

	// Permet de gérer les différents états
	class StateMachine
	{
	public:
		StateMachine() = default;

		~StateMachine() = default;

		// Ajoute un nouvel état
		void AddState(StateRef newState, bool isReplacing = true);

		// Enlève l'état actuel
		void RemoveState();

		// Debut de chaque boucle
		// Tous les changements se font ici
		void ProcessStateChanges();

		// Retourne l'état actif de la fenetre
		StateRef& GetActiveState();

	private:
		std::stack<StateRef> _states; // Pile des états
		StateRef _newState; // Nouvel état

		bool _isRemoving;
		bool _isAdding;
		bool _isReplacing;
	};
}