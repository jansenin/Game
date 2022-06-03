#pragma once

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "GameObjects/Interface/entity.h"
#include "GameObjects/coin.h"
#include "game_view.h"
#include "game_scene.h"
#include "level.h"
#include "constants.h"

class Controller : public QObject {
  Q_OBJECT

 public:
  static Controller* Instance();

  [[nodiscard]] GameView* GetView() const;
  [[nodiscard]] GameScene* GetScene() const;
  [[nodiscard]] Level* GetLevel() const;

  void DealDamageToBase(int damage);

  void AddMoney(int money);
  void LoseMoney(int money);
  int GetBalance();
  bool HaveEnoughMoney(int money);

 signals:
  void GameOver();

 public slots:
  void TickAllTickables();

 private:
  static Controller* instance;

  Controller();

  void SetupScene();
  void LaunchTickTimer();

  void RegulateMoney();

  GameScene* scene_;
  GameView* view_;
  QTimer* tick_timer_;
  Level* level_;
  int balance_ = kStartBalance;

  int base_hp_;
  int damage_per_current_tick_;
};
