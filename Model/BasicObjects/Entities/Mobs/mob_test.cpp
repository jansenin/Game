#include "mob_test.h"

#include <QGraphicsScene>

void MobTest::Tick(Time delta) {
  setPos(pos() + QPointF{static_cast<qreal>(delta.ms() * 5), 0});
}

void MobTest::paint(QPainter* painter,
                    const QStyleOptionGraphicsItem* option,
                    QWidget* widget) {
  painter->save();

  static QPen pen(Qt::black);
  static QBrush brush(Qt::white);
  painter->setPen(pen);
  painter->setBrush(brush);
  painter->drawRect(boundingRect());

  painter->restore();
}

void MobTest::keyPressEvent(QKeyEvent* event) {
  setRotation(50);
  if (event->key() == Qt::Key::Key_Left) {
    setPos(pos() + QPointF{-1, 0});
  } else if (event->key() == Qt::Key::Key_Right) {
    setPos(pos() + QPointF{1, 0});
  } else if (event->key() == Qt::Key::Key_Up) {
    setPos(pos() + QPointF{0, -1});
  } else if (event->key() == Qt::Key::Key_Down) {
    setPos(pos() + QPointF{0, 1});
  }
  update();
}

void MobTest::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  scene()->addItem(new MobTest(pos() + QPointF{10, 30}));
}

MobTest::MobTest(const QPointF& coordinates) : Mob(coordinates, 10, 50, 50) {
  setFlag(QGraphicsItem::ItemIsFocusable, true);
}
