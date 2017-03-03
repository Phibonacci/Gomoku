#include "RGamePlay.hh"
#include "Priority.hh"
#include "Transition.hh"
#include "Node.hh"
#include <stdexcept>
#include <iostream>
#include <list>
#include <algorithm>
#include <cstring>
#include <cassert>

namespace ia
{
	void		Node::initializeChoices()
	{
		if (!arbitre)
		{
			throw std::runtime_error("state not initialized");
		}
		RGamePlay::RPieceInformation	infos[2];
		std::list<Transition>			temporary;

		for (unsigned int i = 0; i < 19 * 19; ++i)
		{
			if (!arbitre->pieceInformationUpdated(i % 19, i / 19))
				continue;
			if (arbitre->getPieceInformation(i % 19, i / 19, infos))
			{
				Transition		possible;

				memset(&possible, 0, sizeof(possible));
				possible.x = i % 19;
				possible.y = i / 19;
				possible.values[0].value = Priority(infos).getPriority();
				possible.values[1].value = Priority(infos + 1).getPriority();
				possible.updateLevel();
				temporary.push_back(possible);
			}
		}

		this->nbChoices = temporary.size();
		this->choices = new Transition[this->nbChoices];
		std::copy(temporary.begin(), temporary.end(), this->choices);
	}

	void	Node::evaluateChoice(unsigned int idx)
	{
		assert(idx < this->nbChoices);

		Transition *toEvaluate = this->choices + idx;

		for (int i = 0; i < 2; ++i)
		{
			IGamePlay::Piece color = static_cast<IGamePlay::Piece>(i + 1);

			toEvaluate->values[i].result = NULL;
			if (this->depth[i] <= 3 && toEvaluate->values[i].value > Priority::INVALIDE)
			{
				Node *result = new Node(this, toEvaluate, i);

				result->parent.color = color;
				if (result->arbitre->putPiece(toEvaluate->x, toEvaluate->y,
						color))
				{
					toEvaluate->values[i].result = result;
					IGamePlay::Piece winner = result->arbitre->getWinner();
					if (winner != IGamePlay::NONE)
					{
						// assert(winner == color);
						if (winner == color)
							toEvaluate->values[i].value = Priority::WIN;
						else
							toEvaluate->values[i].value = Priority::LOSE;
					}
				}
				else
					assert(false);
			}
		}
	}

	void	Node::updateParentValue()
	{
		assert(parent.parent != NULL);
		assert(parent.choice != NULL);

		if (choices == NULL)
			return ;
		int				self = this->parent.color - 1;
		Transition		*bestOp = NULL;
		Transition		*guarantee = NULL;

		assert(self == 1 || self == 0);
		for (unsigned int i = 0; i < this->nbChoices; ++i)
		{
			if (bestOp == NULL)
			{
				bestOp = this->choices + i;
			}
			else if (bestOp->level < this->choices[i].level)
			{
				bestOp = this->choices + i;
			}
		}
		//Eliminate opponent choice
		for (unsigned int i = 0; i < this->nbChoices; ++i)
		{
			if (this->choices + i != bestOp)
			{
				if (guarantee == NULL)
				{
					guarantee = this->choices + i;
				}
				else if (guarantee->values[self].value < this->choices[i].values[self].value)
				{
					guarantee = this->choices + i;
				}
			}
		}
		if (!guarantee)
		{
			return ;
		}

		if (guarantee->values[self].value < bestOp->values[!self].value)
		{
			this->parent.choice->values[self].value = Priority::USELESS;
		}
		else
		{
			this->parent.choice->values[self].value = guarantee->level;
		}
	}

	void		Node::updateChildValue()
	{
		for (unsigned int i = 0; i < this->nbChoices; ++i)
		{
			if (this->choices[i].values[0].result)
				this->choices[i].values[0].result->updateChildValue();
			if (this->choices[i].values[1].result)
				this->choices[i].values[1].result->updateChildValue();
			this->choices[i].updateLevel();
		}
		if (this->parent.parent != NULL)
			updateParentValue();
	}

	Transition * Node::getBestChoice(unsigned int color)
	{
		Transition *rt = NULL;

		assert(choices != NULL);
		for (unsigned int i = 0; i < this->nbChoices; ++i)
		{
			if (rt == NULL || rt->values[color].value < choices[i].values[color].value)
				rt = choices + i;
		}
		return rt;
	}

	Node::Node()
	{
		memset(this, 0, sizeof(*this));
	}

	Node::Node(Node *parent, Transition *causedby, int dindex)
	{
		memcpy(this, parent, sizeof(*this));
		this->parent.parent = parent;
		this->parent.choice = causedby;
		this->nbChoices = 0;
		this->choices = NULL;
		this->depth[dindex] += 1;
		this->arbitre = new RGamePlay::RGameArbitre(*(parent->arbitre));
	}

	Node::~Node()
	{
		for (unsigned int i = 0; i < this->nbChoices; ++i)
		{
			choices[i].cleanUp();
		}
		delete[] choices;
		delete arbitre;
	}
}
