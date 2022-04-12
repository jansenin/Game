#pragma once

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "GameObjects/BasicObjects/Interface/entity.h"
#include "game_view.h"

class Controller : public QObject {
  Q_OBJECT
 public:
  static Controller* Instance();

  [[nodiscard]] GameView* GetView() const;

 public slots:
  void TickAllTickables();

 private:
  static Controller* instance;

  Controller();

  void SetupScene();
  void LaunchTickTimer();

  QGraphicsScene* scene_;
  GameView* view_;
  QTimer* tick_timer_;
};
