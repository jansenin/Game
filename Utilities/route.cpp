#include "route.h"
#include <cmath>

qreal kEps = 2;

bool Route::isEnd(Entity* entity) {
  return entities_[entity] == points_.size() - 1;
}

void Route::Move(Entity* entity, qreal distance) {
  VectorF start(points_[entities_[entity]]);
  VectorF end(points_[entities_[entity] + 1]);
  VectorF direction = end - start;
  entity->MoveBy((direction.normalized() * distance));
  ChooseIndex(entity);
}

void Route::ChooseIndex(Entity* entity) {
  qreal
      square_distance =
      pow((points_[entities_[entity] + 1].x() - entity->pos().x()), 2) +
          pow((points_[entities_[entity] + 1].y() - entity->pos().y()), 2);
  if (square_distance <= kEps * kEps) {
    ++entities_[entity];
  }
}

void Route::AddEntity(Entity* entity) {
  entities_[entity] = 0;
}

VectorF Route::GetStart() const {
  return points_[0];
}

