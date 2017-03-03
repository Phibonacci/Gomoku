#include "RLine.hh"
#include "RPiece.hh"
#include <bitset>
#include <iostream>
namespace RGamePlay
{
	unsigned int		RPiece::getLinePosition(unsigned int direction)
	{
		return (positions >> direction
			>> direction
			>> direction
			>> direction) & 15;
	}

	void		RPiece::setLinePosition(unsigned int direction, unsigned short position)
	{
		unsigned int mask = 15 << direction
							   << direction
							   << direction
							   << direction;

		positions = (positions & (~mask)) | (position
					<< direction << direction
					<< direction << direction);
		//std::cout << position << " "<< std::bitset<16>(positions) << "mask" << std::bitset<16>(~mask) << std::endl;
	}
	void		RPiece::setColor(unsigned int color)
	{
		this->color = color;
	}
}
