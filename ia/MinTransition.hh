#ifndef MINTRANSITION_H_
# define MINTRANSITION_H_

namespace ia
{
	struct MinNode;
	class Priority;
	struct MinTransition
	{
		unsigned int	x;
		unsigned int	y;
		int				capture;
		MinNode			*result;
		int				level;
		bool			end;
		bool			init;
		void		 cleanUp();
		bool		 operator==(MinTransition const&) const;
		int			 getScore(bool minmax);
		void		 initScore(int alpha, int belta);
	};
}

#endif /* !MINTRANSITION_H_ */
