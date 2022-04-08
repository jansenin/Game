#include "Controller/controller.h"

#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QApplication>
#include <QTimer>

#include "../Model/BasicObjects/Entities/Mobs/mob_test.h"
#include "Model/BasicObjects/Entities/Towers/TowerSlots/test_tower_slot.h"

Controller::Controller() :
  scene_(new QGraphicsScene(-1920.0/2, -1080.0/2, 1920, 1080)),
  view_(new GameView(scene_)) {
  QPushButton* close_button = new QPushButton();
  QGraphicsProxyWidget* close_button_proxy = scene_->addWidget(close_button);
  close_button_proxy->setGeometry(QRectF(
      scene_->sceneRect().topRight() - QPointF{100, 0},
      scene_->sceneRect().topRight() + QPointF{0, 100}));

  close_button->setText("Close");
  QObject::connect(close_button, &QPushButton::clicked, &QApplication::exit);

  view_->scale(1/view_->devicePixelRatio(), 1/view_->devicePixelRatio());
  view_->setInteractive(true);
  view_->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
  view_->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
  view_->setRenderHint(QPainter::RenderHint::Antialiasing);
  view_->setOptimizationFlag(
      QGraphicsView::OptimizationFlag::DontSavePainterState);
  view_->setViewportUpdateMode(
      QGraphicsView::ViewportUpdateMode::FullViewportUpdate);

  entity = new MobTest();
  scene_->addItem(entity);
  scene_->setFocusItem(entity);

  TestTowerSlot* test_tower_slot = new TestTowerSlot(QPointF{400, 400});
  scene_->addItem(test_tower_slot);

  QRectF sceneRect = scene_->sceneRect();
  qreal x = sceneRect.x();
  qreal y = sceneRect.y();
  qreal width = sceneRect.width();
  qreal height = sceneRect.height();

  // if it will be just sceneRect, the user will be able to scroll the view
  // with arrow keys(it's default behaviour, I don't know how to disable it)
  view_->setSceneRect(QRectF(x + 1, y + 1, width - 2, height - 2));

  scene_->addLine(
      x + width / 2,
      y,
      x + width / 2,
      y + height,
      QPen(Qt::blue));

  scene_->addLine(
      x,
      y + height / 2,
      x + width,
      y + height / 2,
      QPen(Qt::blue));

  view_->centerOn(0, 0);

  // QTimer* timer = new QTimer(this);
  // timer->setInterval(1000);
  // timer->start();
  // connect(timer, &QTimer::timeout, this, [&](){entity->setPos(
  // entity->pos() + QPointF{100, 100});});

  QTimer* timer = new QTimer(this);
  timer->setInterval(1000 / 30);
  timer->start();
  connect(timer, &QTimer::timeout, this, [&](){
    for (QGraphicsItem* graphics_item : scene_->items()) {
      if (Tickable* tickable = dynamic_cast<Tickable*>(graphics_item)) {
        // TODO(jansenin): make time dependency(it
        //  could have been more than 1000/30 ms)
        tickable->Tick(Time(1000 / 30));
      }
  }});
}

GameView* Controller::GetView() const {
  return view_;
}
