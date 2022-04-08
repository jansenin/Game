#include "mob.h"

#include <utility>

Mob::Mob(QPointF coordinates, QString path_to_pixmap, int health)
    : Entity(coordinates, std::move(path_to_pixmap), health) {}
