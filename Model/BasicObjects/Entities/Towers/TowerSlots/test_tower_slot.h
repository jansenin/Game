#ifndef TEST_TOWER_SLOT_H__
#define TEST_TOWER_SLOT_H__

#include "tower_slot.h"

class TestTowerSlot : public TowerSlot {
 public:
  TestTowerSlot(const QPointF& coordinates);

 protected:
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

 public:
  void paint(QPainter* painter,
             const QStyleOptionGraphicsItem* option,
             QWidget* widget) override;
};

#endif //TEST_TOWER_SLOT_H__
