#include "RLine.hh"
#include "RPiece.hh"
#include "RGameBoard.hh"
#include "RPattern.hh"
#include "RPlayerInfo.hh"
#include "RGameArbitre.hh"
#include "RPieceInformation.hh"
#include "GamePlay.hh"
#include <iostream>
#include <stdexcept>

namespace RGamePlay
{
	RGameArbitre::RPieceToTry::RPieceToTry(RGameArbitre &ab,
		RGameBoard::Coord const& coord)
		: _arbitre(ab), _board(ab._board), _coord(coord)
	{}

	void RGameArbitre::RPieceToTry::tryPiece(RPieceInformation *toInit, IGamePlay::Piece color)
	{
		bool valide = true;
		unsigned int threes = 0;
		RPieceToPut		pieceToPut(_arbitre, color,
							  _coord);
		RPattern patterns[4];

		toInit->highestCount = 0;
		toInit->comboCount = 0;
		toInit->volunerable = 0;
		int nbPiece = 0;
		for (RGameBoard::DirectType i = 0; i < RGameBoard::dMax; ++i)
		{
			toInit->volunerable |= pieceToPut.getLine(i).isBreakable();
			patterns[i] = pieceToPut.getPattern(i);
			if (patterns[i].info.nbPiece > nbPiece)
			{
				toInit->highestCount = i;
				nbPiece = patterns[i].info.nbPiece;
			}
			if (patterns[i].info.nbPiece >= 3)
			{
				toInit->comboCount += (patterns[i].info.nbPiece - patterns[i].nbBlocked()) >= 3;
			}

			if (GamePlay::getRule() & IGamePlay::DOUBLE3)
			{
				if (patterns[i].info.nbPiece == 3 && patterns[i].info.isBlocked == false)
				{
					++threes;
					valide = !(threes >= 2);
				}
			}
			toInit->patterns[i] = patterns[i];
		}
		toInit->valide = valide;
		if (valide)
		{
			toInit->captureCount = 0;
			for (RGameBoard::DirectType i = 0; i < RGameBoard::dMax; ++i)
			{
				toInit->captureCount += pieceToPut.captureAble(i, 1);
				toInit->captureCount += pieceToPut.captureAble(i, -1);

				//set line for each direction
			}
			//to be set
		}
	}
}
