#include <QString>
#include "constants.h"

const bool kDebugMode = false;
const int kFPS = 60;
const int kStartBalance = 10000;

namespace Scene {
const qreal kWidth = 1920;
const qreal kHeight = 1080;
const QRectF kRect{
    -kWidth / 2,
    -kHeight / 2,
    kWidth,
    kHeight};
const qreal kMapTextureZValue = -10000;
}

namespace UI {
const qreal kDefaultZValue = 10000;
const QColor kButtonDefaultTextColor = Qt::white;
}

namespace LevelData {
extern const int kLevelsCount = 1;
}

namespace Explosions {
const qreal kDefaultRadius = 70.0;
const Damage kDefaultDamage = Damage(50);
const Time kTimeBetweenFrames = 50_ms;
const qreal kZValue = 2000;
}

namespace Entities {
const int kCircleAttackAreaApproximationPointsCount = 10;
const Time kGrowingSpeed = Time(500);
const QString kSkeletonId = "Skeleton";
const QString kCobraId = "Cobra";
const QString kHedgehogId = "Hedgehog";
const QString kDwarfId = "Dwarf";
const int kCoinAppearChance = 3;

namespace MagicTower {
const qreal kAttackRangeLevel1 = 300;
const Time kAttackCooldownLevel1 = Time(4000);
const qreal kAttackRangeLevel2 = 400;
const Time kAttackCooldownLevel2 = Time(3000);
const qreal kAttackRangeLevel3 = 600;
const Time kAttackCooldownLevel3 = Time(2000);
const int kMaxLevel = 3;
const int kPrice = 110;
}

namespace CannonTower {
const qreal kAttackRangeLevel1 = 200;
const Time kAttackCooldownLevel1 = Time(1250);
const qreal kAttackRangeLevel2 = 300;
const Time kAttackCooldownLevel2 = Time(1000);
const qreal kAttackRangeLevel3 = 500;
const Time kAttackCooldownLevel3 = Time(1000);
const int kMaxLevel = 3;
const int kPrice = 70;
}

namespace Skeleton {
const Time kTimeBetweenFrames = 50_ms;
const qreal kSpeed = 50;
const int kHealth = 2000;
const int kDamageToBase = 1;
}

namespace Cobra {
const Time kTimeBetweenFrames = 50_ms;
const qreal kSpeed = 70;
const int kHealth = 160;
const int kDamageToBase = 1;
}

namespace Hedgehog {
const Time kTimeBetweenFrames = 50_ms;
const qreal kSpeed = 110;
const int kHealth = 80;
const int kDamageToBase = 1;
}

namespace Dwarf {
const Time kTimeBetweenFrames = 50_ms;
const qreal kSpeed = 80;
const int kHealth = 10000;
const int kDamageToBase = 1;
}

namespace MagicProjectile {
const Damage kDamageLevel1 = Damage(60);
const Damage kDamageLevel2 = Damage(100);
const Damage kDamageLevel3 = Damage(180);
const qreal kSpeed = 50;
const qreal kAcceleration = 1500;
const qreal kMaxSpeed = 300;
const qreal kEnemyFindDistance = 300;
const Time kTimeBetweenFrames = 50_ms;
}

namespace CannonProjectile {
const Damage kDamageLevel1 = Damage(10);
const Damage kDamageLevel2 = Damage(20);
const Damage kDamageLevel3 = Damage(40);
const qreal kSpeed = 500;
}
}  // namespace Entities

namespace Costs {
const int kCoinCost = 50;
const int kCannonTowerCost = 200;
const int kMagicTowerCost = 300;
const int kTowerLevel2Upgrade = 100;
const int kTowerLevel3Upgrade = 150;
const int kBearTrapRepairingCost = 50;
const int kBombExplosionCost = 100;
}
