#include "tower_slot.h"

#include <utility>

bool TowerSlot::IsTakenUp() const {
  return tower_ != nullptr;
}

void TowerSlot::TakeUpArea(Tower* tower) {
  tower_ = tower;
}

void TowerSlot::ClearArea() {
  tower_ = nullptr;
}

TowerSlot::TowerSlot(QPointF coordinates, QString path_to_pixmap)
  : Entity(coordinates, std::move(path_to_pixmap)) {}

void TowerSlot::Tick(Time time) {
  if (tower_ != nullptr) {
    tower_->Tick(time);
  }
}
