#include <iostream>

#include "Game.hh"
#include "RobotThread.hh"
#include "RGamePlay.hh"
#include "AiThread.hh"
#include "HelpRobot.hh"
#include "MinRobot.hh"
#include "Phia.hpp"

namespace Logic
{
	unsigned int AiLevel;

	Game::Game()
	{
		_currentPlayer = 0;
		_players[0].color(IGamePlay::BLACK);
		_players[1].color(IGamePlay::WHITE);
		_gameplay = std::make_shared<RGamePlay::GamePlay>();
	}

	void Game::start()
	{
		for (size_t i = 0; i < 2; ++i)
		{
			if (_players[i].mode() == Player::AI)
			{
				// IRobot *robot = new ia::Phia(*this, _players[i]);
				//IRobot *robot = new ia::HelpRobot(*this, _players[i]);
				IRobot *robot = new ia::MinRobot(*this, _players[i]);


				_threads[i] = std::make_shared<RobotThread>(*this, _players[i], robot, this);
				//_threads[i] = std::make_shared<AiThread>(*this, _players[i], robot);
				_threads[i]->launch();
			}
		}
	}

	IGamePlay& Game::gameplay() const
	{
		return *_gameplay;
	}

	Player& Game::player(unsigned int num)
	{
		return _players[num];
	}

	void Game::humanPlay(unsigned int x, unsigned int y)
	{
		if (_players[_currentPlayer].mode() != Player::Human)
			return ;
		playPiece(x, y);
	}

	void Game::aiPlay(unsigned int x, unsigned int y)
	{
		if (_players[_currentPlayer].mode() != Player::AI)
			return ;
		playPiece(x, y);
	}

	void Game::syncIA()
	{
		for (size_t i = 0; i < 2; ++i)
		{
			if (_players[i].mode() == Player::AI)
			{
				_threads[i]->sync();
			}
		}
	}

	void Game::reset()
	{
		_gameplay->reinit();
		_currentPlayer = 0;
		syncIA();
	}

	void Game::undo()
	{
		// We can't shouldn't undo during the AI turn.
		if (_players[_currentPlayer].mode() == Player::AI)
			return;

		_gameplay->undoLastPlacement();
		if (_players[1].mode() == Player::AI)
		{
			// Double undo to prevent the IA from auto playing again.
			_gameplay->undoLastPlacement();
			_currentPlayer = 1 - _currentPlayer;
		}
		_currentPlayer = 1 - _currentPlayer;
		syncIA();
		emit playerChanged();
		if (_players[_currentPlayer].mode() == Player::AI)
		{
			_threads[_currentPlayer]->play();
		}
	}

	void Game::playPiece(unsigned int x, unsigned int y)
	{
		try
		{
			_gameplay->putPiece(x, y);
			emit played(_players[_currentPlayer], x, y);
			nextPlayer();
		}
		catch (const IGamePlay::PlacementException& e)
		{
			emit error(e.what());
		}
	}

	void Game::nextPlayer()
	{
		_currentPlayer = 1 - _currentPlayer;
		if (_players[_currentPlayer].mode() == Player::AI && _gameplay->getWinner() == 0)
		{
			_threads[_currentPlayer]->play();
		}
		emit playerChanged();
	}
}
