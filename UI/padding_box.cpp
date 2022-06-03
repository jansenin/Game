#include "padding_box.h"

#include <QPainter>

#include "Utilities/vector_f.h"
#include "constants.h"

PaddingBox::PaddingBox(QGraphicsItem* wrapping_item, qreal padding)
  : wrapping_item_(wrapping_item), padding_(padding) {
  wrapping_item->setParentItem(this);
  wrapping_item->setPos(padding, padding);
  setZValue(UI::kDefaultZValue);
}

qreal PaddingBox::Padding() const {
  return padding_;
}
void PaddingBox::SetPadding(qreal padding) {
  padding_ = padding;
  wrapping_item_->setPos(padding, padding);
}

QRectF PaddingBox::boundingRect() const {
  QRectF inner_rect = wrapping_item_->boundingRect();
  VectorF inner_rect_half_size = VectorF(
      inner_rect.width() / 2,
      inner_rect.height() / 2);
  QRectF result = QRectF(
      inner_rect.center() - inner_rect_half_size * scale(),
      inner_rect.center() + inner_rect_half_size * scale());
  result.translate(-result.x(), -result.y());
  result.adjust(0, 0, 2 * padding_, 2 * padding_);
  return result;
}

void PaddingBox::paint(QPainter* painter,
                       const QStyleOptionGraphicsItem* option,
                       QWidget* widget) {
  if (kDebugMode) {
    static QPen white_pen(Qt::white);
    static QPen green_pen(Qt::green);
    static QPen blue_pen(Qt::blue);

    painter->setPen(white_pen);
    painter->drawRect(boundingRect());

    painter->setPen(green_pen);
    painter->drawRect(
        wrapping_item_->boundingRect().translated(wrapping_item_->pos()));

    painter->setPen(blue_pen);
    painter->drawEllipse(-5, -5, 10, 10);
  }
}
