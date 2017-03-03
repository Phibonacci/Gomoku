#ifndef PLAYER_H_
#define PLAYER_H_

#include "IGamePlay.hh"

namespace Logic
{
	class Player
	{
	public:
		enum Mode
		{
			Human,
			AI
		};

	private:
		IGamePlay::Piece _color;
		Mode _mode;

	public:
		IGamePlay::Piece color() const;
		void color(IGamePlay::Piece value);

		Mode mode() const;
		void mode(Mode value);
	};
}

#endif // PLAYER_H_
