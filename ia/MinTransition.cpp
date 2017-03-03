#include "Priority.hh"
#include "MinTransition.hh"
#include "MinNode.hh"
#include <algorithm>
#include <iostream>
namespace ia{
void	MinTransition::cleanUp()
{
	delete result;
	result = NULL;
}

	bool		 MinTransition::operator==(MinTransition const& other) const
	{
		return other.x == x && other.y == y;
	}

	int			MinTransition::getScore(bool minmax)
	{
		int		heuristic_level = level;

		//assert(level <= 140 && level >= -140);
		// if (!end && minmax == false)
		//	heuristic_level *= -1;
		if (minmax)
			return heuristic_level + capture * 20;
		else
			return heuristic_level - capture * 20;
	}

	void		MinTransition::initScore(int alpha, int belta)
	{
		init = true;
		if (result != NULL)
		{
			level = result->calculateScore(alpha, belta);
			end = true;
		}
		else
			end = false;
	}
}
