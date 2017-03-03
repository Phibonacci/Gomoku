#include "Priority.hh"
#include <iostream>
namespace ia
{
	void		Priority::updatePriority(Level priority)
	{
		if (_priority != INVALIDE)
		{
			_priority = (priority > _priority) ? priority : _priority;
		}
	}

	Priority::Priority(RGamePlay::RPieceInformation *one)
		: _priority(USELESS)
	{
		if (!one[0].valide)
			_priority = INVALIDE;
		else
		{
			if (one[0].comboCount > 0)
			{
				RGamePlay::RPattern pattern = one[0].getHighestPattern();
				updatePriority(((one[0].comboCount) > 1) ?
					PRESSURE : ALIGN3);
				if (pattern.info.nbPiece - pattern.nbBlocked() >= 3 && !pattern.info.splitted)
					updatePriority(POTENTIAL);
				if (pattern.info.nbPiece - pattern.nbBlocked() >= 4 && !pattern.info.splitted)
					updatePriority(ADVANTAGE);
				if (pattern.info.nbPiece >= 5 && !pattern.info.splitted)
					updatePriority(ADVANTAGE);
			}
			if (one[0].captureCount > 0)
			{
				updatePriority(((one[0].captureCount) > 1) ?
					ALMOSTWIN : CAPTURE);
			}
		}
	}



	Priority::Level	Priority::getPriority() const
	{
		return _priority;
	}
}
