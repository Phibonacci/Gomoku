#ifndef IROBOT_H_
# define IROBOT_H_

# include "Coord.hh"

class IRobot
{
public:


	/*
	**
	** this will be called when the board need to be resync
	**
	*/
	virtual void sync() = 0;


	/*
	**
	** this will be called to iterate on background
	**
	*/
	virtual void background() = 0;


	/*
	**
	** this will be called to get the position
	**
	*/
	virtual Coord play() = 0;

	/*
	**
	** this will be called when opponent played at some position
	**
	*/
	virtual void opponentPlayed(Coord const&) = 0;
	virtual ~IRobot() {}
};

#endif /* !IROBOT_H_ */
