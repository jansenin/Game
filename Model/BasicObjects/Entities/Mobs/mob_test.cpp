#include "mob_test.h"

#include <QGraphicsScene>

#include "Utilities/resource_cacher.h"
#include "Utilities/math.h"

void MobTest::Tick(Time delta) {
  //setPos(pos() + QPointF{static_cast<qreal>(delta.seconds() * 5), 0});
}

void MobTest::keyPressEvent(QKeyEvent* event) {
  if (health_ == 0) return;
  QPointF velocity_vector = mapToParent(pos() + QPointF{0, -10}) - mapToParent(pos());
  if (event->key() == Qt::Key::Key_Left) {
    setRotation(rotation() - 10);
  } else if (event->key() == Qt::Key::Key_Right) {
    setRotation(rotation() + 10);
  } else if (event->key() == Qt::Key::Key_Up) {
    setPos(pos() + velocity_vector);
  } else if (event->key() == Qt::Key::Key_Down) {
    setPos(pos() - velocity_vector);
  }
  update();
}

void MobTest::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  scene()->addItem(new MobTest(pos() + QPointF{10, 30}));
}

MobTest::MobTest(const QPointF& coordinates) : Mob(coordinates, ":images/test_mob.png", 30) {
  setFlag(QGraphicsItem::ItemIsFocusable, true);
}
