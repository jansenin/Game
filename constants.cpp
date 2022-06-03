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
const qreal kDefaultRadius = 50.0;
const Damage kDefaultDamage = Damage(50);
const Time kTimeBetweenFrames = 50_ms;
}

namespace Entities {
const int kCircleAttackAreaApproximationPointsCount = 10;
const QString kTestMobId = "TestMob";
const QString kSkeletonId = "Skeleton";
const QString kCobraId = "Cobra";
const QString kHedgehogId = "Hedgehog";
const QString kDwarfId = "Dwarf";

namespace TestTower {
const qreal kAttackRange = 300;
const Time kAttackCooldown = Time(100);
}

namespace TestMob {
const qreal kPassiveMoveSpeed = 5;
const qreal kActiveMoveSpeed = 100;
const qreal kRotationSpeed = 10;
const int kHealth = 30;
const int kDamageToBase = 1;
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
const Damage kDamage = Damage(3);
const qreal kSpeed = 500;
}
}  // namespace Entities
