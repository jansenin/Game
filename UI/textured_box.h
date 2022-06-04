#pragma once

#include <QGraphicsObject>
#include <QPixmap>

#include "Utilities/Resources/pixmap_loader.h"
#include "Utilities/Resources/textured_box_pixmaps.h"

class TexturedBox : public QGraphicsObject {
 public:
  enum class OriginPoint { kTopLeft, kBottomLeft, kTopRight, kBottomRight };

  explicit TexturedBox(
      QGraphicsItem* wrapping_item,
      TexturedBoxPixmaps textured_box_pixmaps =
          PixmapLoader::kDefaultTexturedBoxPixmaps);

  void paint(QPainter* painter,
             const QStyleOptionGraphicsItem* option,
             QWidget* widget) override;
  QRectF boundingRect() const override;

  void SetTexturedBoxPixmaps(const TexturedBoxPixmaps& pixmaps);
  void SetWrappingItem(QGraphicsItem* wrapping_item);

  OriginPoint OriginPoint() const;
  void SetOriginPoint(enum OriginPoint origin_point);

  void RecalculateInnerPos();

 protected:
  TexturedBox();

  QRectF ConvertRectConsideringOriginPoint(QRectF rect) const;

  TexturedBoxPixmaps textured_box_pixmaps_;
  QGraphicsItem* wrapping_item_;
  enum OriginPoint origin_point_;
};
