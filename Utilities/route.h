#pragma once
#include "../GameObjects/BasicObjects/Interface/entity.h"
#include "../Utilities/vector_f.h"
#include <QPointF>
#include <vector>

class Route {
 public:
  void Move(qreal distance);
  bool isEnd();

 private:
  const std::vector<QPointF>& points;
  int index;
  Entity* entity;
};
