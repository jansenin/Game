#pragma once

#include "GameObjects/Interface/entity.h"

class BearTrap : public Entity {
 public:
  BearTrap(const VectorF& coordinates, QPixmap* pixmap);
  BearTrap(const VectorF& coordinates, Animation* animation);
  ~BearTrap();

  [[nodiscard]] QRectF boundingRect() const;
  void paint(QPainter* painter,
             const QStyleOptionGraphicsItem* option,
             QWidget* widget);
  void Tick(Time delta);
  void RepairTrap();

  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

 private:
  Animation* idle_animation_;
  Animation* attacking_animation_;
  Animation* broken_animation_;
  Animation* repairing_animation_;

  bool is_broken_ = false;
};
