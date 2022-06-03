#include "test_tower_slot.h"

#include <QGraphicsScene>

#include "GameObjects/Entities/Towers/tower.h"
#include "Utilities/Resources/pixmap_loader.h"
#include "constants.h"

// TestTowerSlot::TestTowerSlot(const VectorF& coordinates) : TowerSlot(
//     coordinates, PixmapLoader::Pixmaps::kTestTowerSlot) {}
//
// void TestTowerSlot::mousePressEvent(QGraphicsSceneMouseEvent* event) {
//   if (event->button() != Qt::MouseButton::LeftButton) {
//     return TowerSlot::mousePressEvent(event);
//   }
//   if (!IsTakenUp()) {
//     Tower* tower = new Tower(scenePos(), PixmapLoader::Pixmaps::kTestTower, Time(0), Entities::TestTower::kAttackRange);
//     scene()->addItem(tower);
//     TakeUpArea(tower);
//   }
//   QGraphicsItem::mousePressEvent(event);
// }
//
// void TestTowerSlot::paint(
//     QPainter* painter,
//     const QStyleOptionGraphicsItem* option,
//     QWidget* widget) {
//   if (IsTakenUp()) return;
//   Entity::paint(painter, option, widget);
// }
