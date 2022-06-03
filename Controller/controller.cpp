#include "Controller/controller.h"

#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QApplication>
#include <QTimer>
#include <QTextDocument>

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
  base_hp_(20),
  damage_per_current_tick_(0) {
  SetupScene();
  LaunchTickTimer();

  connect(this, &Controller::GameOver, [this]() {
    scene_->addItem(new Dwarf({100, 100}));
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
  level_->Tick(delta);

  base_hp_ -= damage_per_current_tick_;
  damage_per_current_tick_ = 0;
  if (base_hp_ <= 0) {
    base_hp_ = 0;
    emit GameOver();
  }
}

void Controller::DealDamageToBase(int damage) {
  // damage_per_current_tick_ += damage;
}
