#ifndef TOWER_SLOT_H
#define TOWER_SLOT_H

#include "../tower.h"
#include "../../../Interface/entity.h"

class TowerSlot : public Entity {
 public:
  TowerSlot(QPointF coordinates);
  [[nodiscard]] bool isTakenUp() const;
  void TakeUpArea(Tower* tower);
  void FreeArea(Tower* tower);

 private:
  Tower* tower_;
};

#endif //TOWER_SLOT_H
