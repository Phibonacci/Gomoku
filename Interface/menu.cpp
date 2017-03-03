#include "menu.h"
#include "mainwindow.h"

Menu::Menu(Logic::Game* game, QWidget* parent) :
	QDialog(parent)
{
	_game = game;
	setupUi(this);
    _game->player(0).mode(Logic::Player::Human);
	_game->player(1).mode(Logic::Player::Human);
	horizontalSlider->setValue(5);
	Logic::AiLevel = 5;
}

void Menu::on_ai_clicked()
{
	_game->player(1).mode(Logic::Player::AI);
	aiLevel->setEnabled(true);
}

void Menu::on_players_clicked()
{
	_game->player(1).mode(Logic::Player::Human);
	aiLevel->setEnabled(false);
}

void Menu::on_horizontalSlider_valueChanged(int value)
{
	horizontalSlider->setToolTip(QVariant(value).toString());
	Logic::AiLevel = value;
}

void Menu::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Escape) {
        emit close();
        closeEvent(NULL);
    }
    if (event->key() == Qt::Key_Return) {
        closeEvent(NULL);
    }
}

void Menu::on_buttonBox_rejected()
{
    emit close();
}

void Menu::on_horizontalSlider_2_sliderMoved(int position)
{
    static_cast<MainWindow*>(parent())->setMin(position);
}

void Menu::on_buttonBox_accepted()
{
    _game->start();
    static_cast<MainWindow*>(parent())->startGame();
}
