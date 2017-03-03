#include "TestRobot.hh"
#include <iostream>
TestRobot::TestRobot()
{}

void TestRobot::sync()
{
	std::cout <<"Test robot: " << "need resync" << std::endl;
}

void TestRobot::background()
{
	std::cout << "Test robot: " << "background" << std::endl;
}

Coord TestRobot::play()
{
	return Coord(0, 0);
}

void TestRobot::opponentPlayed(Coord const& op)
{
	std::cout << "Test robot: " << "opponent " << op.x << " "<< op.y << std::endl;
}

TestRobot::~TestRobot()
{}
