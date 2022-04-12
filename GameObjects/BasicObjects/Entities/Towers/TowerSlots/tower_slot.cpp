#include "tower_slot.h"

bool TowerSlot::IsTakenUp() const {
  return tower_ != nullptr;
}

void TowerSlot::TakeUpArea(Tower* tower) {
  tower_ = tower;
}

void TowerSlot::ClearArea() {
  tower_ = nullptr;
}

TowerSlot::TowerSlot(const VectorF& coordinates, QPixmap* pixmap)
  : Entity(coordinates, pixmap), tower_(nullptr) {}

void TowerSlot::Tick(Time time) {
  if (tower_ != nullptr) {
    tower_->Tick(time);
  }
}
