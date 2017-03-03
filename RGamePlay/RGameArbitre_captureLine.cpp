#include "RLine.hh"
#include "RPiece.hh"
#include "RGameBoard.hh"
#include "RPattern.hh"
#include "RPlayerInfo.hh"
#include "RGameArbitre.hh"
#include <iostream>
#include <stdexcept>
#include <cstring>
namespace RGamePlay
{
	bool RGameArbitre::RPieceToPut::captureAble(RGameBoard::DirectType dir, int i)
	{
		RGameBoard::Coord coordToCapture = _board.advanceCoord(_coord, dir, i);
		RPiece &toCapture = _board[coordToCapture.index];

		if (!coordToCapture.outOfBound && toCapture.color != _color && toCapture.color != 0)
		{
			RLine const& line = toCapture.info.lines[dir];

			if (line.info.nbPiece == 2)
			{
				return ((line.info.leftBlocked == RLine::ENEMY &&
					line.info.rightBlocked == RLine::NONE)
					|| (line.info.leftBlocked == RLine::NONE &&
						line.info.rightBlocked == RLine::ENEMY));
			}
		} //if out do nothing
		return false;
	}

	bool RGameArbitre::RPieceToPut::captureLine(RGameBoard::DirectType dir, int i)
	{
		RGameBoard::Coord coordToCapture = _board.advanceCoord(_coord, dir, i);
		RPiece &toCapture = _board[coordToCapture.index];

		if (!coordToCapture.outOfBound && toCapture.color != _color && toCapture.color != 0)
		{
			RLine const& line = toCapture.info.lines[dir];

			if (line.info.nbPiece == 2 &&
				line.info.leftBlocked == line.info.rightBlocked)
			{
				//_arbitre._board.debug();
				if (line.info.leftBlocked != RLine::ENEMY)
					throw std::runtime_error("Bug bad initialization");
				RPieceToRemove(_arbitre, coordToCapture).remove(dir);
				coordToCapture = _board.advanceCoord(coordToCapture, dir, i);
				RPieceToRemove(_arbitre, coordToCapture).remove(dir);
				return true;
			}
		} //if out do nothing
		return false;
	}

	RGameArbitre::RPieceToRemove::RPieceToRemove(RGameArbitre &ab,
		RGameBoard::Coord const& coord)
		: _arbitre(ab), _board(ab._board), _coord(coord)
	{}

	void RGameArbitre::RPieceToRemove::remove(RGameBoard::DirectType becauseOf)
	{
		for (RGameBoard::DirectType i = 0; i < RGameBoard::dMax; ++i)
		{
			if (i != becauseOf)
			{
				updateLine(i);
			}
			else
			{
				updateOpponentLine(i);
			}
		}
		_board[_coord.index].color = 0;
	}

	void RGameArbitre::RPieceToRemove::updateOpponentLine(RGameBoard::DirectType dir)
	{
		RPiece &piece = _board[_coord.index];
		int pos = piece.getLinePosition(dir);
		RGameBoard::Coord begin = _board.advanceCoord(_coord,
								  dir, -pos - 1);

		if (piece.color == 0)
		{
			throw std::runtime_error("caputre-updateline-bug1");
		}
		if (!begin.outOfBound // && pos == 0 Optimisation?
			)
		{
			RPiece &toUpdate =_board[begin.index];

			if (toUpdate.color == piece.color)
			{
				throw std::runtime_error("capture-updateline-bug2");
			}
			else if (toUpdate.color != 0)
			{
				toUpdate.info.lines[dir].info.rightBlocked = 0;
				RPieceToPut(_arbitre, toUpdate.color, begin).updateLine(dir, false); //update the left line
			}
		}
		begin = _board.advanceCoord(begin, dir, 3);
		//set prev flag
		if (!begin.outOfBound  // && pos == line.info.nbPiece - 1 Optimisation?
			)
		{
			RPiece &toUpdate =_board[begin.index];

			if (toUpdate.color == piece.color)
			{
				throw std::runtime_error("capture-updateline-bug3");
			}
			else if (toUpdate.color != 0)
			{
				toUpdate.info.lines[dir].info.leftBlocked = 0;
				RPieceToPut(_arbitre, toUpdate.color, begin).updateLine(dir, false); //update the left line
			}
		}
	}

	void RGameArbitre::RPieceToRemove::updateLine(RGameBoard::DirectType dir)
	{
		RPiece &piece = _board[_coord.index];
		RLine line = piece.info.lines[dir];
		int pos = piece.getLinePosition(dir);
		RGameBoard::Coord begin = _board.advanceCoord(_coord,
								  dir, -pos - 1);

		if (piece.color == 0)
		{
			throw std::runtime_error("caputre-updateline-bug1");
		}
		if (!begin.outOfBound // && pos == 0 Optimisation?
			)
		{
			RPiece &toUpdate =_board[begin.index];

			if (toUpdate.color == piece.color)
			{
				throw std::runtime_error("capture-updateline-bug2");
			}
				//	;
			else if (toUpdate.color != 0)
			{
				toUpdate.info.lines[dir].info.rightBlocked = 0;
				RPieceToPut(_arbitre, toUpdate.color, begin).updateLine(dir, false); //update the left line
			}
			else
				toUpdate.init = 0;
		}
		begin = _board.advanceCoord(begin, dir, 1);
		//set prev flag
		bool passed = false;
		RLine copy = line;

		memcpy(&copy, &line, sizeof(copy));
		copy.info.nbPiece = pos;
		copy.info.rightBlocked = RLine::NONE;
		for (unsigned int i = 0; i < line.info.nbPiece; ++i)
		{
			if (begin != _coord)
			{
				RPiece &toUpdate = _board[begin.index];

				if (passed)
				{
					//Right side
					toUpdate.setLinePosition(dir, i - pos - 1);
				}
				toUpdate.info.lines[dir].value = copy.value;
				toUpdate.init = 0;
				//resetInit?
			}
			else
			{
				//Right side mode
				memcpy(&copy, &line, sizeof(copy));
				copy.info.leftBlocked = RLine::NONE;
				copy.info.nbPiece = line.info.nbPiece - pos - 1;
				passed = true;
			}
			begin = _board.advanceCoord(begin, dir, 1);
		}
		if (!begin.outOfBound  // && pos == line.info.nbPiece - 1 Optimisation?
			)
		{
			RPiece &toUpdate =_board[begin.index];

			if (toUpdate.color == piece.color)
			{
				throw std::runtime_error("capture-updateline-bug3");
			}
			else if (toUpdate.color != 0)
			{
				toUpdate.info.lines[dir].info.leftBlocked = 0;
				RPieceToPut(_arbitre, toUpdate.color, begin).updateLine(dir, false); //update the left line
			}
			else
				toUpdate.init = 0;
		}
	}
}
