#include "projectile.h"

Projectile::Projectile(const VectorF& coordinates, QPixmap* pixmap)
    : Projectile(coordinates, new Animation(pixmap)) {}

Projectile::Projectile(const VectorF& coordinates, Animation* animation)
    : Entity(coordinates, animation) {}
