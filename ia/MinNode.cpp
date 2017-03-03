#include "RGamePlay.hh"
#include "Priority.hh"
#include "MinTransition.hh"
#include "MinNode.hh"
#include "Game.hh"
#include <stdexcept>
#include <iostream>
#include <list>
#include <algorithm>
#include <cstring>
#include <cassert>

namespace ia
{
	bool found(unsigned x, unsigned y, MinTransition *oldones, unsigned int size)
	{
		MinTransition one;

		one.x = x;
		one.y = y;
		MinTransition *it = std::find(oldones, oldones + size, one);

		return it != oldones + size;
	}

	int		MinNode::calculateScore(int alpha, int belta)
	{
		IGamePlay::Piece winner = arbitre->getWinner();
		if (winner != IGamePlay::NONE)
		{
			if (winner == IGamePlay::BLACK)
				return Priority::WIN;
			else
				return Priority::LOSE;
		}

		if (this->parent.parent)
			this->initializeChoices(this->parent.parent->choices,
				this->parent.parent->nbChoices);
		if (depth > (Logic::AiLevel / 2) + 1)
			return score;

		unsigned max = (10 - depth * 3) < 3 ? 3 : ((10- depth * 3));
		for (unsigned int i = 0; i < this->nbChoices && i < max; ++i)
		{
			this->evaluateChoice(i);
		}
		int		value = 0;
		bool	init = false;

		if (color_turn == IGamePlay::BLACK)
		{
			for (unsigned i = 0; i < this->nbChoices && i < max; ++i)
			{
				MinTransition &e = this->choices[i];
				e.initScore(alpha, belta);
				if (!init)
				{
					value = e.getScore(true);
					init = true;
				}
				else
				{
					value = std::max(value, e.getScore(true));
				}
				alpha = std::max(alpha, value);
				if (belta <= alpha)
				{
					break;
				}
			}
		}
		else
		{
			for (unsigned i = 0; i < this->nbChoices && i <	max; ++i)
			{
				MinTransition &e = this->choices[i];
				e.initScore(alpha, belta);
				if (!init)
				{
					value = e.getScore(false);
					init = true;
				}
				else
				{
					value = std::min(value, e.getScore(false));
				}
				belta = std::min(belta, value);
				if (belta <= alpha)
				{
					break;
				}
			}
		}
		for (unsigned i = 0; i < this->nbChoices; ++i)
		{
			delete this->choices[i].result;
			this->choices[i].result = nullptr;
		}
		assert(init);
		return value;
	}

	void		MinNode::initializeChoices(MinTransition *oldones, unsigned int size)
	{
		if (!arbitre)
		{
			throw std::runtime_error("state not initialized");
		}
		RGamePlay::RPieceInformation	infos[2];
		std::list<MinTransition>		temporary;

		int		self = color_turn - 1;

		this->score = 0;
		for (unsigned int i = 0; i < 19 * 19; ++i)
		{
			if (!found(i % 19, i / 19, oldones, size) &&
				!arbitre->pieceInformationUpdated(i % 19, i / 19))
				continue;
			if (arbitre->getPieceInformation(i % 19, i / 19, infos))
			{
				MinTransition		possible;
				int					potential = 0;
				Priority black(infos);
				Priority white(infos + 1);

				memset(&possible, 0, sizeof(possible));
				if (black.getPriority() > 0)
					potential += black.getPriority();
				if (white.getPriority() > 0)
					potential -= white.getPriority();
				score += potential;

				memset(&possible, 0, sizeof(possible));
				possible.x = i % 19;
				possible.y = i / 19;

				if (infos[self].valide)
				{
					possible.capture = infos[self].captureCount;
					possible.level = std::max(Priority(infos).getPriority(),
									 Priority(infos + 1).getPriority());
					temporary.push_back(possible);
				}
			}
		}

		temporary.sort([](MinTransition const& a, MinTransition const& b)
			{
				if (a.capture < b.capture)
					return false;
				if (a.level < b.level)
					return false;
				if (a.level == b.level && a.capture == b.capture)
					return std::rand() % 10 >= 8;
				return true;
			});

		MinNode *p;
		if ((p = this->parent.parent))
		{
			if (!p->inited)
			{
				p->score = this->score;
				p->inited = true;
			}
			else
			{
				if (color_turn == IGamePlay::BLACK)
					p->score = std::max(p->score, this->score);
				else if (color_turn == IGamePlay::WHITE)
					p->score = std::min(p->score, this->score);
			}
		}
		this->nbChoices = temporary.size();
		this->choices = new MinTransition[this->nbChoices];
		std::copy(temporary.begin(), temporary.end(), this->choices);
	}

	bool		MinNode::evaluateChoice(unsigned int idx)
	{
		assert(idx < this->nbChoices);

		MinTransition *toEvaluate = this->choices + idx;

		MinNode *result = new MinNode(this, toEvaluate);
		if (result->arbitre->putPiece(toEvaluate->x, toEvaluate->y,
				color_turn))
		{
				toEvaluate->result = result;
		}
		else
			assert(false);
		return false;
	}


	bool		MinNode::hasChild()
	{
		for (unsigned i = 0; i < this->nbChoices; ++i)
		{
			MinTransition &e = this->choices[i];
			if (e.result != NULL && e.result->nbChoices > 0)
				return true;
		}
		return false;
	}


	int			MinNode::evaluateNode()
	{
		return this->score;
	}

	MinNode::MinNode()
	{
		memset(this, 0, sizeof(*this));
	}

	MinNode::MinNode(MinNode *parent, MinTransition *causedby)
	{
		memcpy(this, parent, sizeof(*this));
		this->parent.parent = parent;
		this->parent.choice = causedby;
		this->nbChoices = 0;
		this->choices = NULL;
		this->depth += 1;
		this->arbitre = new RGamePlay::RGameArbitre(*(parent->arbitre));
		if (color_turn == IGamePlay::BLACK)
			color_turn = IGamePlay::WHITE;
		else
			color_turn = IGamePlay::BLACK;
	}

	MinNode::~MinNode()
	{
		for (unsigned int i = 0; i < this->nbChoices; ++i)
		{
			choices[i].cleanUp();
		}
		delete[] choices;
		delete arbitre;
	}
}
