#ifndef CONTROLLER_MAIN_WINDOW_H_
#define CONTROLLER_MAIN_WINDOW_H_

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

#endif  // CONTROLLER_MAIN_WINDOW_H_
