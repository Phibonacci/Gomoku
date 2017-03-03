#include <cstdlib>
#include <ctime>

#include <QApplication>
#include <QStyleFactory>
#include <QObject>

#include "Game.hh"
#include "Context.hh"
#include "mainwindow.h"
#include "menu.h"

int main(int argc, char *argv[])
{
	std::srand(std::time(0));
	QApplication a(argc, argv);
	QApplication::setStyle(QStyleFactory::create("Fusion"));
	Logic::Game* game = new Logic::Game();

	MainWindow w(game);

	Menu* menu = new Menu(game, &w);
	QObject::connect(menu, SIGNAL(close()), &w, SLOT(quit()));
	menu->exec();

	if (w.getQuit() == true) {
		return 0;
	}

	Context::create(&a, &w);
	w.show();

	return a.exec();
}
