#include "RLine.hh"
#include "RPiece.hh"
#include "RGameBoard.hh"
#include "RPattern.hh"
#include "RPlayerInfo.hh"
#include "RGameArbitre.hh"
#include <iostream>
#include <stdexcept>

namespace RGamePlay
{
	RPattern RGameArbitre::RPieceToPut::getPattern(RGameBoard::DirectType dir)
	{
		RPiece &piece = _board[_coord.index];
		RLine const &line = piece.info.lines[dir];
		RPattern rt;
		bool	inited(false);
		unsigned int position = piece.getLinePosition(dir);

		rt.value = 0;
		rt.info.nbPiece = line.info.nbPiece;
		rt.info.leftBlocked = line.info.leftBlocked;
		rt.info.rightBlocked = line.info.rightBlocked;
		if (line.info.leftBlocked == RLine::NONE)
		{
			RGameBoard::Coord prev = _board.advanceCoord(_coord, dir,
									 -(2 + position));

			RPiece &pieceToConnect = _board[prev.index];

			RGameBoard::Coord prevt = _board.advanceCoord(_coord, dir,
									 -(1 + position));

			RPiece &pieceThrough= _board[prevt.index];
			if (!prev.outOfBound && pieceToConnect.color == _color && pieceThrough.color == 0)
			{
				inited = true;
				RLine const& lineToConnect = pieceToConnect.info.lines[dir];

				rt.info.nbPiece += lineToConnect.info.nbPiece;
				rt.info.splitted = true; // or put the position
				rt.info.leftBlocked = lineToConnect.info.leftBlocked;
			}
		}

		if (line.info.rightBlocked == RLine::NONE)
		{
			RGameBoard::Coord prev = _board.advanceCoord(_coord, dir,
									 +(1 + line.info.nbPiece - position));

			RPiece &pieceToConnect = _board[prev.index];
			RGameBoard::Coord prevt = _board.advanceCoord(_coord, dir,
									 +(line.info.nbPiece - position));

			RPiece &pieceThrough= _board[prevt.index];
			if (!prev.outOfBound && pieceToConnect.color == _color && pieceThrough.color == 0)
			{
				RLine const& lineToConnect = pieceToConnect.info.lines[dir];
				if (!inited)
				{
				inited = true;

				rt.info.nbPiece += lineToConnect.info.nbPiece;
				rt.info.splitted = true; // or put the position
				rt.info.rightBlocked = lineToConnect.info.rightBlocked;
				}
				else
				{
					RPattern another;
					another.value = 0;
					another.info.nbPiece = line.info.nbPiece + lineToConnect.info.nbPiece;
					another.info.leftBlocked = line.info.leftBlocked;
					another.info.splitted = true; // or put the position
					another.info.rightBlocked = lineToConnect.info.rightBlocked;

					if (another.info.nbPiece > rt.info.nbPiece)
						rt.value = another.value;

					// if (_color == IGamePlay::WHITE)
					//	std::cout << "white [" << _coord.x << _coord.y << "]" << std::endl;
					// else
					//	std::cout << "black [" << _coord.x << _coord.y << "]" << std::endl;
					//std::cout << "caution implementation may not be complete" << std::endl;
					//throw std::runtime_error("Not implemented");
				}
			}
		}
		rt.info.isBlocked = (rt.info.leftBlocked || rt.info.rightBlocked);
		return rt;
	}

