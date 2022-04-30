#pragma once
#include "../GameObjects/BasicObjects/Interface/entity.h"
#include "../Utilities/vector_f.h"
#include <QPointF>
#include <vector>

class Route {
 public:
  Route(Entity* entity, const std::vector<QPointF>& points) :
  entity_(entity), points_(points), index_(0) {}
  Route(Route&& route);
  void Move(qreal distance);
  bool isEnd();

 private:
  void ChooseIndex();
  std::vector<QPointF> points_;
  int index_{0};
  Entity* entity_;
};
