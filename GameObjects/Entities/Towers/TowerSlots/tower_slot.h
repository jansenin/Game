#pragma once

#include "GameObjects/Entities/Towers/tower.h"
#include "GameObjects/Interface/entity.h"

class TowerSlot : public Entity {
 public:
  TowerSlot(const VectorF& coordinates, QPixmap* pixmap);
  TowerSlot(const VectorF& coordinates, Animation* animation);

  [[nodiscard]] bool IsTakenUp() const;
  void TakeUpArea(Tower* tower);
  void ClearArea();
  void Tick(Time time) override;

 protected:
  Tower* tower_;
};
