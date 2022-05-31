#pragma once

#include <QGraphicsItem>
#include <QPixmap>

#include "Utilities/Resources/pixmap_loader.h"
#include "Utilities/Resources/textured_box_pixmaps.h"

class TexturedBox : public QGraphicsItem {
 public:
  explicit TexturedBox(
      QGraphicsItem* wrapping_item,
      TexturedBoxPixmaps textured_box_pixmaps =
          PixmapLoader::kDefaultTexturedBoxPixmaps);

  void paint(QPainter* painter,
             const QStyleOptionGraphicsItem* option,
             QWidget* widget) override;
  QRectF boundingRect() const override;

  void SetPixmaps(const TexturedBoxPixmaps& pixmaps);
  void SetWrappingItem(QGraphicsItem* wrapping_item);

 protected:
  TexturedBox();

  TexturedBoxPixmaps textured_box_pixmaps_;
  QGraphicsItem* wrapping_item_;
};
