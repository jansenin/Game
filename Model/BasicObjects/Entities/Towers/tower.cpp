#include "tower.h"

#include <utility>

Tower::Tower(QPointF coordinates, QString path_to_pixmap, int health)
    : Entity(coordinates, std::move(path_to_pixmap), health) {}
