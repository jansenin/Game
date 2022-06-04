#include "explosion.h"

#include "GameObjects/Entities/Mobs/Basis/mob.h"
#include "Utilities/Resources/pixmap_loader.h"
#include "constants.h"

Explosion::Explosion(const VectorF& coordinates, qreal radius, Damage damage)
    : radius_(radius),
    damage_(damage),
    animation_(new Animation(
        PixmapLoader::Pixmaps::Explosion::kExplosion,
        Explosions::kTimeBetweenFrames)) {
  setPos(coordinates);
  setZValue(Explosions::kZValue);
}

QRectF Explosion::boundingRect() const {
  QRectF result = animation_->Frame()->rect();
  qreal scale = result.width() / (radius_ * 2);
  result = QRectF(0, 0, result.width() / scale, result.height() / scale);
  result.translate(-result.width() / 2, -result.height() / 2);
  return result;
}

void Explosion::paint(QPainter* painter,
                      const QStyleOptionGraphicsItem* option,
                      QWidget* widget) {
  QRectF rect = boundingRect();
  QPixmap* pixmap = animation_->Frame();
  painter->drawPixmap(rect, *pixmap, pixmap->rect());
}

void Explosion::Tick(Time delta) {
  animation_->Tick(delta);

  if (animation_->WasEndedDuringPreviousUpdate()) {
    deleteLater();
  }
}

void Explosion::DamageMobs() {
  for (auto mob : scene()->Mobs()) {
    if (VectorF(scenePos() - mob->scenePos()).length() < radius_) {
      mob->ApplyDamage(damage_);
    }
  }
}

QVariant Explosion::itemChange(QGraphicsItem::GraphicsItemChange change,
                             const QVariant& value) {
  if (change == GraphicsItemChange::ItemSceneHasChanged) {
    DamageMobs();
  }
  return QGraphicsItem::itemChange(change, value);
}

Explosion::~Explosion() {
  delete animation_;
}
