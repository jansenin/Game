#include "test_mob.h"

#include <QGraphicsScene>

#include "Utilities/Resources/pixmap_loader.h"
#include "constants.h"

void TestMob::Tick(Time delta) {
  if (!Mob::route_->isEnd(this)) {
    Mob::route_->Move(this, Mob::speed_ * delta.seconds());
  }
}

void TestMob::keyPressEvent(QKeyEvent* event) {
  if (health_ == 0) return;
  QPointF velocity_vector = mapToParent(pos() +
      VectorF{0, -Entities::TestMob::kActiveMoveSpeed}) - mapToParent(pos());
  if (event->key() == Qt::Key::Key_Left) {
    setRotation(rotation() - Entities::TestMob::kRotationSpeed);
  } else if (event->key() == Qt::Key::Key_Right) {
    setRotation(rotation() + Entities::TestMob::kRotationSpeed);
  } else if (event->key() == Qt::Key::Key_Up) {
    setPos(pos() + velocity_vector);
  } else if (event->key() == Qt::Key::Key_Down) {
    setPos(pos() - velocity_vector);
  }
}

void TestMob::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  scene()->addItem(new TestMob(pos() + VectorF{10, 30}));
}

TestMob::TestMob(const VectorF& coordinates)
    : Mob(
    coordinates,
    PixmapLoader::Pixmaps::kTestMob,
    Entities::TestMob::kHealth) {
  setFlag(QGraphicsItem::ItemIsFocusable, true);
}
void TestMob::paint(QPainter* painter,
                    const QStyleOptionGraphicsItem* option,
                    QWidget* widget) {
  Entity::paint(painter, option, widget);
  if (health_ == 0) {
    painter->drawLine(-50, -50, 50, 50);
    painter->drawLine(50, -50, -50, 50);
  }
}
