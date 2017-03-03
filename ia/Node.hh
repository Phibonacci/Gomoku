#ifndef STATE_H_
# define STATE_H_

# include "RGamePlay.hh"

namespace ia
{
	struct Transition;
	struct Node;
	struct Link
	{
		Node		 *parent;
		Transition	 *choice;
		IGamePlay::Piece color;
	};
	struct Node
	{
		Link			parent;
		unsigned int	nbChoices;
		Transition		*choices;
		unsigned int	depth[2];

		RGamePlay::RGameArbitre	*arbitre;

		Node();
		Node(Node *parent, Transition *by, int depthchoice);
		void	initializeChoices();
		void	evaluateChoice(unsigned idx);
		void	updateParentValue();
		void	updateChildValue();
		Transition *getBestChoice(unsigned color);
		~Node();
	};

}


#endif /* !STATE_H_ */
