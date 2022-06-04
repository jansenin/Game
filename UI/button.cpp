#include "button.h"

#include <QTextDocument>
#include <QCursor>

#include "Utilities/Resources/pixmap_loader.h"
#include "constants.h"

TextButton::TextButton(VectorF position, const QString& text)
  : TexturedBox() {
  textured_box_pixmaps_ = PixmapLoader::kButtonTexturedBoxPixmaps;
  text_item_ = new QGraphicsTextItem();
  icon_ = new PixmapObject(PixmapLoader::Pixmaps::kEmpty);
  layout_ = new LinearLayout();
  layout_->AddItem(icon_);
  layout_->AddItem(text_item_);
  layout_->SetType(LinearLayout::Type::Horizontal);
  padding_box_ = new PaddingBox(layout_, 0);
  text_item_->setDefaultTextColor(UI::kButtonDefaultTextColor);
  SetWrappingItem(padding_box_);
  setPos(position);
  SetText(text);
  setZValue(UI::kDefaultZValue);
  setCursor(Qt::PointingHandCursor);
}

void TextButton::SetText(const QString& text) {
  prepareGeometryChange();
  text_item_->setPlainText(text);
}

void TextButton::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  emit Clicked();
}

QTextDocument* TextButton::GetTextDocument() {
  return text_item_->document();
}

qreal TextButton::Padding() {
  return padding_box_->Padding();
}

void TextButton::SetPadding(qreal padding) {
  padding_box_->SetPadding(padding);
}

qreal TextButton::Spacing() {
  return layout_->Spacing();
}

void TextButton::SetSpacing(qreal spacing) {
  layout_->SetSpacing(spacing);
}

QPixmap* TextButton::Icon() {
  return icon_->Pixmap();
}

void TextButton::SetIcon(QPixmap* icon) {
  icon_->SetPixmap(icon);
  layout_->RecalculatePositions();
}
