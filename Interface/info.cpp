#include "info.hh"
#include <QLabel>
#include <QDebug>

Info::Info(IPieceInfo* info, IPieceInfo *info2, QWidget *parent) :
  QDialog(parent)
{
  setupUi(this);
  addLabel(static_cast<QFormLayout*>(tab->layout()), QString("Could you place a piece here ?"), QVariant(info->canPlace()).toString());
  addLabel(static_cast<QFormLayout*>(tab->layout()), QString("Winning position ?"), QVariant(info->canWin()).toString());
  addLabel(static_cast<QFormLayout*>(tab->layout()), QString("Eat Score: "), QVariant(info->pieceEaten()).toString());
  addLabel(static_cast<QFormLayout*>(tab->layout()), QString("Score: "), QVariant(info->toScore()).toString());
  addLabel(static_cast<QFormLayout*>(tab->layout()), QString("It could be breakable ? "), QVariant(info->couldBeBreakable()).toString());

  addLabel(static_cast<QFormLayout*>(tab_2->layout()), QString("Could you place a piece here ?"), QVariant(info2->canPlace()).toString());
  addLabel(static_cast<QFormLayout*>(tab_2->layout()), QString("Winning position ?"), QVariant(info2->canWin()).toString());
  addLabel(static_cast<QFormLayout*>(tab_2->layout()), QString("Eat Score: "), QVariant(info2->pieceEaten()).toString());
  addLabel(static_cast<QFormLayout*>(tab_2->layout()), QString("Score: "), QVariant(info2->toScore()).toString());
  addLabel(static_cast<QFormLayout*>(tab_2->layout()), QString("It could be breakable ? "), QVariant(info->couldBeBreakable()).toString());
}

void  Info::setValues(IPieceInfo* info, IPieceInfo *info2)
{
  QFormLayout* layout = static_cast<QFormLayout*>(tab->layout());

  QLayoutItem* item = layout->itemAt(1);
  static_cast<QLabel*>(item->widget())->setText(QVariant(info->canPlace()).toString());
  item = layout->itemAt(3);
  static_cast<QLabel*>(item->widget())->setText(QVariant(info->canWin()).toString());
  item = layout->itemAt(5);
  static_cast<QLabel*>(item->widget())->setText(QVariant(info->pieceEaten()).toString());
  item = layout->itemAt(7);
  static_cast<QLabel*>(item->widget())->setText(QVariant(info->toScore()).toString());
  item = layout->itemAt(9);
  static_cast<QLabel*>(item->widget())->setText(QVariant(info->couldBeBreakable()).toString());

  layout = static_cast<QFormLayout*>(tab_2->layout());
  item = layout->itemAt(1);
  static_cast<QLabel*>(item->widget())->setText(QVariant(info2->canPlace()).toString());
  item = layout->itemAt(3);
  static_cast<QLabel*>(item->widget())->setText(QVariant(info2->canWin()).toString());
  item = layout->itemAt(5);
  static_cast<QLabel*>(item->widget())->setText(QVariant(info2->pieceEaten()).toString());
  item = layout->itemAt(7);
  static_cast<QLabel*>(item->widget())->setText(QVariant(info2->toScore()).toString());
  item = layout->itemAt(9);
  static_cast<QLabel*>(item->widget())->setText(QVariant(info->couldBeBreakable()).toString());
}

void  Info::addLabel(QFormLayout* layout, QString const& key, QString const& value)
{
    layout->addRow(new QLabel(key, this), new QLabel(value, this));
}
