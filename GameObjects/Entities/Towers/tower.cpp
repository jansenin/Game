#include <QtMath>

#include "tower.h"
#include "GameObjects/Entities/Projectiles/test_projectile.h"
#include "GameObjects/Entities/Mobs/Basis/mob.h"
#include "Utilities/Resources/pixmap_loader.h"
#include "constants.h"

QPolygonF CreateAttackArea(qreal range) {
  const int points_count = Entities::kCircleAttackAreaApproximationPointsCount;
  QVector<QPointF> points;
  for (int i = 0 ; i < points_count; ++i) {
    qreal angle = i * 2 * M_PI / points_count;
    points.push_back(QPointF { cos(angle), sin(angle) } * range);
  }
  return QPolygonF(points);
}

Tower::Tower(const VectorF& coordinates, QPixmap* pixmap, Time cooldown,
             qreal range, int max_level, int price, int health)
    : Entity(coordinates, new Animation(pixmap), health),
      attack_timer_(Time(0)),
      range_(range),
      cooldown_(cooldown),
      current_level_(1),
      max_level_(max_level),
      price_(price),
      local_attack_area_(CreateAttackArea(range_)) {
    // TODO(jansenin): change it when coordinates are changed
    scene_attack_area_ = local_attack_area_.translated(scenePos());
}

Tower::Tower(const VectorF& coordinates, Animation* animation,
             Time cooldown, qreal range, int max_level, int price, int health)
    : Entity(coordinates, animation, health),
      attack_timer_(Time(0)),
      range_(range),
      cooldown_(cooldown),
      current_level_(1),
      max_level_(max_level),
      price_(price),
      local_attack_area_(CreateAttackArea(range_)) {
  // TODO(jansenin): change it when coordinates are changed
  scene_attack_area_ = local_attack_area_.translated(scenePos());
}

void Tower::Tick(Time delta) {
  Entity::Tick(delta);

  attack_timer_.Tick(delta);

  if (attack_timer_.IsExpired()) {
    QList<QGraphicsItem*> items_in_attack_area =
        scene()->items(scene_attack_area_);
    for (QGraphicsItem* item : items_in_attack_area) {
      if (Mob* mob = dynamic_cast<Mob*>(item)) {
        if (mob->GetHealth() <= 0) {
          continue;
        }
        scene()->addItem(new TestProjectile(
            scenePos() - QPointF(0, 20), mob));
        attack_timer_.Start(cooldown_);
        break;
      }
    }
  }
}

void Tower::Upgrade() {}
