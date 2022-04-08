#include "math.h"

qreal Length(QPointF point) {
  return sqrt(point.x() * point.x() + point.y() * point.y());
}

QPointF Normalized(QPointF point) {
  return point / Length(point);
}
