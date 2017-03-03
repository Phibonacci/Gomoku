#include "RLine.hh"
#include "RPiece.hh"
#include "RGameBoard.hh"
#include "RPattern.hh"
#include "RPlayerInfo.hh"
#include "RGameArbitre.hh"
#include "GamePlay.hh"
#include <iostream>
#include <stdexcept>

namespace RGamePlay
{
	bool RGameArbitre::RPieceToPut::checkWin(RGameBoard::DirectType dir)
	{
		RPiece &piece = _board[_coord.index];
		RLine line = piece.info.lines[dir];
		int pos = piece.getLinePosition(dir);
		RGameBoard::Coord begin = _board.advanceCoord(_coord,
								  dir, -pos);

		unsigned int count = 0;

		if (!(GamePlay::getRule() & IGamePlay::BREAKABLE5))
			return line.info.nbPiece >= 5;
		for (unsigned int i = 0; i < line.info.nbPiece; ++i)
		{
			RPiece &toCheck = _board[begin.index];

			toCheck.breakable = 0;
			for (unsigned int i = 0; i < 4; ++i)
			{
				toCheck.breakable |= toCheck.info.lines[i].isBreakable();
			}
			if (toCheck.breakable)
				count = 0;
			else
				++count;
			if (count == 5)
				break;
			begin = _board.advanceCoord(begin, dir, 1);
		}
		return count >= 5;
	}

	void RGameArbitre::RPieceToPut::internCheckWin(RGameBoard::DirectType dir)
	{
		if (checkWin(dir))
			_arbitre._players[_color - 1].truewin = true;
	}
}
