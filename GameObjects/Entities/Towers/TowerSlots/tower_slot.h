#pragma once

#include "GameObjects/Entities/Towers/tower.h"
#include "GameObjects/Interface/entity.h"

class TowerSlot : public Entity {
 public:
  explicit TowerSlot(const VectorF& coordinates);

  [[nodiscard]] bool IsTakenUp() const;
  void TakeUpArea(Tower* tower);
  void ClearArea();
  void Tick(Time time) override;
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
  void paint(QPainter* painter,
             const QStyleOptionGraphicsItem* option,
             QWidget* widget) override;

 protected:
  Tower* tower_;
};
