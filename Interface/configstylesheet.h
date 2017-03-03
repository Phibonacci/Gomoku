#ifndef CONFIGSTYLESHEET_H
#define CONFIGSTYLESHEET_H

#include <QDialog>
#include <QPalette>
#include <QColor>
#include "guistrstyle.h"

namespace Ui {
  class configStyleSheet;
}

class rgbDial;

class configStyleSheet : public QDialog
{
  Q_OBJECT

  rgbDial             *_rgbdial;
  QPalette::ColorRole _role;
  int                 _style;
  QColor              _color;
  GuiStrStyle*        guiStyle;

  typedef void        (GuiStrStyle::*fnptr)(const QString &);
  void                changeGui(QString& vec, int const pos, QMap<char, int> const& map, fnptr ptr);
  void                changeStyle(QMap<char, int> &map, char type, int value);

public:
  explicit            configStyleSheet(QWidget *parent = 0);
                      ~configStyleSheet();
  void                onValueChanged(char type, int value);

private slots:
  void on__windowBut_clicked();
  void on__windowTextBut_clicked();
  void on__baseBut_clicked();
  void on__alternateBaseBut_clicked();
  void on__toolTipBaseBut_clicked();
  void on__toolTipText_clicked();
  void on__buttonBut_clicked();
  void on__butonTextBut_clicked();
  void on__brightTextBut_clicked();
  void on__linkBut_clicked();
  void on__hightlightBut_clicked();
  void on__hightlitedTextBut_clicked();
  void on__editLine_clicked();
  void on__editLineText_clicked();
  void on__text_clicked();

private:
  Ui::configStyleSheet *ui;
};

#endif // CONFIGSTYLESHEET_H
