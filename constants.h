#pragma once

#include <QRectF>
#include <QColor>

#include "Utilities/time.h"
#include <Utilities/damage.h>

extern const bool kDebugMode;

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

namespace TestTower {
extern const qreal kAttackRange;
extern const Time kAttackCooldown;
}

namespace TestMob {
extern const qreal kPassiveMoveSpeed;
extern const qreal kActiveMoveSpeed;
extern const qreal kRotationSpeed;
extern const int kHealth;
}

namespace TestProjectile {
extern const Damage kDamage;
extern const qreal kSpeed;
}
}  // namespace Entities
