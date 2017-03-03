#ifndef STATE_HPP
#define STATE_HPP

#include <memory>

#include "RGamePlay.hh"
#include "Condition.hpp"

namespace ia
{

	class Choice;

	class State
	{
		std::shared_ptr<Choice>						_choice;
		RGamePlay::RGameArbitre						_currentState;
		std::tuple<uint8_t, uint8_t>				_position;
		IGamePlay::Piece							_color;
		Condition&									_condition;
		uint32_t									_depht;
		int32_t										_priority;
		int32_t										_value;

	public:
													State( RGamePlay::RGameArbitre& currentState,
														std::tuple<uint8_t, uint8_t> position,
														IGamePlay::Piece color,
														Condition& condition,
														uint32_t depht,
														int8_t priority = 0 );
													State( RGamePlay::RGameArbitre&& currentState,
														std::tuple<uint8_t, uint8_t> position,
														IGamePlay::Piece color,
														Condition& condition,
														uint32_t depht,
														int8_t priority = 0 );

		std::shared_ptr<Choice>&					getChoice();
		uint32_t									getPriority() const;
		const std::tuple<uint8_t, uint8_t>&			getPosition() const;
		IGamePlay::Piece							getColor() const;
		uint32_t									getDepth() const;
		int32_t										refreshChoiceValue();
		int32_t										getValue() const;
		int32_t										getExpendedValue();
	};

}

#endif // !STATE_HPP
