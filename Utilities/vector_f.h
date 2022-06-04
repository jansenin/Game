#pragma once

#include <QPointF>

class VectorF : public QPointF {
 public:
  VectorF();
  explicit VectorF(const QPoint& p);
  VectorF(const QPointF& p);  // NOLINT
  VectorF(qreal x, qreal y);

  qreal lengthSquared();
  qreal length();

  void normalize();
  VectorF normalized();

  void rotate(qreal radians);
  VectorF rotated(qreal radians);
};
