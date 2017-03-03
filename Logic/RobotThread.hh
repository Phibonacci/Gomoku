#ifndef ROBOTTHREAD_H_
# define ROBOTTHREAD_H_

# include <QThread>
# include <QEvent>
# include "Game.hh"
# include "IRobot.hh"

namespace Logic {
	class RobotThread : public QObject, public IThread
{
	Q_OBJECT
protected:
	bool event(QEvent *e);
private:
	QThread _thread;
	Game &_game;
	Player &_player;
	IRobot *_robot;
public:
	RobotThread(Game& game, Player& player, IRobot *robot,
		QObject *parent = 0);
	virtual void sync();
	virtual void launch();
	virtual void quit();
	virtual void play();
	virtual ~RobotThread();
signals:
	void aiPlay(unsigned int x, unsigned int y);
	void aiPlaySignal();
public slots:
	void aiPlaySlot();
	void playerPlayed(const Logic::Player& player, unsigned int x, unsigned int y);


private:
	class PlayEvent : public QEvent
	{
	public:
		PlayEvent();
	};

};

}

#endif /* !ROBOTTHREAD_H_ */
