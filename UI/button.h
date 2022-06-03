#pragma once

#include <QGraphicsTextItem>

#include "textured_box.h"
#include "Utilities/vector_f.h"
#include "padding_box.h"
#include "pixmap_object.h"
#include "linear_layout.h"

class TextButton : public TexturedBox {
  Q_OBJECT

 public:
  explicit TextButton(VectorF position = {0, 0}, const QString& text = "");

  void SetText(const QString& text);
  QTextDocument* GetTextDocument();

  qreal Padding();
  void SetPadding(qreal padding);

  qreal Spacing();
  void SetSpacing(qreal spacing);

  QPixmap* Icon();
  void SetIcon(QPixmap* icon);

 signals:

  void Clicked();

 protected:
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

  QGraphicsTextItem* text_item_;
  PixmapObject* icon_;
  PaddingBox* padding_box_;
  LinearLayout* layout_;
};
