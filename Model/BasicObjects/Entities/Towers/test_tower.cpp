#include "test_tower.h"

#include <QGraphicsScene>

#include "Model/BasicObjects/Entities/Projectiles/test_projectile.h"
#include "Model/BasicObjects/Entities/Mobs/Basis/mob.h"

namespace {
QPolygonF CreateAttackArea(qreal range) {
  const int points_count = 10;
  QList<QPointF> points;
  for (int i = 0 ; i < points_count; ++i) {
    qreal angle = i * 2 * M_PI / points_count;
    points.push_back(QPointF { cos(angle), sin(angle) } * range);
  }
  return QPolygonF(points);
}
}  // namespace

TestTower::TestTower(const QPointF& coordinates)
  : Tower(coordinates, ":images/test_tower.png"),
    attack_timer_(this),
    range_(1000),
    local_attack_area_(CreateAttackArea(range_)) {
  attack_timer_.setSingleShot(true);
  attack_timer_.setInterval(1000);

  // TODO(jansenin): change it when coordinates are changed
  scene_attack_area_ = local_attack_area_.translated(scenePos());
}

void TestTower::Tick(Time delta) {
  static bool fired = false;
  if (fired) return;
  QList<QGraphicsItem*> items_in_attack_area =
      scene()->items(scene_attack_area_);
  for (QGraphicsItem* item : items_in_attack_area) {
    if (Mob* mob = dynamic_cast<Mob*>(item)) {
      scene()->addItem(new TestProjectile(scenePos(), mob));
      // attack_timer_.start();
      fired = true;
      break;
    }
  }

  // if (!attack_timer_.isActive()) {
  //   QList<QGraphicsItem*> items_in_attack_area =
  //      scene()->items(local_attack_area_);
  //   for (QGraphicsItem* item : items_in_attack_area) {
  //     if (Entity* entity = dynamic_cast<Entity*>(item)) {
  //       scene()->addItem(new TestProjectile(mapToScene(pos()), entity));
  //       attack_timer_.start();
  //       break;
  //     }
  //   }
  // }
}
