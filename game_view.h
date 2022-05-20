#pragma once

#include <QGraphicsView>

#include "game_scene.h"

class GameView : public QGraphicsView {
 public:
  explicit GameView(QGraphicsScene* scene, QWidget* parent = nullptr);

  GameScene* scene();
};
