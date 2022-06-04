#include "entity.h"

Entity::Entity(
    const VectorF& coordinates,
    QPixmap* pixmap,
    int health)
    : Entity(coordinates, new Animation(pixmap), health) {}

Entity::Entity(const VectorF& coordinates, Animation* animation, int health)
    : Damageable(health),
      GraphicsObject(),
      animation_(animation) {
  animation->Frame();
  setPos(coordinates);
  setFlag(ItemSendsGeometryChanges);
  connect(this, &Entity::yChanged, [this](){
    setZValue(pos().y());
  });
}

QRectF Entity::boundingRect() const {
  const QPixmap* frame = animation_->Frame();
  return QRectF(
      frame->rect().translated(
          QPoint{ -frame->width()/2, -frame->height()/2 }));
}

void Entity::paint(QPainter* painter,
                   const QStyleOptionGraphicsItem* option,
                   QWidget* widget) {
  painter->save();
  static QPen pen(QColor(0, 0, 255, 50));
  painter->setPen(pen);
  // painter->drawRect(boundingRect());
  painter->drawPixmap(boundingRect().toRect(), *animation_->Frame());
  painter->restore();
}

void Entity::Tick(Time delta) {
  QPixmap* previous_frame = animation_->Frame();
  animation_->Tick(delta);
  if (previous_frame != animation_->Frame()) {
    update();
  }
}
