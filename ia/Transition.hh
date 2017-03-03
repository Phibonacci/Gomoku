#ifndef TRANSITION_H_
# define TRANSITION_H_

namespace ia
{
	struct Node;
	class Priority;
	struct Value
	{
		int				value;
		Node			*result;
	};
	struct Transition
	{
		unsigned int	x;
		unsigned int	y;
		Value			values[2];
		int				level;

		void		 cleanUp();
		void		 updateLevel();
		bool		 operator==(Transition const&) const;
	};
}

#endif /* !TRANSITION_H_ */
