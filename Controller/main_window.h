#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "../Model/Map/game_field.h"
#include "../Model/BasicObjects/Interface/entity.h"

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  MainWindow();

 private:
  GameField* gamefield_;
  QGraphicsScene* scene_;
  QGraphicsView* view_;
  Entity* entity;
};

#endif //MAIN_WINDOW_H
