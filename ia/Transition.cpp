#include "Priority.hh"
#include "Transition.hh"
#include "Node.hh"
#include <algorithm>

namespace ia{
void	Transition::cleanUp()
{
	delete values[0].result;
	delete values[1].result;
	values[0].result = NULL;
	values[1].result = NULL;
}

	bool		 Transition::operator==(Transition const& other) const
	{
		return other.x == x && other.y == y;
	}


	void		 Transition::updateLevel()
	{
		level = std::max(values[0].value, values[1].value);
	}
}
