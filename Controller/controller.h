#pragma once

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "GameObjects/Interface/entity.h"
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

  void DealDamageToBase(int damage);

 signals:
  void GameOver();

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

  int base_hp_;
  int damage_per_current_tick_;
};
