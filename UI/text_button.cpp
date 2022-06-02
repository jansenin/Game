#include "text_button.h"

#include <QTextDocument>
#include <QCursor>

#include "Utilities/Resources/pixmap_loader.h"
#include "constants.h"

TextButton::TextButton(VectorF position, const QString& text)
  : TexturedBox() {
  textured_box_pixmaps_ = PixmapLoader::kButtonTexturedBoxPixmaps;
  text_item_ = new QGraphicsTextItem();
  padding_box = new PaddingBox(text_item_, 0);
  text_item_->setDefaultTextColor(UI::kButtonDefaultTextColor);
  SetWrappingItem(padding_box);
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
  return padding_box->Padding();
}

void TextButton::SetPadding(qreal padding) {
  padding_box->SetPadding(padding);
}
