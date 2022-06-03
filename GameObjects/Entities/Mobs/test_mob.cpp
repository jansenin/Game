#include "test_mob.h"

#include "Utilities/Resources/pixmap_loader.h"
#include "constants.h"

void TestMob::Tick(Time delta) {
  Mob::Tick(delta);
  if (is_creating_ && animation_->WasEndedDuringPreviousUpdate()) {
    is_creating_ = false;
    animation_ = idle_animation_;
  }
  if (is_destroying_ && animation_->WasEndedDuringPreviousUpdate()) {
    animation_->SetIndex(animation_->FrameCount() - 1);
    deleteLater();
  }
  if (route_ != nullptr && !is_destroying_) {
    if (!is_creating_ && !route_->isEnd(this)) {
      route_->Move(this, speed_ * delta.seconds());
    }
  }
  test_tooltip->setPos(scenePos() + QPointF(0, 80));
}

void TestMob::keyPressEvent(QKeyEvent* event) {
  if (health_ == 0) return;
  QPointF velocity_vector = mapToParent(pos() +
      VectorF{0, -Entities::TestMob::kActiveMoveSpeed}) - mapToParent(pos());
  if (event->key() == Qt::Key::Key_Left) {
    setRotation(rotation() - Entities::TestMob::kRotationSpeed);
  } else if (event->key() == Qt::Key::Key_Right) {
    setRotation(rotation() + Entities::TestMob::kRotationSpeed);
  } else if (event->key() == Qt::Key::Key_Up) {
    setPos(pos() + velocity_vector);
  } else if (event->key() == Qt::Key::Key_Down) {
    setPos(pos() - velocity_vector);
  } else if (event->key() == Qt::Key::Key_Space && !is_destroying_) {
    health_ = 0;
    is_destroying_ = true;
    disappearing_animation_->Reset();
    animation_ = disappearing_animation_;
  }
}

void TestMob::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  scene()->addItem(new TestMob(pos() + VectorF{100, 100}));
  static int tooltip_number = 0;
  tooltip_number++;
  test_tooltip->setHtml(
      "Test tooltip line 1 <br>"
      "Test   tooltip line 2 <br>"
      "Test very long tooltip line with line break in the end" +
      QString::number(tooltip_number));
}

TestMob::TestMob(const VectorF& coordinates)
    : Mob(
      coordinates,
      // TODO(jansenin): Было бы лучше инициализировать анимации отдельно
      //  от моба
      new Animation(PixmapLoader::Pixmaps::FireTotem::kAppearing, 50_ms),
      Entities::TestMob::kHealth,
      1,
      300),
    is_destroying_(false),
    idle_animation_(
        new Animation(PixmapLoader::Pixmaps::FireTotem::kIdle, 50_ms)),
    disappearing_animation_(
        new Animation(PixmapLoader::Pixmaps::FireTotem::kDisappear, 50_ms)),
    appearing_animation_(animation_),
    is_creating_(true),
    test_tooltip(new Tooltip()) {
  setFlag(QGraphicsItem::ItemIsFocusable, true);
  setAcceptHoverEvents(true);
  setScale(1.4);

  test_tooltip->setPos(scenePos() + QPointF(0, 80));
  test_tooltip->setVisible(false);
  test_tooltip->setHtml(
      "Test tooltip line 1 <br>"
      "Test   tooltip line 2 <br>"
      "Test very long tooltip line with line break in the end <br>");
}

TestMob::~TestMob() {
  delete idle_animation_;
  delete disappearing_animation_;
  delete appearing_animation_;
  test_tooltip->deleteLater();
}

void TestMob::ApplyDamage(Damage damage) {
  Damageable::ApplyDamage(damage);

  if (health_ <= 0 && !is_destroying_) {
    disappearing_animation_->Reset();
    is_destroying_ = true;
    animation_ = disappearing_animation_;
  }
}

void TestMob::SetRoute(Route* route) {
  Mob::SetRoute(route);
  MoveToRouteStart();
}

void TestMob::hoverEnterEvent(QGraphicsSceneHoverEvent* event) {
  test_tooltip->setVisible(true);
}

void TestMob::hoverLeaveEvent(QGraphicsSceneHoverEvent* event) {
  test_tooltip->setVisible(false);
}

QVariant TestMob::itemChange(QGraphicsItem::GraphicsItemChange change,
                             const QVariant& value) {
  if (change == GraphicsItemChange::ItemSceneHasChanged) {
    scene()->addItem(test_tooltip);
  }
  return QGraphicsItem::itemChange(change, value);
}
