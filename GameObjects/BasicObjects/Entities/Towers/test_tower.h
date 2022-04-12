#pragma once

#include "Utilities/timer.h"
#include <QPolygonF>

#include "tower.h"

class TestTower : public Tower {
 public:
  explicit TestTower(const VectorF& coordinates);

  void Tick(Time delta) override;

 protected:
  qreal range_;
  Timer attack_timer_;
  QPolygonF local_attack_area_;
  QPolygonF scene_attack_area_;
};
