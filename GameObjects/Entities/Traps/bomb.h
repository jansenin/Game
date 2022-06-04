#pragma once

#include "GameObjects/Entities/Mobs/Basis/mob.h"

class Bomb : public Entity {
 public:
  explicit Bomb(const VectorF& coordinates);
  Bomb(const VectorF& coordinates, Animation* animation);
  ~Bomb();

  [[nodiscard]] QRectF boundingRect() const;
  void paint(QPainter* painter,
             const QStyleOptionGraphicsItem* option,
             QWidget* widget);
  void Tick(Time delta);

  void Explode();

  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

 private:
  Animation* idle_animation_;
  Animation* explosion_animation_;

  bool activated_ = false;
};
