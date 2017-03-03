#ifndef AROBOT_H_
# define AROBOT_H_

# include "IGamePlay.hh"
# include "RGamePlay.hh"
# include "Coord.hh"

namespace ia {
class ARobot
{
	RGamePlay::GamePlay &_game;
	IGamePlay::Piece	_color;
	bool		isBetter(RGamePlay::RPieceInformation *one, RGamePlay::RPieceInformation *two);
	bool		isInteresting(RGamePlay::RPieceInformation *one);
public:
	ARobot(RGamePlay::GamePlay &game, IGamePlay::Piece color);
	virtual Coord decide();
	virtual ~ARobot() {}

private:
	ARobot(const ARobot &);
	ARobot &operator=(const ARobot &);
protected:
};
}

#endif /* !AROBOT_H_ */