	void RGameArbitre::RPieceToPut::updateLine(RGameBoard::DirectType dir, bool rec)
	{
		RPiece &piece = _board[_coord.index];
		RLine line = piece.info.lines[dir];
		int pos = piece.getLinePosition(dir);
		RGameBoard::Coord begin = _board.advanceCoord(_coord,
								  dir, -pos - 1);

		if (piece.color == 0)
			throw std::runtime_error("update-line1");
		if (rec && !begin.outOfBound
			)
		{
			RPiece &toUpdate =_board[begin.index];

			if (toUpdate.color == piece.color)
			{
				throw std::runtime_error("voilaBug1");
			}
			else if (toUpdate.color != 0)
			{
				toUpdate.info.lines[dir].info.rightBlocked = 1;
				RPieceToPut(_arbitre, piece.color, begin).updateLine(dir, false); //update the left line
			}
			_board[begin.index].init = 0;
		}
		// if (!begin.outOfBound)
		// {
		//	_board[begin.index].init = 0;
		// }

		begin = _board.advanceCoord(begin, dir, 1);
		//set prev flag
		for (unsigned int i = 0; i < line.info.nbPiece; ++i)
		{
			RPiece &toUpdate = _board[begin.index];
			if (begin != _coord)
			{
				toUpdate.info.lines[dir].value = line.value;
				toUpdate.setLinePosition(dir, i);
			}
			if (toUpdate.breakable && line.isBreakable() == 0)
			{
				toUpdate.breakable = 0;
				for (unsigned int i = 0; i < 4; ++i)
				{
					toUpdate.breakable |= toUpdate.info.lines[i].isBreakable();
				}
				if (toUpdate.breakable == 0 && rec)
				{
					for (unsigned int i = 0; i < 4; ++i)
					{
						if (toUpdate.info.lines[i].info.nbPiece >= 5)
							RPieceToPut(_arbitre, toUpdate.color, begin).internCheckWin(i);
					}
				}

			}
			toUpdate.breakable |= line.isBreakable();
			begin = _board.advanceCoord(begin, dir, 1);
		}

		if (rec && !begin.outOfBound  // && pos == line.info.nbPiece - 1 Optimisation?
			)
		{
			RPiece &toUpdate =_board[begin.index];

			if (toUpdate.color == piece.color)
			{
				throw std::runtime_error("voilaBug2");
			}
			else if (toUpdate.color != 0)
			{
				toUpdate.info.lines[dir].info.leftBlocked = 1;
				RPieceToPut(_arbitre, piece.color, begin).updateLine(dir, false); //update the left line
			}
			_board[begin.index].init = 0;
		}
		// if (!begin.outOfBound)
		// {
		//	_board[begin.index].init = 0;
		// }
	}

	RLine RGameArbitre::RPieceToPut::getLine(RGameBoard::DirectType dir)
	{
		unsigned int position = 0;
		RLine	line;
		RGameBoard::Coord	prev = _board.advanceCoord(_coord, dir, -1);
		RGameBoard::Coord	next = _board.advanceCoord(_coord, dir, 1);

		line.value = 0;
		line.info.nbPiece = 1;
		if (!prev.outOfBound)
		{
			RPiece &piece = _board[prev.index];

			if (piece.color == _color)
			{
				RLine &toConnect = piece.info.lines[dir];
				unsigned int pos = piece.getLinePosition(dir);

				line.info.nbPiece += toConnect.info.nbPiece;
				line.info.leftBlocked = toConnect.info.leftBlocked;
				position = pos + 1;
			}
			else if (piece.color != 0)
			{
				line.info.leftBlocked = RLine::ENEMY;
			}
		}
		else
		{
			line.info.leftBlocked = RLine::WALL;
		}

		if (!next.outOfBound)
		{
			RPiece &piece = _board[next.index];
			if (piece.color == _color)
			{
				RLine &toConnect = piece.info.lines[dir];

				line.info.nbPiece += toConnect.info.nbPiece;
				line.info.rightBlocked = toConnect.info.rightBlocked;
				//lines not inited
			}
			else if (piece.color != 0)
			{
				line.info.rightBlocked = RLine::ENEMY;
			}
		}
		else
		{
			line.info.rightBlocked = RLine::WALL;
		}
		_board[_coord.index].info.lines[dir] = line;
		_board[_coord.index].setLinePosition(dir, position);
		return line;
	}
}
