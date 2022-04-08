#ifndef MODEL_BASICOBJECTS_ENTITIES_TOWERS_TOWERSLOTS_TOWER_SLOT_H_
#define MODEL_BASICOBJECTS_ENTITIES_TOWERS_TOWERSLOTS_TOWER_SLOT_H_

#include "../tower.h"
#include "../../../Interface/entity.h"

class TowerSlot : public Entity {
 public:
  TowerSlot(QPointF coordinates, QString path_to_pixmap);
  [[nodiscard]] bool IsTakenUp() const;
  void TakeUpArea(Tower* tower);
  void ClearArea();
  void Tick(Time time) override;

 protected:
  Tower* tower_;
};

#endif  // MODEL_BASICOBJECTS_ENTITIES_TOWERS_TOWERSLOTS_TOWER_SLOT_H_
