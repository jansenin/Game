#ifndef MODEL_BASICOBJECTS_ENTITIES_TOWERS_TEST_TOWER_H_
#define MODEL_BASICOBJECTS_ENTITIES_TOWERS_TEST_TOWER_H_

#include <QTimer>
#include <QPolygonF>

#include "tower.h"

class TestTower : public Tower {
 public:
  explicit TestTower(const QPointF& coordinates);

  void Tick(Time delta) override;

 protected:
  qreal range_;
  QTimer attack_timer_;
  QPolygonF local_attack_area_;
  QPolygonF scene_attack_area_;
};

#endif  // MODEL_BASICOBJECTS_ENTITIES_TOWERS_TEST_TOWER_H_
