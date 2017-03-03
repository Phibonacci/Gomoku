#ifndef GAME_H_
#define GAME_H_

#include <memory>
#include <string>
#include <QObject>

#include "Player.hh"
#include "IThread.hh"

class IGamePlay;

namespace Logic
{
	class AiThread;

	extern unsigned int AiLevel;

	class Game : public QObject
	{
		Q_OBJECT

	private:
		std::shared_ptr<IGamePlay> _gameplay;
		Player _players[2];
		std::shared_ptr<IThread> _threads[2];
		int _currentPlayer;

	public:
		Game();
		void start();
		IGamePlay& gameplay() const;
		Player& player(unsigned int num);
	public slots:
		void humanPlay(unsigned int x, unsigned int y);
		void aiPlay(unsigned int x, unsigned int y);
		void reset();
		void undo();

	signals:
		void played(const Logic::Player& player, unsigned int x, unsigned int y);
		void error(const std::string& err);
		void playerChanged();
	private:
		void playPiece(unsigned int x, unsigned int y);
		void nextPlayer();
		void syncIA();
	};
}

#endif // GAME_H_
