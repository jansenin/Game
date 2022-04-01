#include "tower_slot.h"

bool TowerSlot::isTakenUp() const {
  return tower_ == nullptr;
}

void TowerSlot::TakeUpArea(Tower* tower) {
  tower_ = tower;
}

void TowerSlot::ClearArea() {
  tower_ = nullptr;
}

TowerSlot::TowerSlot(QPointF coordinates) : Entity(coordinates, 0, 50, 50) {}

void TowerSlot::Tick(Time time) {
  if (tower_ != nullptr) {
    tower_->Tick(time);
  }
}
