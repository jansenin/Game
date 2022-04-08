#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

#include "../View/game_view.h"
#include "../Model/Map/game_field.h"
#include "../Model/BasicObjects/Interface/entity.h"

class Controller : public QObject {
  Q_OBJECT
 public:
  Controller();
  [[nodiscard]] GameView* GetView() const;

 private:
  GameField* game_field_;
  QGraphicsScene* scene_;
  GameView* view_;
  Entity* entity;
};

#endif //CONTROLLER_H
