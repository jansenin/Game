#include "tower.h"

Tower::Tower(const VectorF& coordinates, QPixmap* pixmap, int health)
    : Tower(coordinates, new Animation(pixmap), health) {}

Tower::Tower(const VectorF& coordinates, Animation* animation, int health)
    : Entity(coordinates, animation, health) {}
