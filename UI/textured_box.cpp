#include "textured_box.h"

#include <QPainter>

#include "Utilities/vector_f.h"
#include "constants.h"

TexturedBox::TexturedBox(
    QGraphicsItem* wrapping_item,
    TexturedBoxPixmaps textured_box_pixmaps)
    : textured_box_pixmaps_(textured_box_pixmaps),
      wrapping_item_(wrapping_item) {
  wrapping_item->setParentItem(this);
  wrapping_item->setPos(
      textured_box_pixmaps_.left_side->width(),
      textured_box_pixmaps_.top_side->height());
  setZValue(UI::kDefaultZValue);
}

TexturedBox::TexturedBox() {
  setZValue(UI::kDefaultZValue);
}

void TexturedBox::paint(QPainter* painter,
                        const QStyleOptionGraphicsItem* option,
                        QWidget* widget) {
  TexturedBoxPixmaps& pixmaps = textured_box_pixmaps_;

  QRectF bounding_rect = boundingRect();
  QRectF inner_rect = wrapping_item_->boundingRect().translated(
      pixmaps.left_side->width(),
      pixmaps.top_side->height());

  QRectF left_side_rect = {
      bounding_rect.x(),
      inner_rect.y(),
      static_cast<qreal>(pixmaps.left_side->width()),
      inner_rect.height()};
  QRectF right_side_rect = {
      inner_rect.right(),
      inner_rect.y(),
      static_cast<qreal>(pixmaps.right_side->width()),
      inner_rect.height()};
  QRectF top_side_rect = {
      inner_rect.x(),
      bounding_rect.y(),
      inner_rect.width(),
      static_cast<qreal>(pixmaps.top_side->height())};
  QRectF bottom_side_rect = {
      inner_rect.x(),
      inner_rect.bottom(),
      inner_rect.width(),
      static_cast<qreal>(pixmaps.bottom_side->height())};

  // there are -1 because of gaps
  painter->drawPixmap(
      inner_rect.adjusted(-1, -1, 1, 1),
      *pixmaps.inside,
      pixmaps.inside->rect());

  painter->drawPixmap(
      left_side_rect.adjusted(0, -1, 0, 1),
      *pixmaps.left_side,
      pixmaps.left_side->rect());
  painter->drawPixmap(
      right_side_rect.adjusted(0, -1, 0, 1),
      *pixmaps.right_side,
      pixmaps.right_side->rect());
  painter->drawPixmap(
      top_side_rect.adjusted(-1, 0, 1, 0),
      *pixmaps.top_side,
      pixmaps.top_side->rect());
  painter->drawPixmap(
      bottom_side_rect.adjusted(-1, 0, 1, 0),
      *pixmaps.bottom_side,
      pixmaps.bottom_side->rect());


  VectorF top_left_corner_pos = {
      bounding_rect.left(),
      bounding_rect.top()
  };
  VectorF top_right_corner_pos = {
      bounding_rect.right() - pixmaps.top_right_corner->width(),
      bounding_rect.top()
  };
  VectorF bottom_left_corner_pos = {
      bounding_rect.left(),
      bounding_rect.bottom() - pixmaps.bottom_left_corner->height()
  };
  VectorF bottom_right_corner_pos = {
      bounding_rect.right() - pixmaps.bottom_right_corner->width(),
      bounding_rect.bottom() - pixmaps.bottom_right_corner->height()
  };

  painter->drawPixmap(top_left_corner_pos, *pixmaps.top_left_corner);
  painter->drawPixmap(top_right_corner_pos, *pixmaps.top_right_corner);
  painter->drawPixmap(bottom_left_corner_pos, *pixmaps.bottom_left_corner);
  painter->drawPixmap(bottom_right_corner_pos, *pixmaps.bottom_right_corner);

  if (kDebugMode) {
    painter->setPen(QPen(Qt::white, 3));
    painter->drawRect(boundingRect());

    painter->setPen(QPen(Qt::yellow, 5));
    painter->drawRect(inner_rect);
  }
}

QRectF TexturedBox::boundingRect() const {
  qreal left_side_width = textured_box_pixmaps_.left_side->width();
  qreal right_side_width = textured_box_pixmaps_.right_side->width();
  qreal top_side_height = textured_box_pixmaps_.top_side->height();
  qreal bottom_side_height = textured_box_pixmaps_.bottom_side->height();

  QRectF unscaled_result = wrapping_item_->boundingRect().adjusted(
      0,
      0,
      right_side_width + left_side_width,
      bottom_side_height + top_side_height);
  VectorF half_size =
      VectorF(unscaled_result.width(), unscaled_result.height()) / 2;

  return QRectF(
      unscaled_result.center() - half_size,
      unscaled_result.center() + half_size);
}

void TexturedBox::SetTexturedBoxPixmaps(const TexturedBoxPixmaps& pixmaps) {
  prepareGeometryChange();
  textured_box_pixmaps_ = pixmaps;
  wrapping_item_->setPos(
      textured_box_pixmaps_.left_side->width(),
      textured_box_pixmaps_.top_side->height());
}

void TexturedBox::SetWrappingItem(QGraphicsItem* wrapping_item) {
  prepareGeometryChange();
  wrapping_item_ = wrapping_item;
  wrapping_item->setParentItem(this);
  wrapping_item->setPos(
      textured_box_pixmaps_.left_side->width(),
      textured_box_pixmaps_.top_side->height());
}
