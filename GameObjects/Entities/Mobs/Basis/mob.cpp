#include "mob.h"

#include <vector>
#include "Controller/controller.h"
#include "Utilities/randomaizer.h"
#include "GameObjects/Interface/coin.h"
#include "Utilities/Resources/pixmap_loader.h"
#include "constants.h"

Mob::Mob(const VectorF& coordinates,
         Animation* animation,
         int health,
         int damage_to_base,
         qreal speed)
    : Entity(coordinates, animation, health),
      speed_(speed),
      growing_time_(Time(0)),
      growing_step_(0),
      dealed_damage_to_base_(false),
      damage_to_base_(damage_to_base) {}

Mob::Mob(const VectorF& coordinates,
         QPixmap* pixmap,
         int health,
         int damage_to_base,
         qreal speed)
         : Entity(coordinates, new Animation(pixmap), health),
             speed_(speed),
             growing_time_(Time(0)),
             growing_step_(0),
             dealed_damage_to_base_(false),
             damage_to_base_(damage_to_base) {}

qreal Mob::GetSpeed() const {
  return speed_;
}

void Mob::SetSpeed(qreal speed) {
  speed_ = speed;
}

void Mob::SetRoute(Route* route) {
  if (route == nullptr && route_ != nullptr) {
    route_->RemoveEntity(this);
  }
  route_ = route;
  if (route_ != nullptr) {
    route_->AddEntity(this);
  }
}

void Mob::MoveToRouteStart() {
  Entity::setPos(route_->GetStart());
}

void Mob::Tick(Time delta) {
  Entity::Tick(delta);

  if (route_ != nullptr) {
    if (route_->isEnd(this) && !dealed_damage_to_base_) {
      dealed_damage_to_base_ = true;
      Controller::Instance()->DealDamageToBase(damage_to_base_);
    }
  }
  if (growing_time_.ms() > 0) {
    setScale(scale() + growing_step_ * delta.ms());
    growing_time_ -= delta;
  }
  update();
}

Mob::~Mob() {
  if (route_ != nullptr) {
    route_->RemoveEntity(this);
  }
  if (rand() % Entities::kCoinAppearChance == 1) {  //NOLINT
    scene()->addItem(new Coin(VectorF(pos().x(), pos().y()),
                              PixmapLoader::Pixmaps::kCoinAnimations));
  }
}

QRectF Mob::boundingRect() const {
  QRectF result = Entity::boundingRect();
  result.translate(0, -result.height() / 2);
  return result;
}

void Mob::TimeToGrow() {
  int grow_chance = std::abs(Randomaizer::Random()) % 6;
  qreal grow_index = 0;
  switch (grow_chance) {
    case 0 : {
      grow_index = 1.0;
      break;
    }
    case 1 : {
      grow_index = 1.0;
      break;
    }
    case 2 : {
      grow_index = 1.0;
      break;
    }
    case 3 : {
      grow_index = 1.1;
      break;
    }
    case 4 : {
      grow_index = 1.3;
      break;
    }
    case 5 : {
      grow_index = 1.5;
      break;
    }
  }
  health_ = static_cast<int>(grow_index * static_cast<qreal>(health_));
  growing_step_ = (grow_index * scale() - scale()) /
      Entities::kGrowingSpeed.ms();
  growing_time_ = Entities::kGrowingSpeed;
}
