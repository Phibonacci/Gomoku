#ifndef IGAMEPLAY_H_
# define IGAMEPLAY_H_

# include <exception>
# include <string>

class IPlayerInfo;
class IPieceInfo;

class IGamePlay
{
public:
  enum Piece {
	NONE,
	BLACK,
	WHITE
  };
  enum Rule {
	BASIC = 0,
	BREAKABLE5 = 1,
	DOUBLE3 = 2,
	BOTH = 3
  };

  class PlacementException : public std::exception
  {
	std::string		_msg;
  public:
	PlacementException(std::string msg) : _msg(msg){};
	virtual char const * what() const throw() {return _msg.c_str();}
	virtual ~PlacementException() throw() {};
  };

  virtual void		setRule(Rule) = 0;
  virtual Piece		getWinner() const = 0;
  virtual IPlayerInfo &getPlayerInfo(unsigned int playernum) = 0;
  virtual void		undoLastPlacement() = 0; //not yet fully implemented

  virtual void		putPiece(unsigned int, unsigned int) = 0;
  virtual Piece		getPiece(unsigned int, unsigned int) const = 0;
  virtual void		reinit() = 0;

  virtual Piece		currentPiece() const = 0;
  // to get info of a piece
  virtual IPieceInfo	*retrievePieceInfo(enum Piece, unsigned int, unsigned int) = 0;
  virtual ~IGamePlay() {}
};

# include "IPieceInfo.hh"
# include "IPlayerInfo.hh"

#endif /* !IGAMEPLAY_H_ */
