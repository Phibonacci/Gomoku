#ifndef GAMEPLAY_H_
# define GAMEPLAY_H_

# include "IGamePlay.hh"
# include <stack>

namespace RGamePlay{
	class RGameArbitre;
	struct RPlayerInfo;
class GamePlay : public IGamePlay
{
public:
	class PlayerInfo : public IPlayerInfo
	{

		RPlayerInfo		&_player;
	public:
		PlayerInfo(RPlayerInfo &player);
		virtual bool			hasWon(IGamePlay::Rule) const;
		virtual IGamePlay::Piece	getColor() const;
		virtual unsigned int		pieceEaten() const;
		virtual ~PlayerInfo() {}
	private:
		PlayerInfo(const PlayerInfo &);
		PlayerInfo &operator=(const PlayerInfo &);
	};

	GamePlay();
	static IGamePlay::Rule		getRule();
	virtual void		setRule(Rule);
	virtual Piece		getWinner() const;
	virtual IPlayerInfo &getPlayerInfo(unsigned int playernum);
	virtual void		undoLastPlacement(); //not yet fully implemented

	virtual void		putPiece(unsigned int, unsigned int);
	virtual Piece		getPiece(unsigned int, unsigned int) const;
	virtual void		reinit();

	virtual Piece		currentPiece() const;
  // to get info of a piece
	virtual IPieceInfo	*retrievePieceInfo(enum Piece, unsigned int, unsigned int);
	virtual ~GamePlay() {}

	void				changeHand();
	RGameArbitre		&getArbitre();
private:
	GamePlay(const GamePlay &);
	GamePlay &operator=(const GamePlay &);
protected:
	std::stack<RGameArbitre> _history;
	mutable RGameArbitre _arbitre;
	IGamePlay::Piece	_current;
	static IGamePlay::Rule		_rule;
	PlayerInfo *_players[2];
};
}

#endif /* !GAMEPLAY_H_ */
