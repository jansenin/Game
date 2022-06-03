#pragma once

#include <QRectF>
#include <QColor>

#include "Utilities/time.h"
#include <Utilities/damage.h>

extern const bool kDebugMode;
extern const int kFPS;

namespace Scene {
extern const qreal kWidth;
extern const qreal kHeight;
extern const QRectF kRect;
extern const qreal kMapTextureZValue;
}

namespace UI {
extern const qreal kDefaultZValue;
extern const QColor kButtonDefaultTextColor;
}

namespace LevelData {
extern const int kLevelsCount;
}

namespace Entities {
extern const int kCircleAttackAreaApproximationPointsCount;
extern const QString kTestMobId;
extern const QString kSkeletonId;
extern const QString kCobraId;
extern const QString kHedgehogId;
extern const QString kDwarfId;

namespace MagicTower {
extern const qreal kAttackRangeLevel1;
extern const Time kAttackCooldownLevel1;
extern const qreal kAttackRangeLevel2;
extern const Time kAttackCooldownLevel2;
extern const qreal kAttackRangeLevel3;
extern const Time kAttackCooldownLevel3;
extern const int kMaxLevel;
extern const int kPrice;
}

namespace CannonTower {
extern const qreal kAttackRangeLevel1;
extern const Time kAttackCooldownLevel1;
extern const qreal kAttackRangeLevel2;
extern const Time kAttackCooldownLevel2;
extern const qreal kAttackRangeLevel3;
extern const Time kAttackCooldownLevel3;
extern const int kMaxLevel;
extern const int kPrice;
}

namespace TestMob {
extern const qreal kPassiveMoveSpeed;
extern const qreal kActiveMoveSpeed;
extern const qreal kRotationSpeed;
extern const int kHealth;
}

namespace Skeleton {
extern const Time kTimeBetweenFrames;
extern const qreal kSpeed;
extern const int kHealth;
extern const int kDamageToBase;
}

namespace Cobra {
extern const Time kTimeBetweenFrames;
extern const qreal kSpeed;
extern const int kHealth;
extern const int kDamageToBase;
}

namespace Hedgehog {
extern const Time kTimeBetweenFrames;
extern const qreal kSpeed;
extern const int kHealth;
extern const int kDamageToBase;
}

namespace Dwarf {
extern const Time kTimeBetweenFrames;
extern const qreal kSpeed;
extern const int kHealth;
extern const int kDamageToBase;
}

namespace TestProjectile {
extern const Damage kDamage;
extern const qreal kSpeed;
}
}  // namespace Entities
