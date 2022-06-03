#pragma once

#include "GameObjects/Interface/entity.h"
#include "Utilities/timer.h"
#include <QPolygonF>

QPolygonF CreateAttackArea(qreal range);

class Tower : public Entity {
 public:
  Tower(const VectorF& coordinates, QPixmap* pixmap, Time cooldown, qreal range, int health = 0);
  Tower(const VectorF& coordinates, Animation* animation, Time cooldown, qreal range, int health = 0);

  void Tick(Time delta) override;

 private:
  Time cooldown_;
  qreal range_;
  Timer attack_timer_;
  QPolygonF local_attack_area_;
  QPolygonF scene_attack_area_;
};
