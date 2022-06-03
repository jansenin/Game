#pragma once

#include <vector>
#include <map>

#include <QPointF>

#include "GameObjects/Interface/entity.h"
#include "Utilities/vector_f.h"

static constexpr qreal kThreshold = 5;

class Route {
 public:
  explicit Route(const std::vector<VectorF>& points) :
  points_(points) {}
  void Move(Entity* entity, qreal distance);
  void AddEntity(Entity* entity);
  void RemoveEntity(Entity* entity);
  bool isEnd(Entity* entity);
  [[nodiscard]] VectorF GetStart() const;

 private:
  void ChooseIndex(Entity* entity);
  std::vector<VectorF> points_;
  std::map<Entity*, int> entity_indexes_{};
};
