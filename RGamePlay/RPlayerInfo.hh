#ifndef RPLAYERINFO_H_
# define RPLAYERINFO_H_

namespace RGamePlay {
struct	RPlayerInfo
{
	unsigned char color : 2,
		pieceCaptured : 3, //Maximum five times
		truewin : 1,
		fakewin : 1; //deprecated, do not use
};

}

#endif /* !RPLAYERINFO_H_ */
