#ifndef PHIA_HPP
#define PHIA_HPP

#include "IRobot.hh"
#include "Coord.hh"
#include "Logic.hh"
#include "RGamePlay.hh"
#include "Choice.hpp"
#include "State.hpp"
#include "Condition.hpp"

namespace ia
{

	class Phia : public IRobot
	{
		Logic::Game&					_game;
		IGamePlay::Piece				_color;
		IGamePlay::Piece				_opColor;
		RGamePlay::RGameArbitre			_currentState;
		std::shared_ptr<State>			_tree;
		Condition						_condition;
		std::tuple<uint8_t, uint8_t>	_lastPosition;

	public:
		Phia( Logic::Game &game, const Logic::Player& player );

		/*
		** this will be called when the board need to be resync
		*/
		virtual void					sync();

		/*
		** this will be called to iterate on background
		*/
		virtual void					background();

		/*
		** this will be called to get the position
		*/
		virtual Coord					play();

		/*
		** this will be called when opponent played at some position
		*/
		virtual void					opponentPlayed( const Coord& );
	};

}

#endif // !PHIA_HPP
