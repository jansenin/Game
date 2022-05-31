#include "textured_box.h"

#include <QPainter>

#include "Utilities/vector_f.h"

TexturedBox::TexturedBox(
    QGraphicsItem* wrapping_item,
    TexturedBoxPixmaps textured_box_pixmaps)
    : textured_box_pixmaps_(textured_box_pixmaps),
      wrapping_item_(wrapping_item) {
  wrapping_item->setParentItem(this);
  wrapping_item->setPos(0, 0);
}

TexturedBox::TexturedBox() {}

void TexturedBox::paint(QPainter* painter,
                        const QStyleOptionGraphicsItem* option,
                        QWidget* widget) {
  QRectF bounding_rect = boundingRect();
  QRectF inner_rect = wrapping_item_->boundingRect();
  TexturedBoxPixmaps& pixmaps = textured_box_pixmaps_;

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

  painter->drawPixmap(
      // there are gaps without this(actually one gap between right
      // side and inside)
      inner_rect.adjusted(-1, -1, 1, 1),
      *pixmaps.inside,
      pixmaps.inside->rect());

  painter->drawPixmap(
      left_side_rect,
      *pixmaps.left_side,
      pixmaps.left_side->rect());
  painter->drawPixmap(
      right_side_rect,
      *pixmaps.right_side,
      pixmaps.right_side->rect());
  painter->drawPixmap(
      top_side_rect,
      *pixmaps.top_side,
      pixmaps.top_side->rect());
  painter->drawPixmap(
      bottom_side_rect,
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

  wrapping_item_->paint(painter, option, widget);
}

QRectF TexturedBox::boundingRect() const {
  qreal left_side_width = textured_box_pixmaps_.left_side->width();
  qreal right_side_width = textured_box_pixmaps_.right_side->width();
  qreal top_side_height = textured_box_pixmaps_.top_side->height();
  qreal bottom_side_height = textured_box_pixmaps_.bottom_side->height();

  return wrapping_item_->boundingRect().adjusted(
      -left_side_width,
      -top_side_height,
      right_side_width,
      bottom_side_height);
}

void TexturedBox::SetPixmaps(const TexturedBoxPixmaps& pixmaps) {
  textured_box_pixmaps_ = pixmaps;
}

void TexturedBox::SetWrappingItem(QGraphicsItem* wrapping_item) {
  wrapping_item_ = wrapping_item;
}
