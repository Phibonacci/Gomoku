#ifndef MENU_H
#define MENU_H

#include "ui_menu.h"
#include "Game.hh"
#include <QKeyEvent>

class Menu : public QDialog, private Ui::Menu
{
	Q_OBJECT

private:
	Logic::Game* _game;

public:
	Menu(Logic::Game* game, QWidget* parent = 0);

signals:
    void    close();

private slots:
    void keyPressEvent(QKeyEvent *event);
    void on_ai_clicked();
    void on_players_clicked();
    void on_buttonBox_rejected();
    void on_horizontalSlider_2_sliderMoved(int position);
    void on_buttonBox_accepted();
    void on_horizontalSlider_valueChanged(int value);
};

#endif // MENU_H
