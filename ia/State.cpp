#include <iostream>

#include "Priority.hh"
#include "State.hpp"
#include "Choice.hpp"

namespace ia
{

	State::State( RGamePlay::RGameArbitre& currentState,
		std::tuple<uint8_t, uint8_t> position,
		IGamePlay::Piece color,
		Condition& condition,
		uint32_t depht,
		int8_t priority )
		:
		_currentState( currentState ),
		_position( position ),
		_color( color ),
		_condition( condition ),
		_depht( depht ),
		_priority(priority)
	{
		IGamePlay::Piece piece;
		if ( ( piece = currentState.getWinner()) != 0 ) {
			_priority = 1000 * ( piece == IGamePlay::BLACK ? -1 : 1 ) ;
		}
		_choice = std::make_shared<Choice>( currentState, _color, condition, depht );
	}

	State::State( RGamePlay::RGameArbitre&& currentState,
		std::tuple<uint8_t, uint8_t> position,
		IGamePlay::Piece color,
		Condition& condition,
		uint32_t depht,
		int8_t priority)
		:
		_currentState( std::move(currentState) ),
		_position( position ),
		_color( color ),
		_condition( condition ),
		_depht( depht ),
		_priority(priority)
	{
		IGamePlay::Piece piece;
		if ( ( piece = currentState.getWinner()) != 0 ) {
			_priority = 1000 * ( piece == IGamePlay::BLACK ? -1 : 1 );
		}
		_choice = std::make_shared<Choice>( _currentState, _color, condition, depht );
	}

	std::shared_ptr<Choice>& State::getChoice()
	{
		return _choice;
	}

	uint32_t		State::getPriority() const
	{
		return _priority;
	}

	const std::tuple<uint8_t, uint8_t>&	State::getPosition() const
	{
		return _position;
	}

	IGamePlay::Piece					State::getColor() const
	{
		return _color;
	}

	uint32_t							State::getDepth() const
	{
		return _depht;
	}

	int32_t								State::getExpendedValue()
	{
		RGamePlay::RPieceInformation infos[2];
		int32_t value = 0;

		if ( _currentState.getWinner() != 0 ) {
			return _priority;
		}
		for ( uint8_t y = 0; y < 19; y++ ) {
			for ( uint8_t x = 0; x < 19; x++ ) {
				if ( _currentState.pieceInformationUpdated( x, y ) ) {
					if ( _currentState.getPieceInformation( x, y, infos ) ) {
						int32_t p = Priority( ( _color == IGamePlay::WHITE ? infos : infos + 1 ) ).getPriority();
						if ( p == -1  ) {
							continue;
						}
						if ( _color == IGamePlay::BLACK ) {
							p *= -1;
						}
						value += p;
					}
				}
			}
		}
		return value;
	}

	int32_t								State::refreshChoiceValue()
	{
		int32_t value = 0;
		bool init = false;

		std::cout << "=> State: Depth: "
				  << _depht
				  << "Color: "
				  << ( _color == IGamePlay::WHITE ? "WHITE" : "BLACK" )
				  << std::endl;
		if ( !_choice->getState().empty() ) {
			for ( auto & e : _choice->getState() ) {
				e->refreshChoiceValue();
				if ( !init
					|| ( _color == IGamePlay::WHITE && e->getValue() > value )
					|| ( _color == IGamePlay::BLACK && e->getValue() < value ) ) {
					value = e->getValue();
				}
			}
		} else {
			value = getExpendedValue();
		}
		_value = value;
		std::cout << "<= State: Depth: "
				  << _depht
				  << "Color: "
				  << ( _color == IGamePlay::WHITE ? "WHITE" : "BLACK" )
				  << std::endl;

		return value;
	}

	int32_t			State::getValue() const
	{
		return _value;
	}
}
