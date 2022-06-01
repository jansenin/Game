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

QPixmap* P::kFireTotemAnimations;
std::vector<QPixmap*> P::kFireTotemIdle;
std::vector<QPixmap*> P::kFireTotemDisappear;
std::vector<QPixmap*> P::kFireTotemAppearing;
std::vector<QPixmap*> P::kSkeletonWalk;
std::vector<QPixmap*> P::kSkeletonDeath;

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
  LoadFireTotemAnimations();
  LoadSkeletonAnimations();
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

  P::kFireTotemAnimations = new QPixmap(":images/fire_totem.png");

  P::kFireTotemIdle = CreateHorizontalFramesVector(
      P::kFireTotemAnimations,
      frame_width,
      frame_height,
      idle_animation_frames_count,
      idle_animation_column * frame_width,
      idle_animation_row * frame_height);

  P::kFireTotemDisappear = CreateHorizontalFramesVector(
      P::kFireTotemAnimations,
      frame_width,
      frame_height,
      disappear_animation_frames_count,
      disappear_animation_column * frame_width,
      disappear_animation_row * frame_height);

  P::kFireTotemAppearing = CreateHorizontalFramesVector(
      P::kFireTotemAnimations,
      frame_width,
      frame_height,
      appear_animation_frames_count,
      appear_animation_column * frame_width,
      appear_animation_row * frame_height);
}

void PixmapLoader::LoadSkeletonAnimations() {
  // walk 13
  //death 14
  // file size - 896x480
  // 5 frame rows, 14 frame columns
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

  P::kSkeletonWalk = CreateHorizontalFramesVector(
      walk_animation,
      frame_walk_width,
      frame_walk_height,
      walk_animation_frames_count,
      walk_animation_column * frame_walk_width,
      walk_animation_row  * frame_walk_height);

  P::kSkeletonDeath = CreateHorizontalFramesVector(
      death_animation,
      frame_death_width,
      frame_death_height,
      death_animation_frames_count,
      death_animation_column * frame_death_width,
      death_animation_row  * frame_death_height);

  delete walk_animation;
  delete death_animation;
}
