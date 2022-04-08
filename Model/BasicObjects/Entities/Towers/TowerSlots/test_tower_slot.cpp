#include "test_tower_slot.h"

#include <QGraphicsScene>
#include "Model/BasicObjects/Entities/Towers/test_tower.h"

TestTowerSlot::TestTowerSlot(const QPointF& coordinates) : TowerSlot(
    coordinates, ":images/test_tower_slot.png") {}

void TestTowerSlot::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  if (event->button() != Qt::MouseButton::LeftButton) {
    return TowerSlot::mousePressEvent(event);
  }
  if (!IsTakenUp()) {
    TestTower* tower = new TestTower(scenePos());
    scene()->addItem(tower);
    TakeUpArea(tower);
  }
  QGraphicsItem::mousePressEvent(event);
}

void TestTowerSlot::paint(
    QPainter* painter,
    const QStyleOptionGraphicsItem* option,
    QWidget* widget) {
  if (IsTakenUp()) return;
  Entity::paint(painter, option, widget);
}
