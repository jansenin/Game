#include "Controller/controller.h"

#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QApplication>
#include <QTimer>

#include "GameObjects/Entities/Mobs/test_mob.h"
#include "GameObjects/Entities/Towers/TowerSlots/test_tower_slot.h"
#include "constants.h"

Controller* Controller::instance;

Controller::Controller() :
  scene_(new GameScene(Scene::kRect)),
  view_(new GameView(scene_)),
  tick_timer_(new QTimer(this)),
  level_(new Level(1)),
  base_hp_(20),
  damage_per_current_tick_(0) {
  SetupScene();
  LaunchTickTimer();

  connect(this, &Controller::GameOver, [this]() {
    scene_->addItem(new TestMob({100, 100}));
    // it's needed, but it also blocks close button
    // view_->setInteractive(false);
    tick_timer_->stop();
  });
}

GameView* Controller::GetView() const {
  return view_;
}

GameScene* Controller::GetScene() const {
  return scene_;
}

Level* Controller::GetLevel() const {
  return level_;
}

void Controller::SetupScene() {
  {  // temporary code
    QPushButton* close_button = new QPushButton();
    QGraphicsProxyWidget* close_button_proxy = scene_->addWidget(close_button);
    close_button_proxy->setGeometry(QRectF(
        scene_->sceneRect().topRight() - VectorF{100, 0},
        scene_->sceneRect().topRight() + VectorF{0, 100}));

    close_button->setText("Close");
    QObject::connect(close_button, &QPushButton::clicked, &QApplication::exit);
  }  // temporary code end

  level_->AddObjectsToScene(scene_);
}

void Controller::LaunchTickTimer() {
  tick_timer_->setInterval(10);
  tick_timer_->start();
  connect(tick_timer_, &QTimer::timeout, this, &Controller::TickAllTickables);
}

Controller* Controller::Instance() {
  if (instance == nullptr) {
    instance = new Controller();
  }
  return instance;
}

void Controller::TickAllTickables() {
  // because we don't want to emit GameOver more than one time
  assert(base_hp_ > 0);

  Time delta = Time(10);
  for (QGraphicsItem* graphics_item : scene_->items()) {
    if (Tickable* tickable = dynamic_cast<Tickable*>(graphics_item)) {
      // TODO(jansenin): make time dependency(it
      //  could have been more than 1000/30 ms)
      tickable->Tick(delta);
    }
  }
  level_->Tick(delta);

  base_hp_ -= damage_per_current_tick_;
  damage_per_current_tick_ = 0;
  if (base_hp_ <= 0) {
    base_hp_ = 0;
    emit GameOver();
  }
}

void Controller::DealDamageToBase(int damage) {
  damage_per_current_tick_ += damage;
}
