#ifndef COORD_H_
# define COORD_H_

struct Coord
{
	unsigned int x, y;
	Coord(unsigned int i, unsigned int j)
		: x(i), y(j) {}
};

#endif /* !COORD_H_ */
