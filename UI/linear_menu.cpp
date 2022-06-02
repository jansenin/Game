#include "linear_menu.h"

#include <QLayoutItem>
#include <QGraphicsObject>
#include <QChildEvent>
#include <QPainter>

#include "constants.h"

LinearMenu::LinearMenu(QGraphicsItem* parent)
    : TexturedBox() {
  textured_box_pixmaps_ = PixmapLoader::kMenuTexturedBoxPixmaps;
  layout_ = new LinearLayout();
  padding_box_ = new PaddingBox(layout_, 0);
  SetWrappingItem(padding_box_);
  this->setParentItem(parent);
  setZValue(UI::kDefaultZValue);
}

void LinearMenu::AddItem(QGraphicsObject* graphics_object) {
  layout_->AddItem(graphics_object);
}

void LinearMenu::RemoveItem(QGraphicsObject* graphics_object) {
  layout_->RemoveItem(graphics_object);
}

void LinearMenu::SetSpacing(qreal spacing) {
  layout_->SetSpacing(spacing);
}

qreal LinearMenu::Spacing() {
  return layout_->Spacing();
}

qreal LinearMenu::Padding() const {
  return padding_box_->Padding();
}

void LinearMenu::SetPadding(qreal padding) {
  prepareGeometryChange();
  padding_box_->SetPadding(padding);
}

LinearMenu::Type LinearMenu::GetType() const {
  return layout_->Type();
}

void LinearMenu::SetType(LinearMenu::Type type) {
  layout_->SetType(type);
}

void LinearMenu::paint(QPainter* painter,
                       const QStyleOptionGraphicsItem* option,
                       QWidget* widget) {
  TexturedBox::paint(painter, option, widget);

  if (kDebugMode) {
    static QPen pen(Qt::red);
    painter->setPen(pen);
    painter->drawRect(TexturedBox::boundingRect());
  }
}
