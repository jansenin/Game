#pragma once

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "GameObjects/BasicObjects/Interface/entity.h"
#include "game_view.h"
#include "game_scene.h"
#include "level.h"

class Controller : public QObject {
  Q_OBJECT
 public:
  static Controller* Instance();

  [[nodiscard]] GameView* GetView() const;
  [[nodiscard]] GameScene* GetScene() const;
  [[nodiscard]] Level* GetLevel() const;


 public slots:
  void TickAllTickables();

 private:
  static Controller* instance;

  Controller();

  void SetupScene();
  void LaunchTickTimer();

  GameScene* scene_;
  GameView* view_;
  QTimer* tick_timer_;
  Level* level_;
};
