#ifndef TESTROBOT_H_
# define TESTROBOT_H_

# include "IRobot.hh"

class TestRobot : public IRobot
{
public:
	TestRobot();
	virtual void sync();
	virtual void background();
	virtual Coord play();
	virtual void opponentPlayed(Coord const&);
	virtual ~TestRobot();
};

#endif /* !TESTROBOT_H_ */
