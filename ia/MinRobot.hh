#ifndef MINROBOT_H_
# define MINROBOT_H_

# include "IRobot.hh"
# include "Logic.hh"
# include "RGamePlay.hh"
namespace ia{
	struct MinTransition;
	struct MinNode;
class MinRobot : public IRobot
{
	Logic::Game	&_game;
	IGamePlay::Piece _color;
	IGamePlay::Piece _opColor;
	std::list<MinTransition>	_oldChoices;
	RGamePlay::RGameArbitre _currentState;
	std::list<MinNode*>			_toEvaluateList;
	//MinNode						*_root;
public:
	MinRobot(Logic::Game &, Logic::Player const&);
	virtual void sync();
	virtual void background();
	virtual Coord play();
	virtual void opponentPlayed(Coord const&);
	void		 iter(unsigned already, unsigned max);
};

}

#endif /* !MINROBOT_H_ */
