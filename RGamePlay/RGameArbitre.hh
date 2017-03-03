#ifndef RGAMEARBITRE_H_
# define RGAMEARBITRE_H_

# include "IGamePlay.hh"

namespace RGamePlay {
	struct RLine;
	struct RPiece;
	class RGameBoard;
	struct RPattern;
	struct PlayerInfo;
	struct RPlayerInfo;
	struct RPieceInformation;
	class RGameArbitre
	{
	public:
		class			RPieceToPut
		{
			RGameArbitre		&_arbitre;
			RGameBoard			&_board;
			IGamePlay::Piece	_color;
			RGameBoard::Coord	const &_coord;
			void		internCheckWin(RGameBoard::DirectType direction);
		public:
			RPieceToPut(RGameArbitre &, IGamePlay::Piece,
				RGameBoard::Coord const &);
			RPieceToPut(RGameArbitre &, unsigned int,
				RGameBoard::Coord const &);
			bool		checkWin(RGameBoard::DirectType direction);
			RLine		getLine(RGameBoard::DirectType direction);
			void		updateLine(RGameBoard::DirectType dir, bool rec = true);
			RPattern	getPattern(RGameBoard::DirectType direction);
			bool		captureLine(RGameBoard::DirectType dir, int forward);
			bool		captureAble(RGameBoard::DirectType dir, int forward);
		};
		class			RPieceToRemove
		{
			RGameArbitre &_arbitre;
			RGameBoard	&_board;
			RGameBoard::Coord const& _coord;
			void		updateLine(RGameBoard::DirectType dir);
			void		updateOpponentLine(RGameBoard::DirectType dir);
		public:
			RPieceToRemove(RGameArbitre &, RGameBoard::Coord const&);
			void		remove(RGameBoard::DirectType becauseOf);
		};

		class			RPieceToTry
		{
			RGameArbitre &_arbitre;
			RGameBoard	&_board;
			RGameBoard::Coord const& _coord;
		public:
			RPieceToTry(RGameArbitre &, RGameBoard::Coord const&);
			void		tryPiece(RPieceInformation *toStore, IGamePlay::Piece color);
		};

	public: //tmp
		RGameBoard		_board;
		RPlayerInfo		_players[2];
	public:
		RGameArbitre();
		IGamePlay::Piece getWinner() const;
		bool	pieceInformationUpdated(unsigned int x, unsigned int y);
		bool	getPieceInformation(unsigned int x, unsigned int y,
			RPieceInformation *toStore);
		bool	putPiece(unsigned int x, unsigned int y,
			IGamePlay::Piece color);
		RPiece const&	getPiece(unsigned int, unsigned int);
		void	reinit();
		~RGameArbitre();
		RPlayerInfo &getPlayer(unsigned int num);
	};
}

#endif /* !RGAMEARBITRE_H_ */
