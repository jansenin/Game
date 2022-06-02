#pragma once

#include <QGraphicsTextItem>

#include "textured_box.h"
#include "Utilities/vector_f.h"
#include "UI/padding_box.h"

class TextButton : public TexturedBox {
  Q_OBJECT
 public:
  explicit TextButton(VectorF position = {0, 0}, const QString& text = "");

  void SetText(const QString& text);
  QTextDocument* GetTextDocument();

  qreal Padding();
  void SetPadding(qreal padding);

 signals:

  void Clicked();

 protected:
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

  QGraphicsTextItem* text_item_;
  PaddingBox* padding_box;
};
