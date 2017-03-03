#include "Context.hh"

Context* Context::_context = NULL;

Context::Context(QApplication* app, MainWindow* win)
  : _app(app)
  , _win(win)
{}

Context::~Context()
{}

void Context::create(QApplication* app, MainWindow* win)
{
  _context = new Context(app, win);
}

Context* Context::getInstance()
{
  if (!_context)
    return NULL;
  return _context;
}

QApplication* Context::getApplication()
{
  return _app;
}

MainWindow*  Context::getWindow()
{
  return _win;
}

