#pragma once

#include "GameObjects/BasicObjects/Entities/Towers/tower.h"
#include "GameObjects/BasicObjects/Interface/entity.h"

class TowerSlot : public Entity {
 public:
  TowerSlot(const VectorF& coordinates, QPixmap* pixmap);
  [[nodiscard]] bool IsTakenUp() const;
  void TakeUpArea(Tower* tower);
  void ClearArea();
  void Tick(Time time) override;

 protected:
  Tower* tower_;
};
