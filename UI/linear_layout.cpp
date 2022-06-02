#include "linear_layout.h"

#include <algorithm>

#include <QPainter>

#include "constants.h"

LinearLayout::LinearLayout(QGraphicsItem* parent)
  : QGraphicsObject(parent),
    items_(std::vector<QGraphicsObject*>()),
    type_(Type::Horizontal) {
  setZValue(UI::kDefaultZValue);
}

QRectF LinearLayout::boundingRect() const {
  return childrenBoundingRect();
}

void LinearLayout::OnItemDestroyed(QObject* item) {
  QGraphicsObject* object = dynamic_cast<QGraphicsObject*>(item);
  assert(object != nullptr);
  RemoveItem(object);
}

void LinearLayout::AddItem(QGraphicsObject* item) {
  prepareGeometryChange();
  items_.push_back(item);
  item->setParentItem(this);
  ConnectItem(item);
  RecalculatePositions();
}

void LinearLayout::RemoveItem(QGraphicsObject* item) {
  auto i = std::find(items_.begin(), items_.end(), item);
  if (i == items_.end()) {
    qDebug() << "LinearLayout.RemoveItem: there is no item in items_";
  }
  items_.erase(i);

  prepareGeometryChange();
  item->setParentItem(nullptr);
  DisconnectItem(item);
  RecalculatePositions();
}

bool LinearLayout::HasItem(QGraphicsObject* item) {
  int count = std::count(items_.begin(), items_.end(), item);
  assert(count <= 1);
  return count == 1;
}

// wasn't tested properly(works on text buttons and should work on
// elements, that satisfy:
// boundingBox().x() == boundingBox().y() == 0)
void LinearLayout::RecalculatePositions() {
  if (type_ == Type::Horizontal) {
    qreal max_height = 0;
    for (int i = 0 ; i < items_.size() ; ++i) {
      max_height = std::max(max_height, items_.at(i)->boundingRect().height());
    }
    qreal x = 0;
    for (int i = 0 ; i < items_.size() ; ++i) {
      QGraphicsItem* item = items_.at(i);
      qreal item_width = item->boundingRect().width() * item->scale();
      qreal item_height = item->boundingRect().height() * item->scale();
      item->setPos(
          x,
          max_height / 2 - item_height / 2);
      x += item_width + spacing_;
    }
  } else if (type_ == Type::Vertical) {
    qreal max_width = 0;
    for (int i = 0 ; i < items_.size() ; ++i) {
      max_width = std::max(
          max_width,
          items_.at(i)->boundingRect().width() * items_.at(i)->scale());
    }
    qreal y = 0;
    for (int i = 0 ; i < items_.size() ; ++i) {
      QGraphicsItem* item = items_.at(i);
      qreal item_width = item->boundingRect().width() * item->scale();
      qreal item_height = item->boundingRect().height() * item->scale();
      item->setPos(
          max_width / 2 - item_width / 2,
          y);
      y += item_height + spacing_;
    }
  } else {
    assert(false);
  }
}

qreal LinearLayout::Spacing() const {
  return spacing_;
}

void LinearLayout::SetSpacing(qreal spacing) {
  if (spacing_ != spacing) {
    spacing_ = spacing;
    prepareGeometryChange();
    RecalculatePositions();
  }
}

void LinearLayout::paint(QPainter* painter,
                         const QStyleOptionGraphicsItem* option,
                         QWidget* widget) {
  if (kDebugMode) {
    painter->setPen(QPen(Qt::green));
    painter->drawRect(boundingRect());
  }
}

void LinearLayout::ConnectItem(QGraphicsObject* item) {
  connect(
      item,
      &QGraphicsObject::heightChanged,
      this,
      &LinearLayout::RecalculatePositions);
  connect(
      item,
      &QGraphicsObject::widthChanged,
      this,
      &LinearLayout::RecalculatePositions);
  connect(
      item,
      &QGraphicsObject::scaleChanged,
      this,
      &LinearLayout::RecalculatePositions);
  connect(
      item,
      &QGraphicsObject::destroyed,
      this,
      &LinearLayout::OnItemDestroyed);
}

void LinearLayout::DisconnectItem(QGraphicsObject* item) {
  disconnect(
      item,
      &QGraphicsObject::heightChanged,
      this,
      &LinearLayout::RecalculatePositions);
  disconnect(
      item,
      &QGraphicsObject::widthChanged,
      this,
      &LinearLayout::RecalculatePositions);
  disconnect(
      item,
      &QGraphicsObject::scaleChanged,
      this,
      &LinearLayout::RecalculatePositions);
  disconnect(
      item,
      &QGraphicsObject::destroyed,
      this,
      &LinearLayout::OnItemDestroyed);
}

enum LinearLayout::Type LinearLayout::Type() const {
  return type_;
}

void LinearLayout::SetType(enum LinearLayout::Type type) {
  if (type_ != type) {
    type_ = type;
    prepareGeometryChange();
    RecalculatePositions();
  }
}
