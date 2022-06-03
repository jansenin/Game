#include "test_tower.h"

#include <QtMath>

#include "GameObjects/Entities/Projectiles/test_projectile.h"
#include "GameObjects/Entities/Mobs/Basis/mob.h"
#include "Utilities/Resources/pixmap_loader.h"
#include "constants.h"

namespace {
QPolygonF CreateAttackArea(qreal range) {
  const int points_count = Entities::kCircleAttackAreaApproximationPointsCount;
  QVector<QPointF> points;
  for (int i = 0 ; i < points_count; ++i) {
    qreal angle = i * 2 * M_PI / points_count;
    points.push_back(QPointF { cos(angle), sin(angle) } * range);
  }
  return QPolygonF(points);
}
}  // namespace

TestTower::TestTower(const VectorF& coordinates)
  : Tower(coordinates, PixmapLoader::Pixmaps::kTestTower),
    attack_timer_(Time(0)),
    range_(Entities::TestTower::kAttackRange),
    local_attack_area_(CreateAttackArea(range_)) {
  // TODO(jansenin): change it when coordinates are changed
  scene_attack_area_ = local_attack_area_.translated(scenePos());
}

void TestTower::Tick(Time delta) {
  Tower::Tick(delta);

  attack_timer_.Tick(delta);

  if (attack_timer_.IsExpired()) {
    QList<QGraphicsItem*> items_in_attack_area =
        scene()->items(scene_attack_area_);
    for (QGraphicsItem* item : items_in_attack_area) {
      if (Mob* mob = dynamic_cast<Mob*>(item)) {
        if (mob->GetHealth() <= 0) {
          continue;
        }
        scene()->addItem(new TestProjectile(scenePos(), mob));
        attack_timer_.Start(Entities::TestTower::kAttackCooldown);
        break;
      }
    }
  }
}
