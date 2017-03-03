#ifndef CHOICE_HPP
#define CHOICE_HPP

#include <memory>
#include <list>

#include "RGamePlay.hh"
#include "Condition.hpp"

namespace RGamePlay
{
	class RGameArbitre;
}

namespace ia
{

	class State;

	class Choice
	{
		std::list<std::shared_ptr<State>>			_state;

	public:
		Choice( RGamePlay::RGameArbitre& currentState,
			IGamePlay::Piece color,
			Condition& condition,
			uint32_t depht );

		void										createStates( RGamePlay::RGameArbitre& currentState,
			IGamePlay::Piece color,
			Condition& condition,
			uint32_t depht );
		void										playState( RGamePlay::RGameArbitre currentState,
			IGamePlay::Piece color,
			Condition& condition,
			uint32_t depht,
			std::tuple<uint8_t, uint8_t> position,
			int8_t priority );

		const std::list<std::shared_ptr<State>>&	getState() const;
	};

}

#endif // !CHOICE_HPP
