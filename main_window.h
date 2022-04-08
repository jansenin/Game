#ifndef MAIN_WINDOW_H_
#define MAIN_WINDOW_H_

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "Controller/controller.h"

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  MainWindow();

 private:
  Controller* controller_;
};

#endif  // MAIN_WINDOW_H_
