#include "graphics_object.h"

GraphicsObject::GraphicsObject(QGraphicsItem* parent)
  : QGraphicsObject(parent) {}

GameScene* GraphicsObject::scene() {
  auto result = dynamic_cast<GameScene*>(QGraphicsObject::scene());
  assert(result != nullptr);
  return result;
}

GameView* GraphicsObject::view() {
  return scene()->view();
}

void GraphicsObject::MoveBy(const VectorF& delta) {
  setPos(pos() + delta);
}
