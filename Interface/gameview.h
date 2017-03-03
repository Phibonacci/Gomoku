#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <IGamePlay.hh>
#include <string>

#include "info.hh"
#include "Game.hh"

class MainWindow;

class GameView : public QGraphicsView
{
	Q_OBJECT
public:
	explicit GameView(QWidget *parent = 0);

signals:
	void mouseEvent(unsigned int, unsigned int);
public slots:
	void redraw();
	void mousePressEvent(QMouseEvent *event);
	void resizeEvent(QResizeEvent *event);
private slots:
	void onGamePlayed(const Logic::Player& player, unsigned int x, unsigned int y);
	void onGameError(const std::string& error);

private:
	Info*		_info;
	MainWindow* _window;
	IGamePlay* _gamePlay;
	QGraphicsScene* _scene;
	int _squareSize;

};

#endif // GAMEVIEW_H
