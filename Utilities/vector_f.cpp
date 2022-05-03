#include "vector_f.h"
#include <Qtmath>

VectorF::VectorF() {}
VectorF::VectorF(const QPoint& p) : QPointF(p) {}
VectorF::VectorF(qreal x, qreal y) : QPointF(x, y) {}
VectorF::VectorF(const QPointF& p) : QPointF(p) {}

qreal VectorF::lengthSquared() {
  return x() * x() + y() * y();
}

qreal VectorF::length() {
  return sqrt(lengthSquared());
}

void VectorF::normalize() {
  *this /= length();
}

VectorF VectorF::normalized() {
  return *this / length();
}
