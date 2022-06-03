#pragma once

#include "GameObjects/Entities/Mobs/Basis/mob.h"

class Coin : public Entity {
 public:
  Coin(const VectorF& coordinates, QPixmap* pixmap);
  Coin(const VectorF& coordinates, Animation* animation);
  ~Coin();

  void paint(QPainter* painter,
             const QStyleOptionGraphicsItem* option,
             QWidget* widget);
  void Tick(Time delta);

  void SetRoute();

  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

 private:
  Animation* idle_animation_;
  Route* collecting_route_;
  qreal speed_;
};
