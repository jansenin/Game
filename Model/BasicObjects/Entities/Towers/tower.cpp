#include "tower.h"

Tower::Tower(QPointF coordinates, int health, qreal width, qreal height, int price, qreal range)
    : Entity(coordinates, health, width, height), price_(price), range_(range) {}

int Tower::GetPrice() const {
  return price_;
}
