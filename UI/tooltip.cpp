#include "tooltip.h"

#include <QTextDocument>
#include <QPainter>

#include "Utilities/Resources/pixmap_loader.h"
#include "Utilities/vector_f.h"
#include "constants.h"

Tooltip::Tooltip(QGraphicsItem* parent)
  : TexturedBox(), text_item_(new QGraphicsTextItem()) {
  textured_box_pixmaps_ = PixmapLoader::kDefaultTexturedBoxPixmaps;
  SetWrappingItem(text_item_);
  setZValue(UI::kDefaultZValue);
}

Tooltip::Tooltip(QString text, QGraphicsItem* parent)
  : Tooltip(parent) {
  setPlainText(text);
}

void Tooltip::setPlainText(const QString& text) {
  qreal initial_text_width = text_item_->document()->size().width();
  text_item_->setPlainText(text);
  qreal current_text_width = text_item_->document()->size().width();

  moveBy(initial_text_width / 2, 0);
  moveBy(- current_text_width / 2, 0);

  prepareGeometryChange();
}

void Tooltip::setHtml(const QString& text) {
  qreal initial_text_width = text_item_->document()->size().width();
  text_item_->setHtml(text);
  qreal current_text_width = text_item_->document()->size().width();

  moveBy(initial_text_width / 2, 0);
  moveBy(- current_text_width / 2, 0);

  prepareGeometryChange();
}

void Tooltip::setPos(qreal ax, qreal ay) {
  QGraphicsItem::setPos(ax, ay);
  qreal text_width = boundingRect().width();
  moveBy(- text_width / 2, 0);
}

void Tooltip::setPos(const QPointF& pos) {
  setPos(pos.x(), pos.y());
}
