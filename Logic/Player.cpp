#include "Player.hh"

namespace Logic
{
	IGamePlay::Piece Player::color() const
	{
		return _color;
	}

	void Player::color(IGamePlay::Piece value)
	{
		_color = value;
	}

	Player::Mode Player::mode() const
	{
		return _mode;
	}

	void Player::mode(Mode value)
	{
		_mode = value;
	}
}
