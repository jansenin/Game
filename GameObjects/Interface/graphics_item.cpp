#include "graphics_item.h"

GraphicsItem::GraphicsItem(QGraphicsItem* parent) : QGraphicsItem(parent) {}

GameScene* GraphicsItem::scene() {
  auto result = dynamic_cast<GameScene*>(QGraphicsItem::scene());
  assert(result != nullptr);
  return result;
}

GameView* GraphicsItem::view() {
  return scene()->view();
}

void GraphicsItem::MoveBy(const VectorF& delta) {
  setPos(pos() + delta);
}
