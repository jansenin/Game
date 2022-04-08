#include "entity.h"

#include <utility>
#include "Utilities/resource_cacher.h"

Entity::Entity(
    QPointF coordinates,
    QString path_to_pixmap,
    int health)
    : Damageable(health), QGraphicsItem(),
    pixmap(ResourceCacher::Pixmap(std::move(path_to_pixmap))) {
  setPos(coordinates);
  setFlag(ItemSendsGeometryChanges);
}

QRectF Entity::boundingRect() const {
  return QRectF(
      pixmap->rect().translated(
          QPoint{-pixmap->width()/2, -pixmap->height()/2}
      )
  );
}

void Entity::paint(QPainter* painter,
                   const QStyleOptionGraphicsItem* option,
                   QWidget* widget) {
  painter->save();

  painter->drawPixmap(Entity::boundingRect().toRect(), *pixmap);
  painter->drawRect(Entity::boundingRect());

  painter->restore();
}

void Entity::MoveBy(QPointF delta) {
  setPos(pos() + delta);
}
