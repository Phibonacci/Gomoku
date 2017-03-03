#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include <stdexcept>

#include "mainwindow.h"
#include "gameview.h"
#include "info.hh"

GameView::GameView(QWidget *parent) :
	QGraphicsView(parent)
{
	_info = NULL;
	setCursor(Qt::CrossCursor);

	_window = dynamic_cast<MainWindow*>(parent->parent());
	_gamePlay = &_window->game().gameplay();

	QPixmap background(":/Board/emptyBoardImg.png");
	_squareSize = background.size().width();

	_scene = new QGraphicsScene(0, 0, _squareSize * 19, _squareSize * 19);
	_scene->setBackgroundBrush(background);
	setScene(_scene);

	connect(&_window->game(), SIGNAL(played(const Logic::Player&, unsigned, unsigned)),
		this, SLOT(onGamePlayed(const Logic::Player&, unsigned, unsigned)));

	connect(&_window->game(), SIGNAL(error(const std::string&)),
		this, SLOT(onGameError(const std::string&)));

	connect(this, SIGNAL(mouseEvent(unsigned, unsigned)),
		&_window->game(), SLOT(humanPlay(unsigned, unsigned)));
}

void GameView::redraw()
{
	_scene->clear();
	for (int x = 0; x < 19; ++x)
	{
		for (int y = 0; y < 19; ++y)
		{
			switch (_gamePlay->getPiece(x, y))
			{
			case IGamePlay::NONE:
				break;
			case IGamePlay::WHITE:
				_scene->addPixmap(QPixmap(":/Board/White.png"))->setPos(QPoint(x, y) * _squareSize);
				break;
			case IGamePlay::BLACK:
				_scene->addPixmap(QPixmap(":/Board/Black.png"))->setPos(QPoint(x, y) * _squareSize);
				break;
			}
		}
	}
}

void GameView::mousePressEvent(QMouseEvent *event)
{
	if (_gamePlay->getWinner() != IGamePlay::NONE)
	{
		return;
	}

	QPointF locf((mapToScene(event->pos()) + QPointF(0.5, 0.5)) / _squareSize);
	QPoint loc(static_cast<int>(locf.x()), static_cast<int>(locf.y()));

	if (loc.x() < 0 || loc.y() < 0 || loc.x() >= 19 || loc.y() >= 19)
	{
		return;
	}

	if (event->button() == Qt::RightButton)
	{
		_gamePlay->retrievePieceInfo(IGamePlay::BLACK, loc.x(), loc.y());
	}
	else if (event->button() == Qt::LeftButton)
	{
		emit mouseEvent(loc.x(), loc.y());
	}
}

void GameView::resizeEvent(QResizeEvent*)
{
	fitInView(_scene->sceneRect(), Qt::IgnoreAspectRatio);
}

void GameView::onGamePlayed(const Logic::Player& player, unsigned int x, unsigned int y)
{
	QString color(player.color() == IGamePlay::BLACK ? "black" : "white");
	_window->log(QString("%1 played at [%2, %3]").arg(color).arg(x).arg(y));

	IGamePlay::Piece winner = _gamePlay->getWinner();
	if (winner != IGamePlay::NONE)
	{
		QString winnerColor(winner == IGamePlay::BLACK ? "black" : "white");
		_window->log(QString("%1 won the game !!").arg(winnerColor));
	}

	redraw();
}

void GameView::onGameError(const std::string& error)
{
	_window->log(QString(error.c_str()));
}
