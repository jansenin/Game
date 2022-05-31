#pragma once

#include <QGraphicsItem>
#include <QGraphicsTextItem>

#include "textured_box.h"

// it's position = top(not very accurate) center point
class Tooltip : public TexturedBox {
 public:
  explicit Tooltip(QGraphicsItem* parent = nullptr);
  explicit Tooltip(QString text, QGraphicsItem* parent = nullptr);

  void setPlainText(const QString& text);
  void setHtml(const QString& text);

 protected:
  QGraphicsTextItem* text_item_;
};
