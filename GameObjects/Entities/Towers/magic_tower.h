#pragma once
#include "tower.h"
#include <QGraphicsSceneMouseEvent>

class MagicTower : public Tower {
 public:
  explicit MagicTower(const VectorF& coordinates);
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

 private:
  void Upgrade() override;
};

