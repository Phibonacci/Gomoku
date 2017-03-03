#ifndef INFO_HH
#define INFO_HH

#include "ui_info.h"
#include "IPieceInfo.hh"

class Info : public QDialog, private Ui::Info
{
  Q_OBJECT

 private:
    void  addLabel(QFormLayout*, QString const& key, QString const& value);

public:
  explicit  Info(IPieceInfo* info, IPieceInfo *info2, QWidget *parent = 0);
  void      setValues(IPieceInfo* info, IPieceInfo *info2);

};

#endif // INFO_HH
