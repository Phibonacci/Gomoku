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
#include <cstring>
namespace RGamePlay {
	RGameArbitre::RGameArbitre()
	{
		memset(_players, 0, sizeof(_players));
	}

	RGameArbitre::~RGameArbitre()
	{}


	IGamePlay::Piece	RGameArbitre::getWinner() const
	{
		if (_players[0].pieceCaptured >= 5 || _players[0].truewin)
			return IGamePlay::BLACK;
		if (_players[1].pieceCaptured >= 5 || _players[1].truewin)
			return IGamePlay::WHITE;
		return IGamePlay::NONE;
	}

	bool RGameArbitre::pieceInformationUpdated(unsigned int x, unsigned int y)
	{
		RGameBoard::Coord		coordToPut = _board.getCoord(x, y);
		RPiece &piece = _board[coordToPut.index];

		return !piece.init;
	}

	bool RGameArbitre::getPieceInformation(unsigned int x, unsigned int y,
										   RPieceInformation *toStore)
	{
		RGameBoard::Coord		coordToPut = _board.getCoord(x, y);
		RPiece &piece = _board[coordToPut.index];

		if (piece.color != 0)
			return false;
		RPieceToTry		pieceToTry(*this, coordToPut);

		pieceToTry.tryPiece(toStore, IGamePlay::BLACK);
		pieceToTry.tryPiece(toStore + 1, IGamePlay::WHITE);
		piece.init = true;
		return true;
	}


	bool RGameArbitre::putPiece(unsigned int x, unsigned int y,
		IGamePlay::Piece color)
	{
		RPiece::Lineinfo		newinfo;
		RGameBoard::Coord			coordToPut = _board.getCoord(x, y);
		RPieceToPut		pieceToPut(*this, color,
							  coordToPut);
		bool valide = true;
		unsigned int threes = 0;
		RPattern patterns[4];
		RPiece &piece = _board[coordToPut.index];

		if (piece.color != 0)
			return false;

		for (RGameBoard::DirectType i = 0; i < RGameBoard::dMax; ++i)
		{
			newinfo.lines[i] = pieceToPut.getLine(i); //get or not? hmm

			if (GamePlay::getRule() & IGamePlay::DOUBLE3)
			{
				patterns[i] = pieceToPut.getPattern(i);
				if (patterns[i].info.nbPiece == 3 && patterns[i].info.isBlocked == false)
				{
					++threes;
					if (threes >= 2)
					{
						std::cout << "Double Three" << std::endl;
						valide = false;
						//Init double Three optimisation if needed
					}
				}
			}
		}

		if (!valide)
		{
			//reset piece? whatever, lineinfo shouldn't be used if empty anyway
			return false;
		}
		//if valide

		//Maybe encapstule those in RPieceToPut

		piece.setColor(color);
		piece.info.value = newinfo.value;
		for (RGameBoard::DirectType i = 0; i < RGameBoard::dMax; ++i)
		{
			pieceToPut.updateLine(i);
			if (newinfo.lines[i].info.nbPiece >= 5)
			{
				if (pieceToPut.checkWin(i))
					_players[color - 1].truewin = true;
			}
		}

		//_board.debug();
		//Capture

		int captureCount = 0;
		for (RGameBoard::DirectType i = 0; i < RGameBoard::dMax; ++i)
		{
			captureCount += pieceToPut.captureLine(i, 1);
			captureCount += pieceToPut.captureLine(i, -1);
			//set line for each direction
		}
		_players[color - 1].pieceCaptured += captureCount;
		//Capture end;

		return true;
	}

	RPiece	const	&RGameArbitre::getPiece(unsigned int x, unsigned int y)
	{
		RGameBoard::Coord place = _board.getCoord(x, y);

		return _board[place.index];
	}

	RPlayerInfo &RGameArbitre::getPlayer(unsigned int num)
	{
		return _players[num];
	}

	void				RGameArbitre::reinit()
	{
		_board.reinit();
		memset(_players, 0, sizeof(_players));
	}

	RGameArbitre::RPieceToPut::RPieceToPut(RGameArbitre &ab, unsigned int color,
		RGameBoard::Coord const &coord)
		: _arbitre(ab), _board(ab._board), _color(static_cast<IGamePlay::Piece>(color)), _coord(coord)
	{}

	RGameArbitre::RPieceToPut::RPieceToPut(RGameArbitre &ab, IGamePlay::Piece color,
		RGameBoard::Coord const &coord)
		: _arbitre(ab), _board(ab._board), _color(color), _coord(coord)
	{}


	//PlayerInfoPart
}
