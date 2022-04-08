#ifndef MODEL_BASICOBJECTS_ENTITIES_MOBS_MOB_TEST_H_
#define MODEL_BASICOBJECTS_ENTITIES_MOBS_MOB_TEST_H_

#include <QPixmap>

#include "Basis/mob.h"

class MobTest : public Mob {
 public:
  explicit MobTest(const QPointF& coordinates = QPointF{0, 0});

  void Tick(Time delta) override;

 protected:
  void keyPressEvent(QKeyEvent* event) override;
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
};

#endif  // MODEL_BASICOBJECTS_ENTITIES_MOBS_MOB_TEST_H_
