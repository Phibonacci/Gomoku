#include "Game.hh"
#include "RGamePlay.hh"
#include "RobotThread.hh"
#include <QApplication>
#include <iostream>
#include <unistd.h>
#include <QMetaType>
namespace Logic {

Logic::RobotThread::RobotThread(Game& game, Player& player, IRobot *robot, QObject *parent)
		: _game(game), _player(player), _robot(robot)
	{
		//connect(workerThread, SIGNAL(resultReady(QString)), parent, SLOT(handleResults(QString)));
		connect(&_thread, SIGNAL(finished()), parent, SLOT(deleteLater()));
		connect(this, SIGNAL(aiPlay(unsigned int, unsigned int)), parent, SLOT(aiPlay(unsigned int, unsigned int)));
		connect(this, SIGNAL(aiPlaySignal()), this, SLOT(aiPlaySlot()));
		qRegisterMetaType<Logic::Player>("const Logic::Player&");
		connect(&game, SIGNAL(played(const Logic::Player&, unsigned, unsigned)),
			this, SLOT(playerPlayed(const Logic::Player&, unsigned, unsigned)));

		moveToThread(&_thread);
	}


	void RobotThread::sync()
	{
		_robot->sync();
	}

	RobotThread::~RobotThread()
	{
		_thread.quit();
		_thread.wait();
	}

bool RobotThread::event(QEvent *e)
{
	if (e->type() == QEvent::User)
	{
		PlayEvent *event = dynamic_cast<PlayEvent*>(e);
		if (event)
		{
//			QApplication::instance()->postEvent(this, new PlayEvent());
//			_robot->background();
			return true;
		}
	}
	return QObject::event(e);
}

void RobotThread::launch()
{
	_thread.start();
	QApplication::instance()->postEvent(this, new PlayEvent());
}

void RobotThread::quit()
{
	_thread.quit();
}

void RobotThread::play()
{
	emit aiPlaySignal();
}

	void RobotThread::playerPlayed(const Logic::Player& player, unsigned int x, unsigned int y)
	{
		if (player.color() != _player.color())
		{
			_robot->opponentPlayed(Coord(x, y));
		}
	}

void RobotThread::aiPlaySlot()
{
	std::cout << "it is my turn" << std::endl;
	Coord result = _robot->play();
	emit aiPlay(result.x, result.y);
	std::cout << "i decided " << result.x << " " << result.y << std::endl;
}

	RobotThread::PlayEvent::PlayEvent()
		: QEvent(User)
	{}

}
