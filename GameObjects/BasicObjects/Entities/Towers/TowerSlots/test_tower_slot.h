#pragma once

#include "tower_slot.h"

class TestTowerSlot : public TowerSlot {
 public:
  explicit TestTowerSlot(const VectorF& coordinates);

 protected:
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

 public:
  void paint(QPainter* painter,
             const QStyleOptionGraphicsItem* option,
             QWidget* widget) override;
};
