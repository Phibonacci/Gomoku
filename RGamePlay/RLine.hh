#ifndef RLINE_H_
# define RLINE_H_

namespace RGamePlay {
struct RLine
{
	/*
	** Blocked
	** 0 for not blocked, 1 for blocked, 2 for wall block?
	 */
	enum BlockType
	{
		NONE,
		ENEMY,
		WALL
	};

	union
	{
		unsigned char value;
		struct {
			unsigned char nbPiece : 4;
			unsigned char leftBlocked : 2;
			unsigned char rightBlocked : 2;
		}				info;
	};

	bool		isBreakable() const;
	bool		isBreaked() const;
};
}
#endif /* !RLINE_H_ */
