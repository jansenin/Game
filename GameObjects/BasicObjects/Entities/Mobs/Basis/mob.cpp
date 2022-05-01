#include "mob.h"
#include <utility>

std::vector<Route>
    routes{Route({QPointF(50, 50),
                  QPointF(150, 300), QPointF(-100, -50)})};

Mob::Mob(const VectorF& coordinates,
         QPixmap* pixmap,
         int health,
         qreal speed)
    : Entity(coordinates, pixmap, health),
      speed_(speed) {
  route_ = &routes[0];
  route_->AddEntity(this);
  Entity::setPos(route_->GetStart());
}

qreal Mob::GetSpeed() const {
  return speed_;
}

void Mob::SetSpeed(qreal speed) {
  speed_ = speed;
}
