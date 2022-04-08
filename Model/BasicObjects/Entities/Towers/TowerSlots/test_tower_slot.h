#ifndef MODEL_BASICOBJECTS_ENTITIES_TOWERS_TOWERSLOTS_TEST_TOWER_SLOT_H_
#define MODEL_BASICOBJECTS_ENTITIES_TOWERS_TOWERSLOTS_TEST_TOWER_SLOT_H_

#include "tower_slot.h"

class TestTowerSlot : public TowerSlot {
 public:
  explicit TestTowerSlot(const QPointF& coordinates);

 protected:
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

 public:
  void paint(QPainter* painter,
             const QStyleOptionGraphicsItem* option,
             QWidget* widget) override;
};

#endif  // MODEL_BASICOBJECTS_ENTITIES_TOWERS_TOWERSLOTS_TEST_TOWER_SLOT_H_
