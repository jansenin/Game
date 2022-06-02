#include "Controller/controller.h"

#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QApplication>
#include <QTimer>
#include <QTextDocument>

#include "GameObjects/Entities/Mobs/test_mob.h"
#include "GameObjects/Entities/Towers/TowerSlots/test_tower_slot.h"
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
    LinearMenu* main_menu = new LinearMenu();
    main_menu->SetTexturedBoxPixmaps(PixmapLoader::kMenu2TexturedBoxPixmaps);
    main_menu->SetSpacing(30);

    TextButton* test_button = new TextButton();
    test_button->SetText("Test button");
    QFont button_font = test_button->GetTextDocument()->defaultFont();
    button_font.setPixelSize(30);
    test_button->GetTextDocument()->setDefaultFont(button_font);

    connect(test_button, &TextButton::Clicked,
            [this, test_button, main_menu](){
      static int i = 0;
      i++;
      scene_->addItem(new TestMob({200.0 + 10 * i, 200}));
      test_button->setScale(1.5);
      test_button->SetIcon(PixmapLoader::Pixmaps::FireTotem::kIdle.at(0));
      test_button->SetSpacing(test_button->Spacing() + 5);
      test_button->SetPadding(test_button->Padding() + 3);
      main_menu->setPos(
          scene_->sceneRect().topRight() -
          main_menu->boundingRect().topRight() +
          QPointF{-5, 5});
      main_menu->RecalculatePositions();
    });

    LinearLayout* layout = new LinearLayout();
    layout->SetSpacing(10);
    layout->AddItem(new TextButton({0, 0}, "Menu button 1"));
    layout->AddItem(new TextButton({0, 0}, "Menu button 2"));
    TextButton* close_button = new TextButton({0, 0}, "Quit");
    layout->AddItem(close_button);
    connect(close_button, &TextButton::Clicked, [](){ QApplication::exit(); });

    LinearMenu* menu = new LinearMenu();
    menu->AddItem(new PaddingBox(new TextButton({0, 0}, "Menu button 1"), 10));
    menu->AddItem(new PaddingBox(new TextButton({0, 0}, "Menu button 2"), 10));
    menu->SetSpacing(5);
    menu->SetPadding(20);
    menu->setScale(1.2);
    menu->SetTexturedBoxPixmaps(PixmapLoader::kMenuTexturedBoxPixmaps);
    menu->SetType(LinearLayout::Type::Vertical);

    main_menu->AddItem(layout);
    main_menu->AddItem(menu);
    main_menu->AddItem(test_button);
    main_menu->SetType(LinearLayout::Type::Vertical);

    {
      LinearLayout* test_hor_layout = new LinearLayout();
      test_hor_layout->AddItem(new TextButton({0, 0}, "test 1"));
      test_hor_layout->AddItem(new TextButton({0, 0}, "test 2"));
      test_hor_layout->SetType(LinearLayout::Type::Horizontal);
      test_hor_layout->SetSpacing(20);
      test_hor_layout->setPos(200, 200);

      LinearLayout* test_ver_layout = new LinearLayout();
      test_ver_layout->AddItem(new TextButton({0, 0}, "test 1"));
      test_ver_layout->AddItem(new TextButton({0, 0}, "test 2"));
      test_ver_layout->SetType(LinearLayout::Type::Vertical);
      test_ver_layout->SetSpacing(20);
      test_ver_layout->setPos(200, 300);

      scene_->addItem(test_hor_layout);
      scene_->addItem(test_ver_layout);
    }
    {
      LinearMenu* test_hor_menu = new LinearMenu();
      test_hor_menu->AddItem(new TextButton({0, 0}, "test 1"));
      test_hor_menu->AddItem(new TextButton({0, 0}, "test 2"));
      test_hor_menu->SetType(LinearLayout::Type::Horizontal);
      test_hor_menu->SetTexturedBoxPixmaps(
          PixmapLoader::kMenu2TexturedBoxPixmaps);
      test_hor_menu->SetPadding(50);
      test_hor_menu->SetSpacing(20);
      test_hor_menu->setPos(-200, 100);

      LinearMenu* test_ver_menu = new LinearMenu();
      test_ver_menu->AddItem(new TextButton({0, 0}, "test 1"));
      test_ver_menu->AddItem(new TextButton({0, 0}, "test 2"));
      test_ver_menu->SetType(LinearLayout::Type::Vertical);
      test_ver_menu->SetTexturedBoxPixmaps(
          PixmapLoader::kMenu2TexturedBoxPixmaps);
      test_ver_menu->SetPadding(50);
      test_ver_menu->SetSpacing(20);
      test_ver_menu->setPos(-600, 100);

      scene_->addItem(test_hor_menu);
      scene_->addItem(test_ver_menu);
    }
    {
      TextButton* text_button = new TextButton({0, 0}, "Button");
      PaddingBox* padding_box = new PaddingBox(text_button, 20);
      padding_box->setPos(0, 0);

      scene_->addItem(padding_box);
    }
    {
      TextButton* text_button = new TextButton({-300, 0}, "Button");

      connect(text_button, &TextButton::Clicked, [text_button]() {
        text_button->SetText("Button Button");
      });

      scene_->addItem(text_button);
    }

    scene_->addItem(main_menu);
    main_menu->setPos(
        scene_->sceneRect().topRight() -
        main_menu->boundingRect().topRight() +
        QPointF{-5, 5});
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
