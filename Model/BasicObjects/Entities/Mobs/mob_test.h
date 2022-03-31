#ifndef MOB_TEST_H
#define MOB_TEST_H

#include "Basis/mob.h"

class MobTest : public Mob {
 public:
  MobTest(const QPointF& coordinates = QPointF{0, 0});

  void Tick(Time delta) override;
  void paint(QPainter* painter,
             const QStyleOptionGraphicsItem* option,
             QWidget* widget) override;
 protected:
  void keyPressEvent(QKeyEvent* event) override;
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
};

#endif //MOB_TEST_H
