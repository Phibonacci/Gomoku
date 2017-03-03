#include <iostream>
#include <algorithm>
#include <cassert>

#include "Priority.hh"
#include "Choice.hpp"
#include "State.hpp"

namespace ia
{

	Choice::Choice( RGamePlay::RGameArbitre& currentState,
		IGamePlay::Piece color,
		Condition& condition,
		uint32_t depht )
	{
		depht++;
		if ( condition.isValid( depht ) ) {
			createStates( currentState, color, condition, depht );
		}
	}

	void			Choice::createStates( RGamePlay::RGameArbitre& currentState,
		IGamePlay::Piece color,
		Condition& condition,
		uint32_t depht )
	{
		uint8_t positionsLen = 0;
		std::tuple<uint8_t, uint8_t> positions[25];
		RGamePlay::RPieceInformation infos[2];
		int8_t priorities[25];
		int32_t priorityMax = 0;
		int32_t priorityMin = 0;

		if ( currentState.getWinner() != 0 ) {
			return;
		}
		for ( uint8_t y = 0; y < 19 && positionsLen < 25; y++ ) {
			for ( uint8_t x = 0; x < 19 && positionsLen < 25; x++ ) {
				if ( currentState.pieceInformationUpdated( x, y ) ) {
					if ( currentState.getPieceInformation( x, y, infos ) ) {
						positions[positionsLen] = std::make_tuple( x, y );
						int32_t p = Priority( ( color == IGamePlay::WHITE ? infos : infos + 1 ) ).getPriority();
						if ( p == -1  ) {
							continue;
						}
						if ( color == IGamePlay::BLACK ) {
							p *= -1;
						}
						priorities[positionsLen] = p;
						if ( priorityMax < p ) {
							priorityMax = p;
						}
						if ( priorityMin > p ) {
							priorityMin = p;
						}
						positionsLen++;
					}
				}
			}
		}
		for ( size_t i = 0; i < positionsLen; i++ ) {
			// if ( priorities[i] == priorityMin || priorities[i] == priorityMax) {
				playState( currentState, color, condition, depht, positions[i],	priorities[i] );
			// }
		}
	}

	void			Choice::playState( RGamePlay::RGameArbitre currentState,
		IGamePlay::Piece color,
		Condition& condition,
		uint32_t depht,
		std::tuple<uint8_t, uint8_t> position,
		int8_t priority )
	{
		assert(color != IGamePlay::NONE);
		currentState.putPiece( std::get<0>( position ), std::get<1>( position ), color );
		auto newState = std::make_shared<State>( std::move(currentState ),
			position,
			( color == IGamePlay::WHITE ? IGamePlay::BLACK : IGamePlay::WHITE ),
			condition, depht, priority );
		_state.push_back( newState );
	}

	const std::list<std::shared_ptr<State>>& Choice::getState() const
	{
		return _state;
	}

}
