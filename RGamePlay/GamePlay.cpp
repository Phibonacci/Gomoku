#include "RLine.hh"
#include "RPiece.hh"
#include "RPlayerInfo.hh"
#include "RGameBoard.hh"
#include "RGameArbitre.hh"
#include "GamePlay.hh"
#include <iostream>
#include "Context.hh"
#include "RGamePlay.hh"
namespace RGamePlay
{
	IGamePlay::Rule		GamePlay::_rule = IGamePlay::BOTH;

	GamePlay::PlayerInfo::PlayerInfo(RPlayerInfo & pl)
		: _player(pl) {}

	bool GamePlay::PlayerInfo::hasWon(IGamePlay::Rule r) const
	{
		if (_player.pieceCaptured >= 5)
			return true;
		if (r & BREAKABLE5)
			return _player.truewin;
		return _player.truewin || _player.fakewin;
	}
	IGamePlay::Piece	GamePlay::PlayerInfo::getColor() const
	{
		return static_cast<IGamePlay::Piece>(_player.color);
	}
	unsigned int		GamePlay::PlayerInfo::pieceEaten() const
	{
		return _player.pieceCaptured * 2;
	}

	GamePlay::GamePlay()
		: _current(BLACK)
	{
		_players[0] = new PlayerInfo(_arbitre.getPlayer(0));
		_players[1] = new PlayerInfo(_arbitre.getPlayer(1));
		_rule = BOTH;
	}

	void		GamePlay::setRule(IGamePlay::Rule r)
	{
		_rule = r;
	}

	RGameArbitre			&GamePlay::getArbitre()
	{
		return _arbitre;
	}

	IGamePlay::Piece		GamePlay::getWinner() const
	{
		if (_players[0]->hasWon(_rule))
			return IGamePlay::BLACK;
		if (_players[1]->hasWon(_rule))
			return IGamePlay::WHITE;
		return IGamePlay::NONE;
	}

	IPlayerInfo &GamePlay::getPlayerInfo(unsigned int playernum)
	{
		return *_players[playernum];
	}

	void		GamePlay::undoLastPlacement()
	{
		//no more undo
		if (!_history.empty())
		{
			_arbitre = _history.top();
			changeHand();
			_history.pop();
			_arbitre._board.debug();
			Context::getInstance()->getWindow()->setScore(0, _players[0]->pieceEaten());
			Context::getInstance()->getWindow()->setScore(1, _players[1]->pieceEaten());
		}
	}

	void		GamePlay::changeHand()
	{
		switch (_current)
		{
			case BLACK:
				_current = WHITE;
				break;
			case WHITE:
				_current = BLACK;
				break;
			default:
				break;
		}
		//no more undo
	}

	void		GamePlay::putPiece(unsigned int x, unsigned int y)
	{
		RGameArbitre before(_arbitre);
		if (_arbitre.putPiece(x, y, _current) == true)
		{
			changeHand();
			_history.push(RGameArbitre(before));
			Context::getInstance()->getWindow()->setScore(0, _players[0]->pieceEaten());
			Context::getInstance()->getWindow()->setScore(1, _players[1]->pieceEaten());
		}
		else
		{
			throw IGamePlay::PlacementException("You can't put there");
		}
	}

	IGamePlay::Piece		GamePlay::getPiece(unsigned int x, unsigned int y) const
	{
		return static_cast<IGamePlay::Piece>((_arbitre).getPiece(x, y).color);
	}

	void		GamePlay::reinit()
	{
		while (!_history.empty())
			_history.pop();
		_arbitre.reinit();
		_current = IGamePlay::BLACK;
	}

	IGamePlay::Piece		GamePlay::currentPiece() const
	{
		return _current;
	}

	std::ostream &operator<<(std::ostream &os, RPieceInformation const &info)
	{
		if (!info.valide)
			os << "can not be put";
		if (info.captureCount > 0)
		{
			os << (int)info.captureCount;
		}
		for (unsigned int i = 0; i < 4; ++i)
		{
			if (info.patterns[i].info.nbPiece > 2)
			{
				os << std::endl;
				if (info.patterns[i].info.leftBlocked)
					os << "X";
				else
					os << "<";
				os << (int)info.patterns[i].info.nbPiece;
				if (info.patterns[i].info.rightBlocked)
					os << "X";
				else
					os << ">";
			}
		}
		return os;
	}

	IPieceInfo	*GamePlay::retrievePieceInfo(IGamePlay::Piece, unsigned int x, unsigned int y)
	{
		RPieceInformation infos[2];

		if (_arbitre.getPieceInformation(x, y, infos))
		{
			std::cout << x << " " << y << " has been updated" << std::endl;
			std::cout << "Black: " << infos[0] << std::endl;
			std::cout << "White: " << infos[1] << std::endl;
		}
		return NULL;
	}

	IGamePlay::Rule				GamePlay::getRule()
	{
		return _rule;
	}
}
