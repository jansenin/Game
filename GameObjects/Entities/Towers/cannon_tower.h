#pragma once
#include "tower.h"
#include <QGraphicsSceneMouseEvent>

class CannonTower : public Tower {
 public:
  explicit CannonTower(const VectorF& coordinates);
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

 private:
  void Upgrade() override;
};
