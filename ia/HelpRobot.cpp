#include "HelpRobot.hh"
#include <iostream>
#include "Priority.hh"
#include "Node.hh"
#include "Transition.hh"
#include <unistd.h>
namespace ia{
HelpRobot::HelpRobot(Logic::Game &game, Logic::Player const& player)
	: _game(game), _color(player.color())
{
	if (_color == IGamePlay::WHITE)
		_opColor = IGamePlay::BLACK;
	else if (_color == IGamePlay::BLACK)
		_opColor = IGamePlay::WHITE;
}

void HelpRobot::sync()
{
	RGamePlay::GamePlay	&board = static_cast<RGamePlay::GamePlay&>(_game.gameplay());

	_oldChoices.clear();
	_currentState = board.getArbitre();
}

void HelpRobot::background()
{
}

	void HelpRobot::iter()
	{
		if (!_toEvaluateList.empty())
		{
			Node		*toEvaluate = _toEvaluateList.front();

			_toEvaluateList.pop_front();
			toEvaluate->initializeChoices();
			for (unsigned int i = 0; i < toEvaluate->nbChoices; ++i)
			{
				toEvaluate->evaluateChoice(i);
				if (toEvaluate->choices[i].values[0].result != NULL)
				_toEvaluateList.push_back(toEvaluate->choices[i].values[0].result);
				if (toEvaluate->choices[i].values[1].result != NULL)
				_toEvaluateList.push_back(toEvaluate->choices[i].values[1].result);
			}

		}
	}

Coord HelpRobot::play()
{
	Coord rt(0, 0);
	Node *root = new Node();
	root->arbitre = new RGamePlay::RGameArbitre(_currentState);

	_toEvaluateList.clear();
	root->initializeChoices();
	for (unsigned int i = 0; i < root->nbChoices; ++i)
	{
		auto it = std::find(_oldChoices.begin(), _oldChoices.end(), root->choices[i]);
		if (it != _oldChoices.end())
		{
			_oldChoices.erase(it);
		}
		root->evaluateChoice(i);
		if (root->choices[i].values[0].result)
		_toEvaluateList.push_back(root->choices[i].values[0].result);
		if (root->choices[i].values[1].result)
		_toEvaluateList.push_back(root->choices[i].values[1].result);
	}
	int i = 0;
	while (!_toEvaluateList.empty() && i < 100)
	{
		iter();
		++i;
	}

	root->updateChildValue();

	Transition *best = root->getBestChoice(_color - 1);

	auto it = std::max_element(_oldChoices.begin(), _oldChoices.end(),
			  [](Transition const& a, Transition const& b) {return a.level < b.level;});
	if (it != _oldChoices.end())
		best = &(*it);


	int self = _color - 1;
	for (unsigned int i = 0; i < root->nbChoices; ++i)
	{
		if (root->choices[i].values[self].value != Priority::INVALIDE)
		{
		if (best == nullptr)
		{
			best = root->choices + i;
		}
		else if (best->level < root->choices[i].level)
		{
			_oldChoices.push_front(*best);
			best = root->choices + i;
		}
		else if (best->level == root->choices[i].level)
		{
			if (best->values[self].value < root->choices[i].values[self].value)
			{
				best = root->choices + i;
				_oldChoices.push_front(*best);
			}
			else if (best->values[self].value == root->choices[i].values[self].value && std::rand() % 10 >= 8)
			{
				_oldChoices.push_front(*best);
				best = root->choices + i;
			}
		}
		else
			_oldChoices.push_back(root->choices[i]);
		}
	}

	// std::for_each(_oldChoices.begin(), _oldChoices.end(),
	//	[](Transition const& a) { std::cout << a.x << " " << a.y << std::endl;});
	//Evaluation
	rt.x = best->x;
	rt.y = best->y;

	_currentState.putPiece(rt.x, rt.y, _color);

	it = std::find(_oldChoices.begin(), _oldChoices.end(), *best);
	if (it != _oldChoices.end())
	{
		std::cout << "choice removed" << std::endl;
		_oldChoices.erase(it);
	}
	std::cout << "Level estimated:" << best->level << std::endl;
	delete root;
	return rt;
}

void HelpRobot::opponentPlayed(Coord const& op)
{
	_currentState.putPiece(op.x, op.y, _opColor);
	Transition tmp;
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
