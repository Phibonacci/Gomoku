#ifndef RGAMEBOARD_H_
# define RGAMEBOARD_H_

# include <utility>

namespace RGamePlay {
struct RPiece;
class RGameBoard
{
protected:
	RPiece				_pieces[19 * 19];

	unsigned int		_sizex;
	unsigned int		_sizey;


	unsigned int getIndex(unsigned int x, unsigned int y) const;
	bool		inBound(unsigned int x, unsigned int y) const;

public:
	void			debug();
	RGameBoard(unsigned int sizex = 19,
		unsigned int sizey = 19);

	struct Coord
	{
		unsigned int x;
		unsigned int y;
		unsigned int index;
		bool outOfBound;
	public:
		Coord(unsigned int x, unsigned int y,
			unsigned int index = 0, bool outBound = false);
		bool	operator!=(Coord const&) const;
	};

	typedef unsigned int DirectType;

	Coord
	advanceCoord(
		Coord location,
		DirectType direction,
		int multiplier) const;

	//Caution, may not be that safe;
	int	getDistance(Coord const&, Coord const&, DirectType dir) const;

	static DirectType const	dMax; //for number of directions in the board

	Coord			getCoord(unsigned int x, unsigned int y) const;

	RPiece &		operator[](unsigned int idx);

	void			reinit();
	~RGameBoard();
};
}

#endif /* !RGAMEBOARD_H_ */
