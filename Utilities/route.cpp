#include "route.h"

bool Route::isEnd() {
  return index == points.size() - 1;
}

void Route::Move(qreal distance) {
  VectorF start(points[index]);
  VectorF end(points[index + 1]);
  VectorF direction = end - start;
  entity->MoveBy((direction.normalized() * distance));
}
