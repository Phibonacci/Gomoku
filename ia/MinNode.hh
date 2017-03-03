#ifndef MINNODE_H_
# define MINNODE_H_

# include "RGamePlay.hh"

namespace ia
{
	struct MinTransition;
	struct Node;
	struct Link
	{
		MinNode					*parent;
		MinTransition			*choice;
	};
	struct MinNode
	{
		Link					parent;
		unsigned int			nbChoices;
		MinTransition			*choices;
		unsigned int			depth;
		unsigned int			score;
		bool					inited;

		IGamePlay::Piece		color_turn;
		RGamePlay::RGameArbitre	*arbitre;

		MinNode();
		MinNode(MinNode *parent, MinTransition *by);
		void	initializeChoices(MinTransition *oldones, unsigned size);
		bool	evaluateChoice(unsigned idx);
		int		calculateScore(int alpha, int belta);
		bool	hasChild();
		int		evaluateNode();
		~MinNode();
	};

}


#endif /* !MINNODE_H_ */
