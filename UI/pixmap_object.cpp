#include "pixmap_object.h"

#include <QPainter>

PixmapObject::PixmapObject(QPixmap* pixmap, QGraphicsItem* parent)
  : QGraphicsObject(parent), pixmap_(pixmap) {}

QRectF PixmapObject::boundingRect() const {
  return pixmap_->rect();
}

void PixmapObject::paint(QPainter* painter,
                         const QStyleOptionGraphicsItem* option,
                         QWidget* widget) {
  painter->drawPixmap(0, 0, *pixmap_);
}

QPixmap* PixmapObject::Pixmap() const {
  return pixmap_;
}

void PixmapObject::SetPixmap(QPixmap* pixmap) {
  pixmap_ = pixmap;
}
