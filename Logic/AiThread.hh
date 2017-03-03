#ifndef AITHREAD_H_
#define AITHREAD_H_

#include <atomic>
#include <thread>
#include <memory>
#include <QObject>

namespace Logic
{
	class Game;
	class Player;

	class AiThread : public QObject
	{
		Q_OBJECT

	private:
		Game& _game;
		Player& _player;
		bool _playing;
		std::shared_ptr<std::thread> _thread;
		bool _isRunning;

	public:
		AiThread(Game& game, Player& player);
		virtual ~AiThread();
		void launch();
		void play();
		void quit();
		void sync();

	signals:
		void playPiece(unsigned int x, unsigned int y);

	private:
		void loop();
	};
}

#endif // AITHREAD_H_
