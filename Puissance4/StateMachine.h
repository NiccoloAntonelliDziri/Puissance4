#pragma once

#include <memory>
#include <stack>

#include "State.h"

namespace Puissance4Modulable {

	using StateRef = std::unique_ptr<State>;

	// Permet de g�rer les diff�rents �tats
	class StateMachine
	{
	public:
		StateMachine() = default;

		~StateMachine() = default;

		// Ajoute un nouvel �tat
		void AddState(StateRef newState, bool isReplacing = true);

		// Enl�ve l'�tat actuel
		void RemoveState();

		// Debut de chaque boucle
		// Tous les changements se font ici
		void ProcessStateChanges();

		// Retourne l'�tat actif de la fenetre
		StateRef& GetActiveState();

	private:
		std::stack<StateRef> _states; // Pile des �tats
		StateRef _newState; // Nouvel �tat

		bool _isRemoving;
		bool _isAdding;
		bool _isReplacing;
	};
}