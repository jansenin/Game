#pragma once

#include <QRectF>

#include "Utilities/time.h"
#include <Utilities/damage.h>

extern const qreal kSceneWidth;
extern const qreal kSceneHeight;
extern const QRectF kSceneRect;

namespace Entities {
extern const int kCircleAttackAreaApproximationPointsCount;

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
