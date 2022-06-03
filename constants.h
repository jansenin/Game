#pragma once

#include <QRectF>
#include <QColor>

#include "Utilities/time.h"
#include <Utilities/damage.h>

extern const bool kDebugMode;
extern const int kFPS;
extern const int kStartBalance;

namespace Costs {
extern const int kCoinCost;
extern const int kCannonTowerCost;
extern const int kMagicTowerCost;
extern const int kTowerLevel2Upgrade;
extern const int kTowerLevel3Upgrade;
extern const int kBearTrapRepairingCost;
extern const int kBombExplosionCost;
}

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

namespace Explosions {
extern const qreal kDefaultRadius;
extern const Damage kDefaultDamage;
extern const Time kTimeBetweenFrames;
extern const qreal kZValue;
}

namespace Entities {
extern const int kCircleAttackAreaApproximationPointsCount;
extern const Time kGrowingSpeed;
extern const QString kSkeletonId;
extern const QString kCobraId;
extern const QString kHedgehogId;
extern const QString kDwarfId;
extern const int kCoinAppearChance;

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

namespace MagicProjectile {
extern const Damage kDamageLevel1;
extern const Damage kDamageLevel2;
extern const Damage kDamageLevel3;
extern const qreal kSpeed;
extern const qreal kAcceleration;
extern const qreal kMaxSpeed;
extern const qreal kEnemyFindDistance;
extern const Time kTimeBetweenFrames;
}

namespace CannonProjectile {
extern const Damage kDamageLevel1;
extern const Damage kDamageLevel2;
extern const Damage kDamageLevel3;
extern const qreal kSpeed;
}
}  // namespace Entities
