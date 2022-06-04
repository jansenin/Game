#include "resource_displayer.h"

#include <QTextDocument>

#include "padding_box.h"
#include "Utilities/vector_f.h"
#include "constants.h"

ResourcesDisplayer::ResourcesDisplayer() {
  resources_layout_ = new LinearLayout();

      textured_box_pixmaps_ = PixmapLoader::kDefaultTexturedBoxPixmaps;
  SetWrappingItem(resources_layout_);

      LinearLayout* money_layout = new LinearLayout();
  LinearLayout* hp_layout = new LinearLayout();

      money_icon_ = new PixmapObject(PixmapLoader::Pixmaps::kMoneyIcon);
  hp_icon_ = new PixmapObject(PixmapLoader::Pixmaps::kHealthStatus1);

      money_item_ = new QGraphicsTextItem();
  hp_item_ = new QGraphicsTextItem();
  money_item_->setPlainText("money");
  hp_item_->setPlainText("hp");
  QFont money_font = money_item_->font();
  QFont hp_font = hp_item_->font();
  money_font.setPixelSize(20);
  hp_font.setPixelSize(20);
  money_item_->setFont(money_font);
  hp_item_->setFont(hp_font);

      money_layout->AddItem(new PaddingBox(money_icon_, 10));
  money_layout->AddItem(new PaddingBox(money_item_, 10));

      hp_layout->AddItem(hp_icon_);
  hp_layout->AddItem(hp_item_);

      resources_layout_->AddItem(money_layout);
  resources_layout_->AddItem(hp_layout);

      resources_layout_->RecalculatePositions();
}

void ResourcesDisplayer::SetMoney(int money) {
  money_item_->setPlainText("Money: " + QString::number(money));
  resources_layout_->RecalculatePositions();
  RecalculateInnerPos();
}

void ResourcesDisplayer::SetHp(int hp) {
  hp_item_->setPlainText("Hp: " + QString::number(hp));
  if (hp < 5 / 2) { //  half hp
      hp_icon_->SetPixmap(PixmapLoader::Pixmaps::kHealthStatus2);
    }
  resources_layout_->RecalculatePositions();
  RecalculateInnerPos();
}
