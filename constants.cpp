#include <QString>
#include "constants.h"

namespace Scene {
const qreal kWidth = 1920;
const qreal kHeight = 1080;
const QRectF kRect{
    -kWidth / 2,
    -kHeight / 2,
    kWidth,
    kHeight};
extern const qreal kMapTextureZValue = -100;
}

namespace LevelData {
extern const int kLevelsCount = 1;
}

namespace Entities {
const int kCircleAttackAreaApproximationPointsCount = 10;
const QString kTestMobId = "TestMob";
const QString kSkeletonId = "Skeleton";

namespace TestTower {
const qreal kAttackRange = 300;
const Time kAttackCooldown = Time(100);
}

namespace TestMob {
const qreal kPassiveMoveSpeed = 5;
const qreal kActiveMoveSpeed = 100;
const qreal kRotationSpeed = 10;
const int kHealth = 30;
}

namespace Skeleton {
const Time kTimeBetweenFrames = 50_ms;
const qreal kSpeed = 50;
const int kHealth = 100;
}

namespace TestProjectile {
const Damage kDamage = Damage(3);
const qreal kSpeed = 500;
}
}  // namespace Entities
