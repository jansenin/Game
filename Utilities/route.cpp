#include "route.h"
#include <cmath>

qreal kEps = 2;

bool Route::isEnd() {
  return index_ == points_.size() - 1;
}

void Route::Move(qreal distance) {
  VectorF start(points_[index_]);
  VectorF end(points_[index_ + 1]);
  VectorF direction = end - start;
  entity_->MoveBy((direction.normalized() * distance));
  ChooseIndex();
}

void Route::ChooseIndex() {
  qreal square_distance = pow((points_[index_ + 1].x() - entity_->pos().x()), 2) +
      pow((points_[index_ + 1].y() - entity_->pos().y()), 2);
  if (square_distance <= kEps * kEps) {
    ++index_;
  }
}

Route::Route(Route&& route) : points_(route.points_), index_(route.index_), entity_(route.entity_) {
  route.entity_ = nullptr;
}
