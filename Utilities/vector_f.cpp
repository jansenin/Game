#include "vector_f.h"
#include <QtMath>

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

void VectorF::rotate(qreal radians) {
  *this = this->rotated(radians);
}

VectorF VectorF::rotated(qreal radians) {
  qreal s = sin(radians);
  qreal c = cos(radians);
  return VectorF(
      x() * c - y() * s,
      x() * s + y() * c);
}
