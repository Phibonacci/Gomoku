#ifndef HELPROBOT_H_
# define HELPROBOT_H_

# include "IRobot.hh"
# include "Logic.hh"
# include "RGamePlay.hh"
namespace ia{
	struct Transition;
	struct Node;
class HelpRobot : public IRobot
{
	Logic::Game	&_game;
	IGamePlay::Piece _color;
	IGamePlay::Piece _opColor;
	std::list<Transition>	_oldChoices;
	RGamePlay::RGameArbitre _currentState;
	std::list<Node*>			_toEvaluateList;
public:
	HelpRobot(Logic::Game &, Logic::Player const&);
	virtual void sync();
	virtual void background();
	virtual Coord play();
	virtual void opponentPlayed(Coord const&);
	void		 iter();
};

}

#endif /* !HELPROBOT_H_ */
