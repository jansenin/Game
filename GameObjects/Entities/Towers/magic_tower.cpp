#include "magic_tower.h"
#include "constants.h"
#include "Utilities/Resources/pixmap_loader.h"

using P = PixmapLoader::Pixmaps;

MagicTower::MagicTower(const VectorF& coordinates) :
    Tower(coordinates,
          P::kMagicTowerLevel1,
          Entities::MagicTower::kAttackCooldownLevel1,
          Entities::MagicTower::kAttackRangeLevel1,
          Entities::MagicTower::kMaxLevel,
          Entities::MagicTower::kPrice) {}

void MagicTower::Upgrade() {
  Tower::Upgrade();

  ++Tower::current_level_;
  if (current_level_ == 2) {
    Tower::cooldown_ = Entities::MagicTower::kAttackCooldownLevel2;
    Tower::range_ = Entities::MagicTower::kAttackRangeLevel2;
    delete Tower::animation_;
    Tower::animation_ = new Animation(P::kMagicTowerLevel2);
    update();
    return;
  }
  if (current_level_ == 3) {
    Tower::cooldown_ = Entities::MagicTower::kAttackCooldownLevel3;
    Tower::range_ = Entities::MagicTower::kAttackRangeLevel3;
    delete Tower::animation_;
    Tower::animation_ = new Animation(P::kMagicTowerLevel3);
    update();
    return;
  }
}

void MagicTower::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  Upgrade();
}
