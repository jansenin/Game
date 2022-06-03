#pragma once

#include <QGraphicsObject>

class PixmapObject : public QGraphicsObject {
 public:
  explicit PixmapObject(QPixmap* pixmap, QGraphicsItem* parent = nullptr);

  QRectF boundingRect() const override;
  void paint(QPainter* painter,
             const QStyleOptionGraphicsItem* option,
             QWidget* widget) override;

  QPixmap* Pixmap() const;
  void SetPixmap(QPixmap* pixmap);

 protected:
  QPixmap* pixmap_;
};


