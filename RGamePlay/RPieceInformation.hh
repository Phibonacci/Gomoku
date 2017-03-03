#ifndef RPIECEINFORMATION_H_
# define RPIECEINFORMATION_H_

namespace RGamePlay {
struct RPattern;
struct RPieceInformation
{
	unsigned short	valide : 1,
	//Capture count 0 - 8;
		captureCount : 3,
		highestCount : 2,
		comboCount : 2,
		volunerable : 1;
	RPattern	patterns[4];

	RPattern	&getHighestPattern()
	{
		return patterns[highestCount];
	}
};
}

#endif /* !RPIECEINFORMATION_H_ */
