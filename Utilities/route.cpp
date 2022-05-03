#include "route.h"
#include <Qtmath>

bool Route::isEnd(Entity* entity) {
  return entity_indexes_[entity] == points_.size() - 1;
}

void Route::Move(Entity* entity, qreal distance) {
  VectorF start(entity->pos());
  VectorF end(points_[entity_indexes_[entity] + 1]);
  VectorF direction = end - start;
  entity->MoveBy((direction.normalized() * distance));
  ChooseIndex(entity);
}

void Route::ChooseIndex(Entity* entity) {
  qreal square_distance =
      pow((points_[entity_indexes_[entity] + 1].x() - entity->pos().x()), 2) +
          pow((points_[entity_indexes_[entity] + 1].y() - entity->pos().y()), 2);
  if (square_distance <= kThreshold * kThreshold) {
    ++entity_indexes_[entity];
  }
}

void Route::AddEntity(Entity* entity) {
  entity_indexes_[entity] = 0;
}

VectorF Route::GetStart() const {
  return points_[0];
}

void Route::RemoveEntity(Entity* entity) {
  entity_indexes_.erase(entity);
}

