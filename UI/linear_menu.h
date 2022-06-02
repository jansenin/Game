#pragma once

#include "textured_box.h"
#include "linear_layout.h"
#include "padding_box.h"

class LinearMenu : public TexturedBox {
 public:
  using Type = enum LinearLayout::Type;

  explicit LinearMenu(QGraphicsItem* parent = nullptr);

  void AddItem(QGraphicsObject* graphics_object);
  void RemoveItem(QGraphicsObject* graphics_object);

  void SetSpacing(qreal spacing);
  qreal Spacing();

  qreal Padding() const;
  void SetPadding(qreal padding);

  Type GetType() const;
  void SetType(Type type);

  void paint(QPainter* painter,
             const QStyleOptionGraphicsItem* option,
             QWidget* widget) override;

 protected:
  LinearLayout* layout_;
  PaddingBox* padding_box_;
};
