#pragma once

#include <QGraphicsObject>

class PaddingBox : public QGraphicsObject {
 public:
  PaddingBox(QGraphicsItem* wrapping_item, qreal padding);

  qreal Padding() const;
  void SetPadding(qreal padding);

  QRectF boundingRect() const override;
  void paint(QPainter* painter,
             const QStyleOptionGraphicsItem* option,
             QWidget* widget) override;

 protected:
  qreal padding_;
  QGraphicsItem* wrapping_item_;
};
