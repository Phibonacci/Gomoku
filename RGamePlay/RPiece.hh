#ifndef RPIECE_H_
# define RPIECE_H_

namespace RGamePlay {
struct RLine;
struct RPiece
{
	/*
	** General informations
	** 5 bit used for now
	*/

	unsigned char
		color : 2,
	/* 0 for none, 1 for black, 2 for white */

	// Information that need init
		breakable : 1,
		init : 1;


	/* other informations */
private:
	unsigned int positions : 16;
	/*
	  Do not direct access positions,
	  it is divised 4bit by bit to use with lines;
	 */

	// use this 4bit by 4bit, each contains the position
public:
	union Lineinfo
	{
		unsigned int	value;
		RLine			lines[4];
	}					info;

	unsigned int		getLinePosition(unsigned int direction);

	void				setLinePosition(
		unsigned int direction,
		unsigned short position);
	void				setColor(unsigned int color);
};
}
#endif /* !RPIECE_H_ */
