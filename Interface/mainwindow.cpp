#include <QMessageBox>
#include <QStyleFactory>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Logic::Game* game, QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  _game(game),
  _settings("Config"),
  _quit(false)
{
    initSettings();
    if (_quit == true) {
        QApplication::closeAllWindows();
    }

    ui->setupUi(this);
	_timer[0] = new Time(this, 10, 0);
	_timer[1] = new Time(this, 10, 0);
	ui->gridLayout->addWidget(_timer[0], 2, 0);
	ui->gridLayout->addWidget(_timer[1], 2, 2);
	_currentTime = 0;
	_uiSetting = new configStyleSheet(this);
	connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(gameQuit()));
	connect(ui->actionStyle, SIGNAL(triggered()), this, SLOT(changeStyle()));
	connect(ui->actionDark_Style, SIGNAL(triggered()), this, SLOT(changeToDarkStyle()));
	connect(_game, SIGNAL(playerChanged()), this, SLOT(handleResults()));

    startGame();
}

MainWindow::~MainWindow()
{
  saveSettings();
  delete ui;
  delete _game;
  delete _timer[0];
  delete _timer[1];
}

void    MainWindow::quit() {
    _quit = true;
}

bool    MainWindow::getQuit() {
    return _quit;
}

void    MainWindow::setMin(int min) {
    _timer[0]->setMin(min);
    _timer[1]->setMin(min);
}

Logic::Game& MainWindow::game() const
{
  return *_game;
}

void MainWindow::startGame()
{
    _timer[_currentTime]->startTimer();
    resetRules();
	ui->logText->clear();
	log("Welcome to Gomoku!");
}

void MainWindow::log(const QString &message)
{
	ui->logText->append(message);
}

void MainWindow::on_restartButton_clicked()
{
	game().reset();
    _timer[0]->restart();
    _timer[1]->restart();
    _currentTime = 0;
    _timer[0]->startTimer();
    _timer[1]->stopTimer();
    ui->gameView->redraw();
	startGame();
}

void MainWindow::on_doubleThreeCheckBox_toggled(bool)
{
	resetRules();
}

void MainWindow::on_breakableFiveCheckBox_toggled(bool)
{
	resetRules();
}

void MainWindow::resetRules()
{
	int rules = 0;
	if (ui->doubleThreeCheckBox->isChecked()) rules |= IGamePlay::DOUBLE3;
	if (ui->breakableFiveCheckBox->isChecked()) rules |= IGamePlay::BREAKABLE5;
	game().gameplay().setRule(static_cast<IGamePlay::Rule>(rules));
}

void MainWindow::on_undoButton_clicked()
{
	game().undo();
	ui->gameView->redraw();
    if (ui->logText->document()->blockCount() > 1) {
        ui->logText->setFocus();
        QTextCursor storeCursorPos = ui->logText->textCursor();
        ui->logText->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
        ui->logText->moveCursor(QTextCursor::StartOfLine, QTextCursor::MoveAnchor);
        ui->logText->moveCursor(QTextCursor::End, QTextCursor::KeepAnchor);
        ui->logText->textCursor().removeSelectedText();
        ui->logText->textCursor().deletePreviousChar();
        ui->logText->setTextCursor(storeCursorPos);
    }
}

void MainWindow::gameQuit()
{
  if (QMessageBox::warning(this, "Quit", "Do you really want to leave ?", QMessageBox::Yes, QMessageBox::No)
	  == QMessageBox::No)
	return ;
  QApplication::quit();
}

void		MainWindow::darkStyle(QPalette& darkPalette)
{
  darkPalette.setColor(QPalette::Window, QColor(53,53,53));
  darkPalette.setColor(QPalette::WindowText, QColor(255, 255, 255));
  darkPalette.setColor(QPalette::Base, QColor(25,25,25));
  darkPalette.setColor(QPalette::AlternateBase, QColor(53,53,53));
  darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
  darkPalette.setColor(QPalette::ToolTipText, Qt::white);
  darkPalette.setColor(QPalette::Text, Qt::white);
  darkPalette.setColor(QPalette::Disabled, QPalette::Text, Qt::gray);
  darkPalette.setColor(QPalette::Button, QColor(53,53,53));
  darkPalette.setColor(QPalette::ButtonText, Qt::white);
  darkPalette.setColor(QPalette::BrightText, Qt::red);
  darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
  darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
  darkPalette.setColor(QPalette::HighlightedText, Qt::black);
}


#include <QDebug>
void MainWindow::handleResults()
{
	_timer[_currentTime]->stopTimer();
	_currentTime = !_currentTime;
	_timer[_currentTime]->startTimer();
}

void MainWindow::changeStyle()
{
  _uiSetting->show();
}

void MainWindow::changeToDarkStyle()
{
  QPalette	darkPalette;
  darkStyle(darkPalette);
  QApplication::setPalette(darkPalette);
}

void MainWindow::setScore(int player, unsigned int score)
{
  QLabel* label = ui->_blackScore;
  if (player == 1)
	label = ui->_whiteScore;
  label->setText(QVariant(score).toString());
}

void	MainWindow::initSettings()
{\
	_settings.beginGroup("MainOptions");
    if (_settings.value("WinColor").value<QString>() == "dark")
        changeToDarkStyle();
	_settings.endGroup();
}

void	MainWindow::saveSettings()
{
	QPalette palette = QApplication::palette();
	_settings.beginGroup("MainOptions");
    _settings.setValue("WinColor", palette.color(QPalette::Window) == QColor(53,53,53) ? "dark" : "normal");
	_settings.endGroup();
}
