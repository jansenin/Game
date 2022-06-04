#include "Controller/controller.h"

#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QApplication>
#include <QTimer>
#include <QTextDocument>
#include <iostream>

#include "GameObjects/Entities/Mobs/Basis/mob.h"
#include "GameObjects/Entities/Mobs/skeleton.h"
#include "GameObjects/Entities/Mobs/hedgehog.h"
#include "GameObjects/Entities/Mobs/cobra.h"
#include "GameObjects/Entities/Mobs/dwarf.h"
#include "GameObjects/explosion.h"
#include "constants.h"
#include "UI/button.h"
#include "UI/linear_menu.h"
#include "UI/padding_box.h"
#include "Utilities/Resources/pixmap_loader.h"

Controller* Controller::instance;

Controller::Controller() :
  scene_(new GameScene(Scene::kRect)),
  view_(new GameView(scene_)),
  tick_timer_(new QTimer(this)),
  level_(new Level(1)),
  base_hp_(5),
  balance_(kStartBalance),
  damage_per_current_tick_(0),
  resource_displayer_(nullptr) {
  SetupScene();
  SetupInterface();
  LaunchTickTimer();

  connect(this, &Controller::GameOver, [this]() {
    scene_->addItem(new Dwarf({100, 100}));
    // it's needed, but it also blocks close button
    // view_->setInteractive(false);
    tick_timer_->stop();
    QGraphicsTextItem* game_over_item = new QGraphicsTextItem();
    game_over_item->setPlainText("Game Over");
    QFont font = game_over_item->font();
    font.setPixelSize(150);
    game_over_item->setFont(font);
    game_over_item->setPos(
        -game_over_item->boundingRect().width() / 2,
    -game_over_item->boundingRect().height() / 2);
    game_over_item->setZValue(1000000);
    scene_->addItem(game_over_item);
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
    TextButton* quit_button = new TextButton({0, 0}, "Quit");
    auto quit_button_font = quit_button->GetTextDocument()->defaultFont();
    quit_button_font.setPixelSize(20);
    quit_button->GetTextDocument()->setDefaultFont(quit_button_font);
    quit_button->setPos(
        scene_->sceneRect().topRight()
            - quit_button->boundingRect().topRight()
            - VectorF(5, -5));
    connect(quit_button, &TextButton::Clicked, [](){ QApplication::exit(); });
    scene_->addItem(quit_button);
  }  // temporary code end

  level_->AddObjectsToScene(scene_);
}

void Controller::LaunchTickTimer() {
  tick_timer_->setInterval(1000 / kFPS);
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

  Time delta = Time(1000 / kFPS);
  for (QGraphicsItem* graphics_item : scene_->items()) {
    if (Tickable* tickable = dynamic_cast<Tickable*>(graphics_item)) {
      // TODO(jansenin): make time dependency(it
      //  could have been more than 1000/30 ms)
      tickable->Tick(delta);
    }
  }
  if (level_->IsTimeForGrow()) {
  for (QGraphicsItem* graphics_item : scene_->items()) {
      if (Mob* mob = dynamic_cast<Mob*>(graphics_item)) {
        mob->TimeToGrow();
      }
    }
  }
  level_->Tick(delta);

  base_hp_ -= damage_per_current_tick_;
  resource_displayer_->SetHp(base_hp_);
  damage_per_current_tick_ = 0;
  if (base_hp_ <= 0) {
    base_hp_ = 0;
    emit GameOver();
  }
}

void Controller::DealDamageToBase(int damage) {
  damage_per_current_tick_ += damage;
}

void Controller::SetupInterface() {
  resource_displayer_ = new ResourcesDisplayer();
  resource_displayer_->SetMoney(balance_);
  resource_displayer_->SetHp(base_hp_);
  resource_displayer_->SetOriginPoint(TexturedBox::OriginPoint::kTopLeft);
  resource_displayer_->setPos(scene_->sceneRect().topLeft() + VectorF(5, 5));
  scene_->addItem(resource_displayer_);
}

void Controller::AddMoney(int money) {
  balance_ += money;
  resource_displayer_->SetMoney(balance_);
}

void Controller::LoseMoney(int money) {
    balance_ -= money;
    resource_displayer_->SetMoney(balance_);
}

int Controller::GetBalance() {
  return balance_;
}

bool Controller::HaveEnoughMoney(int money) {
  if (money > balance_) {
    return false;
  }
  return true;
}

