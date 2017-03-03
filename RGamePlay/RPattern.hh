#ifndef RPATTERN_H_
# define RPATTERN_H_

namespace RGamePlay {
struct	RPattern
{
	union
	{
		unsigned short value;

		struct {
			unsigned short
			nbPiece : 4,
				leftBlocked : 2,
				rightBlocked : 2,
				splitted : 1,
				isBlocked : 1;
		}				info;
	};
	int	nbBlocked() const
	{
		return (info.leftBlocked > 0) + (info.rightBlocked > 0);
	}
};

}

#endif /* !RPATTERN_H_ */
