#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSettings>

#include "Game.hh"
#include "Time.hh"
#include "configstylesheet.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Logic::Game* game, QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow            *ui;
    Logic::Game               *_game;
    configStyleSheet          *_uiSetting;
    Time*                      _timer[2];
    size_t                     _currentTime;
    QSettings                  _settings;
    bool                       _quit;

    static QMap<QPalette::ColorRole, QString>   _map;

public:
    Logic::Game& game() const;
    void startGame();
    void log(const QString& message);
    void setScore(int player, unsigned int score);
    bool getQuit();
    void setMin(int min);

signals:
    void    clicked();

public slots:
    void quit();

private slots:
    void on_restartButton_clicked();
    void on_doubleThreeCheckBox_toggled(bool checked);
    void on_breakableFiveCheckBox_toggled(bool checked);

    void on_undoButton_clicked();
    void gameQuit();
    void handleResults();
    void changeStyle();
    void changeToDarkStyle();

private:
    void resetRules();
    void darkStyle(QPalette& darkPalette);
    void initSettings();
    void saveSettings();
};

#endif // MAINWINDOW_H
