#ifndef CONTEXT_HH
#define CONTEXT_HH

#include <QApplication>
#include "mainwindow.h"

class Context
{
  QApplication    *_app;
  MainWindow     *_win;
  static Context  *_context;

  public:
  Context(QApplication *app, MainWindow *win);
  ~Context();

  QApplication* getApplication();
  MainWindow*  getWindow();

  static void create(QApplication* app, MainWindow* win);
  static Context* getInstance();
};

#endif // CONTEXT_HH
