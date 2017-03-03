#include "MinRobot.hh"
#include <iostream>
#include "Priority.hh"
#include "MinNode.hh"
#include "MinTransition.hh"
#include <unistd.h>
#include <cmath>
#include <cassert>
namespace ia{
MinRobot::MinRobot(Logic::Game &game, Logic::Player const& player)
	: _game(game), _color(player.color())
{
	if (_color == IGamePlay::WHITE)
		_opColor = IGamePlay::BLACK;
	else if (_color == IGamePlay::BLACK)
		_opColor = IGamePlay::WHITE;
}

void MinRobot::sync()
{
	RGamePlay::GamePlay	&board = static_cast<RGamePlay::GamePlay&>(_game.gameplay());

	_oldChoices.clear();
	_currentState = board.getArbitre();

}

void MinRobot::background()
{
	//	iter();
}

	void MinRobot::iter(unsigned already, unsigned max)
	{
		if (!_toEvaluateList.empty())
		{
			MinNode		*toEvaluate = _toEvaluateList.front();

			_toEvaluateList.pop_front();
			for (unsigned int i = 0; i < toEvaluate->nbChoices; ++i)
			{
				if (!toEvaluate->evaluateChoice(i))
				{
					if (already + _toEvaluateList.size() < max)
						_toEvaluateList.push_back(toEvaluate->choices[i].result);
					toEvaluate->choices[i].result->initializeChoices(toEvaluate->choices, toEvaluate->nbChoices);
				}
			}
		}
	}

Coord MinRobot::play()
{
	Coord rt(0, 0);
	MinNode *root = new MinNode();
	root->color_turn = _color;
	root->arbitre = new RGamePlay::RGameArbitre(_currentState);

	_toEvaluateList.clear();
	MinTransition *oldChoices = new MinTransition[_oldChoices.size()];
	std::copy(_oldChoices.begin(), _oldChoices.end(), oldChoices);
	root->initializeChoices(oldChoices, _oldChoices.size());
	delete []oldChoices;
	std::cout << _oldChoices.size() << std::endl;
	_oldChoices.clear();


	int	bestScore = root->calculateScore(-200, 200);
	int idx = std::rand() % root->nbChoices;
	MinTransition *best = NULL;
	int			 bestidx = 0;

	assert(root->nbChoices > 0);
	for (unsigned int i = 0; i < root->nbChoices; ++i)
	{
		if (!root->choices[i].init)
		{
			_oldChoices.push_back(root->choices[i]);
			continue;
		}
		int score1 = root->choices[i].getScore(_color == IGamePlay::BLACK);
		if (score1 == bestScore)
		{
			if (best == NULL || std::abs(idx - bestidx) < std::abs(idx - i))
			{
				if (best)
					_oldChoices.push_back(*best);
				best = root->choices + i;
				bestidx = i;
			}
		}
		else
			_oldChoices.push_back(root->choices[i]);
	}
	assert(best != nullptr);
	rt.x = best->x;
	rt.y = best->y;

	_currentState.putPiece(rt.x, rt.y, _color);

	auto it = std::find(_oldChoices.begin(), _oldChoices.end(), *best);
	if (it != _oldChoices.end())
	{
		std::cout << "choice removed" << std::endl;
		_oldChoices.erase(it);
	}
	std::cout << "Level " << best->level << std::endl;
	delete root;
	return rt;
}

void MinRobot::opponentPlayed(Coord const& op)
{
	_currentState.putPiece(op.x, op.y, _opColor);
	MinTransition tmp;
	tmp.x = op.x;
	tmp.y = op.y;
	auto it = std::find(_oldChoices.begin(), _oldChoices.end(), tmp);
	if (it != _oldChoices.end())
	{
		std::cout << "choice removed" << std::endl;
		_oldChoices.erase(it);
	}
	//Store op?
}

}
