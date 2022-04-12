#include "mob.h"

Mob::Mob(const VectorF& coordinates, QPixmap* pixmap, int health)
    : Entity(coordinates, pixmap, health) {}
