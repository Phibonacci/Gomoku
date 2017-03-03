#include <iostream>
#include <chrono>

#include "AiThread.hh"
#include "Game.hh"

namespace Logic
{
	AiThread::AiThread(Game& game, Player& player) :
		_game(game),
		_player(player),
		_playing(false),
		_isRunning(false)
	{
		connect(this, SIGNAL(playPiece(unsigned, unsigned)),
			&_game, SLOT(aiPlay(unsigned, unsigned)));
	}

	void AiThread::sync()
	{
		//_robot->sync();
	}


	AiThread::~AiThread()
	{
		_isRunning = false;
		if (_thread)
		{
			_thread->join();
		}
	}

	void AiThread::launch()
	{
		_isRunning = true;
		_thread = std::make_shared<std::thread>(std::bind(&AiThread::loop, this));
	}

	void AiThread::play()
	{
		_playing = true;
	}

	void AiThread::quit()
	{
		_playing = false;
	}

	void AiThread::loop()
	{
		while (_isRunning)
		{
			std::cout << "ia" << std::endl;
			if (_playing)
			{
				std::cout << "its my turn!!!" << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				std::cout << "play" << std::endl;
				emit playPiece(0, 0);
				_playing = false;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
	}
}
