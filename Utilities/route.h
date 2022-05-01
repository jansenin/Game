#pragma once
#include "../GameObjects/BasicObjects/Interface/entity.h"
#include "../Utilities/vector_f.h"
#include <QPointF>
#include <vector>
#include <map>

class Route {
 public:
  Route(const std::vector<QPointF>& points) :  // NOLINT
  points_(points) {}
  void Move(Entity* entity, qreal distance);
  void AddEntity(Entity* entity);
  bool isEnd(Entity* entity);
  VectorF GetStart() const;

 private:
  void ChooseIndex(Entity* entity);
  std::vector<QPointF> points_;
  std::map<Entity*, int> entities_{};
};
