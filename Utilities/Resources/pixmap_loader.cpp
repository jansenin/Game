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

TexturedBoxPixmaps PixmapLoader::kDefaultTexturedBoxPixmaps;
TexturedBoxPixmaps PixmapLoader::kMenuTexturedBoxPixmaps;
TexturedBoxPixmaps PixmapLoader::kMenu2TexturedBoxPixmaps;
TexturedBoxPixmaps PixmapLoader::kButtonTexturedBoxPixmaps;

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
  LoadMenuTextureBox();
  LoadMenu2TextureBox();
  LoadButtonTextureBox();
}

void PixmapLoader::LoadDefaultTextureBox() {
  kDefaultTexturedBoxPixmaps = TexturedBoxPixmaps {
      new QPixmap(":GUI/Textured boxes/Default/top_left_corner.png"),
      new QPixmap(":GUI/Textured boxes/Default/top_right_corner.png"),
      new QPixmap(":GUI/Textured boxes/Default/bottom_left_corner.png"),
      new QPixmap(":GUI/Textured boxes/Default/bottom_right_corner.png"),
      new QPixmap(":GUI/Textured boxes/Default/left_side.png"),
      new QPixmap(":GUI/Textured boxes/Default/right_side.png"),
      new QPixmap(":GUI/Textured boxes/Default/top_side.png"),
      new QPixmap(":GUI/Textured boxes/Default/bottom_side.png"),
      new QPixmap(":GUI/Textured boxes/Default/inside.png")
  };
}

void PixmapLoader::LoadMenuTextureBox() {
  kMenuTexturedBoxPixmaps = TexturedBoxPixmaps {
      new QPixmap(":GUI/Textured boxes/Menu/top_left_corner.png"),
      new QPixmap(":GUI/Textured boxes/Menu/top_right_corner.png"),
      new QPixmap(":GUI/Textured boxes/Menu/bottom_left_corner.png"),
      new QPixmap(":GUI/Textured boxes/Menu/bottom_right_corner.png"),
      new QPixmap(":GUI/Textured boxes/Menu/left_side.png"),
      new QPixmap(":GUI/Textured boxes/Menu/right_side.png"),
      new QPixmap(":GUI/Textured boxes/Menu/top_side.png"),
      new QPixmap(":GUI/Textured boxes/Menu/bottom_side.png"),
      new QPixmap(":GUI/Textured boxes/Menu/inside.png")
  };
}

void PixmapLoader::LoadMenu2TextureBox() {
  kMenu2TexturedBoxPixmaps = TexturedBoxPixmaps {
      new QPixmap(":GUI/Textured boxes/Menu2/top_left_corner.png"),
      new QPixmap(":GUI/Textured boxes/Menu2/top_right_corner.png"),
      new QPixmap(":GUI/Textured boxes/Menu2/bottom_left_corner.png"),
      new QPixmap(":GUI/Textured boxes/Menu2/bottom_right_corner.png"),
      new QPixmap(":GUI/Textured boxes/Menu2/left_side.png"),
      new QPixmap(":GUI/Textured boxes/Menu2/right_side.png"),
      new QPixmap(":GUI/Textured boxes/Menu2/top_side.png"),
      new QPixmap(":GUI/Textured boxes/Menu2/bottom_side.png"),
      new QPixmap(":GUI/Textured boxes/Menu2/inside.png")
  };
}

void PixmapLoader::LoadButtonTextureBox() {
  kButtonTexturedBoxPixmaps = TexturedBoxPixmaps {
      new QPixmap(":GUI/Textured boxes/Button/top_left_corner.png"),
      new QPixmap(":GUI/Textured boxes/Button/top_right_corner.png"),
      new QPixmap(":GUI/Textured boxes/Button/bottom_left_corner.png"),
      new QPixmap(":GUI/Textured boxes/Button/bottom_right_corner.png"),
      new QPixmap(":GUI/Textured boxes/Button/left_side.png"),
      new QPixmap(":GUI/Textured boxes/Button/right_side.png"),
      new QPixmap(":GUI/Textured boxes/Button/top_side.png"),
      new QPixmap(":GUI/Textured boxes/Button/bottom_side.png"),
      new QPixmap(":GUI/Textured boxes/Button/inside.png")
  };
}
