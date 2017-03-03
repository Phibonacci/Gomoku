#include <algorithm>
#include "RLine.hh"
#include "RPiece.hh"
#include "RGameBoard.hh"
#include <cstring>
#include <iostream>
#include <stdexcept>
namespace RGamePlay {

	unsigned int const RGameBoard::dMax = 4;

	RGameBoard::RGameBoard(unsigned int x, unsigned int y)
		: _sizex(x), _sizey(y)
	{
		RPiece initial;

		memset(&initial, 0, sizeof(initial));
		initial.init = 1;
		std::fill(_pieces, _pieces + x * y, initial);
	}

	RGameBoard::~RGameBoard()
	{
		//delete[] _pieces;
	}


	void		debugPiece(RPiece &piece)
	{
		for (int i = 0; i < 4; ++i)
		{
			RLine &ci = piece.info.lines[i];
			if (ci.info.nbPiece != RLine::NONE)
			{
				std::cout << i << "dir " << (int)ci.info.nbPiece << "align";
				if (ci.info.leftBlocked)
					std::cout << "X";
				else
					std::cout << "|";

				for (unsigned int count = 0; count < ci.info.nbPiece; ++count)
				{
					if (piece.getLinePosition(i) == count)
						std::cout << "*";
					else
						std::cout << " ";
				}
				if (ci.info.rightBlocked != RLine::NONE)
					std::cout << "X";
				else
					std::cout << "|";
				std::cout << std::endl;
			}
		}
	}

	void		RGameBoard::debug()
	{
		for (unsigned int i = 0; i < _sizex * _sizey; ++i)
		{
			RPiece &piece = _pieces[i];

			if (piece.breakable)
				std::cout << "*Danger*";
			switch (piece.color)
			{
				case 0:
					break;
				case 1:
					std::cout << "BLACK[" << (i / _sizex) << " " << (i % _sizex) << "]";
					debugPiece(piece);
					break;
				case 2:
					std::cout << "WHITE[" << (i / _sizex) << " " << (i % _sizex) << "]";
					debugPiece(piece);
					break;
				default:
					throw std::runtime_error("Memory bug");
			}
		}
	}

	RGameBoard::Coord
	RGameBoard::advanceCoord(Coord coord,
		RGameBoard::DirectType direction,
		int multiplier) const
	{
		int x = multiplier, y = multiplier;

		switch (direction)
		{
			case 0:
				y = 0;
				break;
			case 1:
				break;
			case 2:
				x = 0;
				break;
			case 3:
				y = -y;
				break;
			default:
				throw std::runtime_error("unknown direction");
		}
		coord.x += x;
		coord.y += y;
		coord.index = getIndex(coord.x, coord.y);
		coord.outOfBound = !inBound(coord.x, coord.y);
		return coord;
	}


	int RGameBoard::getDistance(RGameBoard::Coord const& begin,
		RGameBoard::Coord const& end, RGameBoard::DirectType dir) const
	{
		int x = 1, y = 1;
		int rt = -42;
		switch (dir)
		{
			case 0:
				y = 0;
				break;
			case 1:
				break;
			case 2:
				x = 0;
				break;
			case 3:
				y = -y;
				break;
			default:
				throw std::runtime_error("unknown direction");
		}
		if (x != 0)
			rt = (end.x - begin.x) / x;
		if (y != 0)
			rt = (end.y - begin.y) / y;
		if (rt == -42)
			throw std::runtime_error("impossible");
		return rt;
	}

	RGameBoard::Coord	RGameBoard::getCoord(unsigned int x, unsigned int y) const
	{
		return Coord(x, y, getIndex(x, y), inBound(x, y));
	}

	unsigned int RGameBoard::getIndex(unsigned int x, unsigned int y) const
	{
		return (y * _sizey + x);
	}

	bool		RGameBoard::inBound(unsigned int x, unsigned int y) const
	{
		return (x < _sizex && y < _sizey);
	}

	RPiece &	RGameBoard::operator[](unsigned int idx)
	{
		return _pieces[idx];
	}

	RGameBoard::Coord::Coord(unsigned int Px, unsigned int Py,
		unsigned int Pindex, bool outBound)
		: x(Px), y(Py), index(Pindex), outOfBound(outBound)
	{}

	bool		RGameBoard::Coord::operator!=(Coord const& c) const
	{
		return !(x == c.x && y == c.y);
	}

	void		RGameBoard::reinit()
	{
		RPiece initial;

		memset(&initial, 0, sizeof(initial));
		initial.init = 1;
		std::fill(_pieces, _pieces + sizeof(_pieces) / sizeof(*_pieces), initial);
	}
}
