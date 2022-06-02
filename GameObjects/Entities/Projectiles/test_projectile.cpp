#include "test_projectile.h"

#include <QtMath>

#include "Utilities/Resources/pixmap_loader.h"
#include "constants.h"

TestProjectile::TestProjectile(const VectorF& coordinates, Entity* target)
  : AutoguidedProjectile(
    coordinates,
    PixmapLoader::Pixmaps::kTestBullet,
    target,
    Entities::TestProjectile::kSpeed,
    Entities::TestProjectile::kMaxSpeed,
    Entities::TestProjectile::kAcceleration,
    Entities::TestProjectile::kEnemyFindDistance,
    Entities::TestProjectile::kDamage),
    cross_cycle_time_(0_ms) {}

void TestProjectile::Tick(Time delta) {
  AutoguidedProjectile::Tick(delta);

  if (target_ == nullptr) {
    return;
  }

  Time cycle_duration =
      Entities::TestProjectile::kCrossAccelerationCycleDuration;
  qreal acceleration_per_pixel =
      Entities::TestProjectile::kCrossAccelerationPerPixel;
  qreal max_acceleration =
      Entities::TestProjectile::kMaxCrossAcceleration;

  qreal distance_to_target = VectorFromThisToTarget().length();
  qreal acceleration = std::min(
      distance_to_target * acceleration_per_pixel,
      max_acceleration);

  cross_cycle_time_ += delta;

  qreal speed_k = sin(
      cross_cycle_time_.seconds() / cycle_duration.seconds() * M_PI * 2);

  VectorF delta_speed =
      speed_.rotated(M_PI / 2).normalized() *
      speed_k * acceleration * delta.seconds();

  speed_ += delta_speed;
}
