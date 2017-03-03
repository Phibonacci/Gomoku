#include <iostream>

#include "Phia.hpp"

namespace ia
{

	Phia::Phia( Logic::Game &game, const Logic::Player& player )
		:
		_game( game ),
		_color( player.color() ),
		_condition( 0, 3 ),
		_lastPosition( std::make_tuple(20, 20) )
	{
		if ( _color == IGamePlay::WHITE ) {
			_opColor = IGamePlay::BLACK;
		} else if ( _color == IGamePlay::BLACK ) {
			_opColor = IGamePlay::WHITE;
		}
	}

	void Phia::sync()
	{
		RGamePlay::GamePlay	&board = static_cast<RGamePlay::GamePlay&>( _game.gameplay() );

		_currentState = board.getArbitre();
	}

	void Phia::background()
	{
		// TODO
		// Beware, the call of the function is commented
	}

	Coord Phia::play()
	{
		Coord rt( 0, 0 );

		std::shared_ptr<State> tree = std::make_shared<State>( _currentState, _lastPosition, _opColor, _condition, 0 );
		tree->refreshChoiceValue();

		std::tuple<uint8_t, uint8_t> position;
		int32_t value = 0;
		bool set = false;
		for ( auto & e : tree->getChoice()->getState() ) {
			std::cout << "Possibility value: " << e->getValue() << std::endl;
			if (e->getValue() < value || !set) {
				set = true;
				value = e->getValue();
				position = e->getPosition();
			}
		}

		_currentState.putPiece( std::get<0>( position ), std::get<1>( position ), _color );
		rt.x = std::get<0>( position );
		rt.y = std::get<1>( position );
		return rt;
	}

	void Phia::opponentPlayed( Coord const& op )
	{
		_currentState.putPiece( op.x, op.y, _opColor );

		_lastPosition = std::make_tuple( static_cast<uint8_t>(op.x), static_cast<uint8_t>(op.y) );
	}

}
