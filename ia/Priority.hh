#ifndef PRIORITY_H_
# define PRIORITY_H_

# include "RGamePlay.hh"

namespace ia{
	class Priority
	{
	public:
		enum Level
		{
			LOSE = -100,
			INVALIDE = -1,
			USELESS = 0,
			ALIGN3 = 1,
			POTENTIAL = 2,
			PRESSURE = 3,
			ADVANTAGE = 4,
			CAPTURE = 5,
			ALMOSTWIN = 6,
			WIN		  = 100 //priority will never return this condition
		};

		Priority(RGamePlay::RPieceInformation *one);
		Level	getPriority() const;
	public:
		void updatePriority(Level);
	protected:
		Level	_priority;
	};
}

#endif /* !PRIORITY_H_ */
