#include "tower_slot.h"

bool TowerSlot::isTakenUp() const {
  return tower_ == nullptr;
}

void TowerSlot::TakeUpArea(Tower* tower) {
  tower_ = tower;
}

void TowerSlot::FreeArea(Tower* tower) {
  tower_ = nullptr;
}

TowerSlot::TowerSlot(QPointF coordinates) : Entity(coordinates, 0, 50, 50) {}
