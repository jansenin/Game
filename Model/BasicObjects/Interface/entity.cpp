#include "entity.h"

float Entity::GetHeight() const {
  return height_;
}

float Entity::GetWidth() const {
  return width_;
}

Entity::Entity(QPointF coordinates,
               int health, qreal width, qreal height)
    : Damageable(health), QGraphicsItem(), width_(width), height_(height) {
  setPos(coordinates);
  setFlag(ItemSendsGeometryChanges);
}

QRectF Entity::boundingRect() const {
  return QRectF(-GetWidth() / 2, -GetHeight() / 2, GetWidth(), GetHeight());
}
