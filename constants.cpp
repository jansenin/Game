#include <QString>
#include "constants.h"

const bool kDebugMode = false;
const int kFPS = 60;
const int kStartBalance = 500;

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


namespace BearTrap {
const Time kCooldown = 1000_ms;
const Damage kDamage = Damage(1000);
}

namespace MagicTower {
const qreal kAttackRangeLevel1 = 400;
const Time kAttackCooldownLevel1 = Time(600);
const qreal kAttackRangeLevel2 = 400;
const Time kAttackCooldownLevel2 = Time(600);
const qreal kAttackRangeLevel3 = 400;
const Time kAttackCooldownLevel3 = Time(600);
const int kMaxLevel = 3;
const int kPrice = 110;
}

namespace CannonTower {
const qreal kAttackRangeLevel1 = 450;
const Time kAttackCooldownLevel1 = Time(3000);
const qreal kAttackRangeLevel2 = 450;
const Time kAttackCooldownLevel2 = Time(3000);
const qreal kAttackRangeLevel3 = 450;
const Time kAttackCooldownLevel3 = Time(3000);
const int kMaxLevel = 3;
const int kPrice = 70;
const qreal kSplashDamagePercent = 0.35;
}

namespace Skeleton {
const Time kTimeBetweenFrames = 50_ms;
const qreal kSpeed = 40;
const int kHealth = 2000;
const int kDamageToBase = 1;
}

namespace Cobra {
const Time kTimeBetweenFrames = 50_ms;
const qreal kSpeed = 100;
const int kHealth = 300;
const int kDamageToBase = 1;
}

namespace Hedgehog {
const Time kTimeBetweenFrames = 50_ms;
const qreal kSpeed = 130;
const int kHealth = 100;
const int kDamageToBase = 1;
}

namespace Dwarf {
const Time kTimeBetweenFrames = 50_ms;
const qreal kSpeed = 60;
const int kHealth = 5000;
const int kDamageToBase = 3;
}

namespace MagicProjectile {
const Damage kDamageLevel1 = Damage(15);
const Damage kDamageLevel2 = Damage(30);
const Damage kDamageLevel3 = Damage(60);
const qreal kSpeed = 20;
const qreal kAcceleration = 400;
const qreal kMaxSpeed = 250;
const qreal kEnemyFindDistance = 300;
const Time kTimeBetweenFrames = 100_ms;
}

namespace CannonProjectile {
const Damage kDamageLevel1 = Damage(100);
const Damage kDamageLevel2 = Damage(200);
const Damage kDamageLevel3 = Damage(400);
const qreal kSpeed = 1000;
}
}  // namespace Entities

namespace Costs {
const int kCoinCost = 100;
const int kCannonTowerCost = 200;
const int kMagicTowerCost = 300;
const int kTowerLevel2Upgrade = 100;
const int kTowerLevel3Upgrade = 150;
const int kBearTrapRepairingCost = 50;
const int kBombExplosionCost = 100;
}
