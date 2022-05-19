#pragma once
#include "../GameObjects/BasicObjects/Interface/entity.h"
#include "../Utilities/vector_f.h"
#include <QPointF>
#include <vector>
#include <map>

static constexpr qreal kThreshold = 2;

class Route {
 public:
  explicit Route(const std::vector<QPointF>& points) :
  points_(points) {}
  void Move(Entity* entity, qreal distance);
  void AddEntity(Entity* entity);
  void RemoveEntity(Entity* entity);
  bool isEnd(Entity* entity);
  [[nodiscard]] VectorF GetStart() const;

 private:
  void ChooseIndex(Entity* entity);
  std::vector<QPointF> points_;
  std::map<Entity*, int> entity_indexes_{};
};
