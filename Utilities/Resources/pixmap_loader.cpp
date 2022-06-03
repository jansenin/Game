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
QPixmap* P::kEmpty;

QPixmap* P::FireTotem::kAnimations;
std::vector<QPixmap*> P::FireTotem::kIdle;
std::vector<QPixmap*> P::FireTotem::kDisappear;
std::vector<QPixmap*> P::FireTotem::kAppearing;

std::vector<QPixmap*> P::Skeleton::kWalk;
std::vector<QPixmap*> P::Skeleton::kDeath;

QPixmap* P::Cobra::kAnimations;
std::vector<QPixmap*> P::Cobra::kWalk;
std::vector<QPixmap*> P::Cobra::kDeath;

QPixmap* P::Hedgehog::kAnimations;
std::vector<QPixmap*> P::Hedgehog::kWalk;
std::vector<QPixmap*> P::Hedgehog::kDeath;

QPixmap* P::Dwarf::kAnimations;
std::vector<QPixmap*> P::Dwarf::kWalk;
std::vector<QPixmap*> P::Dwarf::kDeath;

QPixmap* P::Explosion::kAnimations;
std::vector<QPixmap*> P::Explosion::kExplosion;

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
    P::kLevelMaps.push_back(new QPixmap(":Levels/Level"
    + QString::number(i)
    + "/map.png"));
  }
  P::kEmpty = new QPixmap();

  LoadFireTotemAnimations();
  LoadSkeletonAnimations();
  LoadCobraAnimations();
  LoadHedgehogAnimations();
  LoadDwarfAnimations();
  LoadExplosionAnimation();
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

void PixmapLoader::LoadSkeletonAnimations() {
  // walk 13 frame columns
  // death 14 frame columns
  // walk file size - 286x33
  // death file size - 495x32
  const int frame_walk_width = 286 / 13;
  const int frame_walk_height = 33;
  const int walk_animation_frames_count = 13;

  const int frame_death_width = 495 / 15;
  const int frame_death_height = 32;
  const int death_animation_frames_count = 14;

  // row and column start from 0
  const int walk_animation_row = 0;
  const int walk_animation_column = 0;

  const int death_animation_row = 0;
  const int death_animation_column = 1;


  QPixmap* walk_animation = new QPixmap(":images/skeleton/walk.png");
  QPixmap* death_animation = new QPixmap(":images/skeleton/death.png");

  P::Skeleton::kWalk = CreateHorizontalFramesVector(
      walk_animation,
      frame_walk_width,
      frame_walk_height,
      walk_animation_frames_count,
      walk_animation_column * frame_walk_width,
      walk_animation_row  * frame_walk_height);

  P::Skeleton::kDeath = CreateHorizontalFramesVector(
      death_animation,
      frame_death_width,
      frame_death_height,
      death_animation_frames_count,
      death_animation_column * frame_death_width,
      death_animation_row  * frame_death_height);

  delete walk_animation;
  delete death_animation;
}

void PixmapLoader::LoadCobraAnimations() {
  // file size - 256x160
  // 5 frame rows, 8 frame columns
  const int frame_width = 256 / 8;
  const int frame_height = 160 / 5;
  const int death_animation_frames_count = 6;
  const int walk_animation_frames_count = 8;
  // row and column start from 0
  const int death_animation_row = 4;
  const int death_animation_column = 0;
  const int walk_animation_row = 1;
  const int walk_animation_column = 0;

  P::Cobra::kAnimations = new QPixmap(":images/cobra.png");

  P::Cobra::kWalk = CreateHorizontalFramesVector(
      P::Cobra::kAnimations,
      frame_width,
      frame_height,
      walk_animation_frames_count,
      walk_animation_column * frame_width,
      walk_animation_row * frame_height);

  P::Cobra::kDeath = CreateHorizontalFramesVector(
      P::Cobra::kAnimations,
      frame_width,
      frame_height,
      death_animation_frames_count,
      death_animation_column * frame_width,
      death_animation_row * frame_height);
}

void PixmapLoader::LoadHedgehogAnimations() {
  // file size - 128x128
  // 4 frame rows, 4 frame columns
  const int frame_width = 128 / 4;
  const int frame_height = 128 / 4;
  const int death_animation_frames_count = 3;
  const int walk_animation_frames_count = 4;
  // row and column start from 0
  const int death_animation_row = 3;
  const int death_animation_column = 0;
  const int walk_animation_row = 1;
  const int walk_animation_column = 0;

  P::Hedgehog::kAnimations = new QPixmap(":images/hedgehog.png");

  P::Hedgehog::kWalk = CreateHorizontalFramesVector(
      P::Hedgehog::kAnimations,
      frame_width,
      frame_height,
      walk_animation_frames_count,
      walk_animation_column * frame_width,
      walk_animation_row * frame_height);

  P::Hedgehog::kDeath = CreateHorizontalFramesVector(
      P::Hedgehog::kAnimations,
      frame_width,
      frame_height,
      death_animation_frames_count,
      death_animation_column * frame_width,
      death_animation_row * frame_height);
}

void PixmapLoader::LoadDwarfAnimations() {
  // file size - 512x256
  // 8 frame rows, 8 frame columns
  const int frame_width = 512 / 8;
  const int frame_height = 256 / 8;
  const int death_animation_frames_count = 7;
  const int walk_animation_frames_count = 8;
  // row and column start from 0
  const int death_animation_row = 7;
  const int death_animation_column = 0;
  const int walk_animation_row = 1;
  const int walk_animation_column = 0;

  P::Dwarf::kAnimations = new QPixmap(":images/dwarf.png");

  P::Dwarf::kWalk = CreateHorizontalFramesVector(
      P::Dwarf::kAnimations,
      frame_width,
      frame_height,
      walk_animation_frames_count,
      walk_animation_column * frame_width,
      walk_animation_row * frame_height);

  P::Dwarf::kDeath = CreateHorizontalFramesVector(
      P::Dwarf::kAnimations,
      frame_width,
      frame_height,
      death_animation_frames_count,
      death_animation_column * frame_width,
      death_animation_row * frame_height);
}

void PixmapLoader::LoadExplosionAnimation() {
  // file size - 384x48
  // 1 frame rows, 8 frame columns
  const int animation_frames_count = 8;
  const int frame_width = 384 / animation_frames_count;
  const int frame_height = 48 / 1;
  // row and column start from 0
  const int animation_row = 0;
  const int animation_column = 0;

  P::Explosion::kAnimations = new QPixmap(":images/explosion.png");

  P::Explosion::kExplosion = CreateHorizontalFramesVector(
      P::Explosion::kAnimations,
      frame_width,
      frame_height,
      animation_frames_count,
      animation_column * frame_width,
      animation_row * frame_height);
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
