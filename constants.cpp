#include <QString>
#include "constants.h"

const bool kDebugMode = false;
const int kFPS = 60;

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
const QString kTestMobId = "TestMob";
const QString kSkeletonId = "Skeleton";
const QString kCobraId = "Cobra";
const QString kHedgehogId = "Hedgehog";
const QString kDwarfId = "Dwarf";

namespace MagicTower {
const qreal kAttackRangeLevel1 = 300;
const Time kAttackCooldownLevel1 = Time(500);
const qreal kAttackRangeLevel2 = 400;
const Time kAttackCooldownLevel2 = Time(450);
const qreal kAttackRangeLevel3 = 600;
const Time kAttackCooldownLevel3 = Time(400);
const int kMaxLevel = 3;
const int kPrice = 110;
}

namespace CannonTower {
const qreal kAttackRangeLevel1 = 200;
const Time kAttackCooldownLevel1 = Time(200);
const qreal kAttackRangeLevel2 = 300;
const Time kAttackCooldownLevel2 = Time(150);
const qreal kAttackRangeLevel3 = 500;
const Time kAttackCooldownLevel3 = Time(100);
const int kMaxLevel = 3;
const int kPrice = 70;
}

namespace Skeleton {
const Time kTimeBetweenFrames = 50_ms;
const qreal kSpeed = 50;
const int kHealth = 200;
const int kDamageToBase = 1;
}

namespace Cobra {
const Time kTimeBetweenFrames = 50_ms;
const qreal kSpeed = 200;
const int kHealth = 40;
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
const qreal kSpeed = 60;
const int kHealth = 300;
const int kDamageToBase = 1;
}

namespace TestProjectile {
const Damage kDamage = Damage(10);
const qreal kSpeed = 100;
const qreal kAcceleration = 1500;
const qreal kMaxSpeed = 500;
const qreal kEnemyFindDistance = 300;
const qreal kCrossAccelerationPerPixel = 900.0 / 100.0;
const Time kCrossAccelerationCycleDuration = 1500_ms;
const qreal kMaxCrossAcceleration = 600;
}
}  // namespace Entities
