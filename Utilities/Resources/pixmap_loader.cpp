#include <utility>

#include "constants.h"
#include "pixmap_loader.h"

using P = PixmapLoader::Pixmaps;

QPixmap* P::kBackground;
QPixmap* P::kTestBullet;
QPixmap* P::kTestMob;
QPixmap* P::kTestTower;
QPixmap* P::kTestTowerGun;
QPixmap* P::kTestTowerSlot;
std::vector<QPixmap*> P::kLevelMaps;

QPixmap* P::FireTotem::kAnimations;
std::vector<QPixmap*> P::FireTotem::kIdle;
std::vector<QPixmap*> P::FireTotem::kDisappear;
std::vector<QPixmap*> P::FireTotem::kAppearing;

// -----------------------------------------------------------------------------

QPixmap* P::UI::DefaultTexturedBox::kTopLeftCorner;
QPixmap* P::UI::DefaultTexturedBox::kTopRightCorner;
QPixmap* P::UI::DefaultTexturedBox::kBottomLeftCorner;
QPixmap* P::UI::DefaultTexturedBox::kBottomRightCorner;

QPixmap* P::UI::DefaultTexturedBox::kLeftSide;
QPixmap* P::UI::DefaultTexturedBox::kRightSide;
QPixmap* P::UI::DefaultTexturedBox::kTopSide;
QPixmap* P::UI::DefaultTexturedBox::kBottomSide;

QPixmap* P::UI::DefaultTexturedBox::kInside;

TexturedBoxPixmaps PixmapLoader::kDefaultTexturedBoxPixmaps;

void PixmapLoader::LoadPixmaps() {
  P::kBackground = new QPixmap(":images/background.png");
  P::kTestBullet = new QPixmap(":images/test_bullet.png");
  P::kTestMob = new QPixmap(":images/test_mob.png");
  P::kTestTower = new QPixmap(":images/test_tower.png");
  P::kTestTowerGun = new QPixmap(":images/test_tower_gun.png");
  P::kTestTowerSlot = new QPixmap(":images/test_tower_slot.png");
  for (int i = 1; i <= LevelData::kLevelsCount; ++i) {
    P::kLevelMaps.push_back(new QPixmap(":Levels/Level" +
    QString::fromStdString(std::to_string(i)) + "/map.png"));
  }

  LoadFireTotemAnimations();
  LoadUI();
}

std::vector<QPixmap*> PixmapLoader::CreateHorizontalFramesVector(
    QPixmap* source,
    int frame_width,
    int frame_height,
    int frames_count,
    int start_x,
    int y) {
  std::vector<QPixmap*> result;

  for (int i = 0 ; i < frames_count ; ++i) {
    int x = i * frame_width + start_x;
    QPixmap* frame = new QPixmap(std::move(source->copy(
        QRect(x, y, frame_width, frame_height))));
    result.push_back(frame);
  }

  return result;
}

void PixmapLoader::LoadFireTotemAnimations() {
  // file size - 896x480
  // 5 frame rows, 14 frame columns
  const int frame_width = 896 / 14;
  const int frame_height = 480 / 5;
  const int idle_animation_frames_count = 7;
  const int disappear_animation_frames_count = 14;
  const int appear_animation_frames_count = 8;
  // row and column start from 0
  const int idle_animation_row = 1;
  const int idle_animation_column = 0;
  const int disappear_animation_row = 4;
  const int disappear_animation_column = 0;
  const int appear_animation_row = 0;
  const int appear_animation_column = 0;

  P::FireTotem::kAnimations = new QPixmap(":images/fire_totem.png");

  P::FireTotem::kIdle = CreateHorizontalFramesVector(
      P::FireTotem::kAnimations,
      frame_width,
      frame_height,
      idle_animation_frames_count,
      idle_animation_column * frame_width,
      idle_animation_row * frame_height);

  P::FireTotem::kDisappear = CreateHorizontalFramesVector(
      P::FireTotem::kAnimations,
      frame_width,
      frame_height,
      disappear_animation_frames_count,
      disappear_animation_column * frame_width,
      disappear_animation_row * frame_height);

  P::FireTotem::kAppearing = CreateHorizontalFramesVector(
      P::FireTotem::kAnimations,
      frame_width,
      frame_height,
      appear_animation_frames_count,
      appear_animation_column * frame_width,
      appear_animation_row * frame_height);
}

void PixmapLoader::LoadUI() {
  LoadDefaultTextureBox();
}

void PixmapLoader::LoadDefaultTextureBox() {
  using T = P::UI::DefaultTexturedBox;

  T::kTopLeftCorner = new QPixmap(
      ":GUI/Default textured box/top_left_corner.png");
  T::kTopRightCorner = new QPixmap(
      ":GUI/Default textured box/top_right_corner.png");
  T::kBottomLeftCorner = new QPixmap(
      ":GUI/Default textured box/bottom_left_corner.png");
  T::kBottomRightCorner = new QPixmap(
      ":GUI/Default textured box/bottom_right_corner.png");
  T::kLeftSide = new QPixmap(
      ":GUI/Default textured box/left_side.png");
  T::kRightSide = new QPixmap(
      ":GUI/Default textured box/right_side.png");
  T::kTopSide = new QPixmap(
      ":GUI/Default textured box/top_side.png");
  T::kBottomSide = new QPixmap(
      ":GUI/Default textured box/bottom_side.png");
  T::kInside = new QPixmap(
      ":GUI/Default textured box/inside.png");

  kDefaultTexturedBoxPixmaps = TexturedBoxPixmaps {
      T::kTopLeftCorner,
      T::kTopRightCorner,
      T::kBottomLeftCorner,
      T::kBottomRightCorner,
      T::kLeftSide,
      T::kRightSide,
      T::kTopSide,
      T::kBottomSide,
      T::kInside
  };
}
