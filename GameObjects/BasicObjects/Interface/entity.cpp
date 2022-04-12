#include "entity.h"

Entity::Entity(
    const VectorF& coordinates,
    QPixmap* pixmap,
    int health)
    : Damageable(health), QGraphicsItem(),
    pixmap(pixmap) {
  setPos(coordinates);
  setFlag(ItemSendsGeometryChanges);
}

QRectF Entity::boundingRect() const {
  return QRectF(
      pixmap->rect().translated(
          QPoint{ -pixmap->width()/2, -pixmap->height()/2 }));
}

void Entity::paint(QPainter* painter,
                   const QStyleOptionGraphicsItem* option,
                   QWidget* widget) {
  painter->save();
  painter->drawPixmap(Entity::boundingRect().toRect(), *pixmap);
  painter->restore();
}

void Entity::MoveBy(const VectorF& delta) {
  setPos(pos() + delta);
}
