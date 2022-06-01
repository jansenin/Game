#include "constants.h"

const qreal kSceneWidth = 1920;
const qreal kSceneHeight = 1080;
const QRectF kSceneRect{
    -kSceneWidth/2,
    -kSceneHeight/2,
    kSceneWidth,
    kSceneHeight};

namespace Entities {
const int kCircleAttackAreaApproximationPointsCount = 10;

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

namespace TestProjectile {
extern const Damage kDamage = Damage(3);
extern const qreal kSpeed = 500;
}
}  // namespace Entities
