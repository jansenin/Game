#include "Controller/controller.h"

#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QApplication>
#include <QTimer>

#include "GameObjects/BasicObjects/Entities/Mobs/test_mob.h"
#include "GameObjects/BasicObjects/Entities/Towers/TowerSlots/test_tower_slot.h"
#include "constants.h"

Controller* Controller::instance;

Controller::Controller() :
  scene_(new QGraphicsScene(kSceneRect)),
  view_(new GameView(scene_)),
  tick_timer_(new QTimer(this)) {
  SetupScene();
  LaunchTickTimer();
}

GameView* Controller::GetView() const {
  return view_;
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

    Entity* entity = new TestMob();
    scene_->addItem(entity);
    scene_->setFocusItem(entity);

    TestTowerSlot* test_tower_slot = new TestTowerSlot(VectorF{400, 400});
    scene_->addItem(test_tower_slot);

    QRectF sceneRect = scene_->sceneRect();
    qreal x = sceneRect.x();
    qreal y = sceneRect.y();
    qreal width = sceneRect.width();
    qreal height = sceneRect.height();

    scene_->addLine(
        x + width / 2,
        y,
        x + width / 2,
        y + height,
        QPen(Qt::blue));

    scene_->addLine(
        x,
        y + 1,
        x + width,
        y + 1,
        QPen(Qt::blue));

    scene_->addLine(
        x,
        y + height / 2,
        x + width,
        y + height / 2,
        QPen(Qt::blue));
  }  // temporary code end
}

void Controller::LaunchTickTimer() {
  tick_timer_->setInterval(1000 / 30);
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
  for (QGraphicsItem* graphics_item : scene_->items()) {
    if (Tickable* tickable = dynamic_cast<Tickable*>(graphics_item)) {
      // TODO(jansenin): make time dependency(it
      //  could have been more than 1000/30 ms)
      tickable->Tick(Time(1000 / 30));
    }
  }
}
