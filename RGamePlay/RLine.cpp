#include "RLine.hh"

namespace RGamePlay {
	bool RLine::isBreakable() const
	{
		unsigned char value = info.leftBlocked << 2 | info.rightBlocked;

		return (info.nbPiece == 2
			&& (
				value == (1 << 2) || value == (1)
				)
			);
	}

	bool RLine::isBreaked() const
	{
		unsigned char value = info.leftBlocked << 2 | info.rightBlocked;

		return (info.nbPiece == 2
			&& (
				value == (1 << 2 | 1)
				)
			);
	}
}
