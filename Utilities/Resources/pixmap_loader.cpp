#include <utility>

#include "constants.h"
#include "pixmap_loader.h"

using P = PixmapLoader::Pixmaps;

QPixmap* P::kBackground;
QPixmap* P::kMagicProjectileLevel1;
QPixmap* P::kMagicProjectileLevel2;
QPixmap* P::kMagicProjectileLevel3;
QPixmap* P::kCannonProjectileLevel1;
QPixmap* P::kCannonProjectileLevel2;
QPixmap* P::kCannonProjectileLevel3;
QPixmap* P::kMagicTowerLevel1;
QPixmap* P::kMagicTowerLevel2;
QPixmap* P::kMagicTowerLevel3;
QPixmap* P::kCannonTowerLevel1;
QPixmap* P::kCannonTowerLevel2;
QPixmap* P::kCannonTowerLevel3;
QPixmap* P::kTowerSlot;
std::vector<QPixmap*> P::kLevelMaps;
QPixmap* P::kEmpty;

QPixmap* P::kBombIdleFrame;
QPixmap* P::kBomb0;
QPixmap* P::kBomb1;
QPixmap* P::kBomb2;
QPixmap* P::kBomb3;
QPixmap* P::kBomb4;
QPixmap* P::kBomb5;
std::vector<QPixmap*> P::kBombExplosion;
std::vector<QPixmap*> P::kBombIdle;

QPixmap* P::kBearTrap;
QPixmap* P::kBearTrapAnimations;
std::vector<QPixmap*> P::kBearTrapIdle;
std::vector<QPixmap*> P::kBearTrapAttacking;
std::vector<QPixmap*> P::kBearTrapBroken;
std::vector<QPixmap*> P::kBearTrapRepairing;

std::vector<QPixmap*> P::kCoinIdle;
QPixmap* P::kCoinAnimations;

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

QPixmap* P::MagicProjectile::kAnimationsLevel1;
QPixmap* P::MagicProjectile::kAnimationsLevel2;
QPixmap* P::MagicProjectile::kAnimationsLevel3;
std::vector<QPixmap*> P::MagicProjectile::kDestroyingLevel1;
std::vector<QPixmap*> P::MagicProjectile::kDestroyingLevel2;
std::vector<QPixmap*> P::MagicProjectile::kDestroyingLevel3;
// -----------------------------------------------------------------------------

TexturedBoxPixmaps PixmapLoader::kDefaultTexturedBoxPixmaps;
TexturedBoxPixmaps PixmapLoader::kMenuTexturedBoxPixmaps;
TexturedBoxPixmaps PixmapLoader::kMenu2TexturedBoxPixmaps;
TexturedBoxPixmaps PixmapLoader::kButtonTexturedBoxPixmaps;

void PixmapLoader::LoadPixmaps() {
  P::kBackground = new QPixmap(":images/background.png");
  P::kMagicProjectileLevel1 =
      new QPixmap(":images/magic_projectile_level1.png");
  P::kMagicProjectileLevel2 =
      new QPixmap(":images/magic_projectile_level2.png");
  P::kMagicProjectileLevel3 =
      new QPixmap(":images/magic_projectile_level3.png");
  P::kCannonProjectileLevel1 =
      new QPixmap(":images/cannon_projectile_level1.png");
  P::kCannonProjectileLevel2 =
      new QPixmap(":images/cannon_projectile_level2.png");
  P::kCannonProjectileLevel3 =
      new QPixmap(":images/cannon_projectile_level3.png");
  P::kBearTrap = new QPixmap(":images/bear_trap.png");
  P::kTowerSlot = new QPixmap(":images/tower_slot.png");
  P::kMagicTowerLevel1 = new QPixmap(":images/magic_tower_level1.png");
  P::kMagicTowerLevel2 = new QPixmap(":images/magic_tower_level2.png");
  P::kMagicTowerLevel3 = new QPixmap(":images/magic_tower_level3.png");
  P::kCannonTowerLevel1 = new QPixmap(":images/cannon_tower_level1.png");
  P::kCannonTowerLevel2 = new QPixmap(":images/cannon_tower_level2.png");
  P::kCannonTowerLevel3 = new QPixmap(":images/cannon_tower_level3.png");
  for (int i = 1; i <= LevelData::kLevelsCount; ++i) {
    P::kLevelMaps.push_back(new QPixmap(":Levels/Level"
                                            + QString::number(i)
                                            + "/map.png"));
  }
  P::kEmpty = new QPixmap();

  LoadBearTrapAnimations();
  LoadBombAnimations();
  LoadCoinAnimations();
  LoadFireTotemAnimations();
  LoadSkeletonAnimations();
  LoadCobraAnimations();
  LoadHedgehogAnimations();
  LoadDwarfAnimations();
  LoadExplosionAnimation();
  LoadUI();
  LoadMagicProjectileAnimations();
}

std::vector<QPixmap*> PixmapLoader::CreateHorizontalFramesVector(
    QPixmap* source,
    int frame_width,
    int frame_height,
    int frames_count,
    int start_x,
    int y) {
  std::vector<QPixmap*> result;

  for (int i = 0; i < frames_count; ++i) {
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
      walk_animation_row * frame_walk_height);

  P::Skeleton::kDeath = CreateHorizontalFramesVector(
      death_animation,
      frame_death_width,
      frame_death_height,
      death_animation_frames_count,
      death_animation_column * frame_death_width,
      death_animation_row * frame_death_height);

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
  kDefaultTexturedBoxPixmaps = TexturedBoxPixmaps{
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
  kMenuTexturedBoxPixmaps = TexturedBoxPixmaps{
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
  kMenu2TexturedBoxPixmaps = TexturedBoxPixmaps{
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
  kButtonTexturedBoxPixmaps = TexturedBoxPixmaps{
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

void PixmapLoader::LoadBearTrapAnimations() {
  // file size - 128x32
  // 1 frame row, 4 frame columns
  const int frame_width = 128 / 4;
  const int frame_height = 32;
  const int idle_animation_frames_count = 1;
  const int attack_animation_frames_count = 3;
  const int broken_animation_frames_count = 1;
  const int repairing_animation_frames_count = 1;
  // row and column start from 0
  const int idle_animation_row = 0;
  const int idle_animation_column = 0;
  const int attack_animation_row = 0;
  const int attack_animation_column = 1;
  const int broken_animation_row = 0;
  const int broken_animation_column = 3;
  const int repairing_animation_row = 0;
  const int repairing_animation_column = 0;

  P::kBearTrapAnimations = new QPixmap(":images/bear_trap.png");

  P::kBearTrapIdle = CreateHorizontalFramesVector(
      P::kBearTrapAnimations,
      frame_width,
      frame_height,
      idle_animation_frames_count,
      idle_animation_column * frame_width,
      idle_animation_row * frame_height);

  P::kBearTrapBroken = CreateHorizontalFramesVector(
      P::kBearTrapAnimations,
      frame_width,
      frame_height,
      broken_animation_frames_count,
      broken_animation_column * frame_width,
      broken_animation_row * frame_height);

  P::kBearTrapAttacking = CreateHorizontalFramesVector(
      P::kBearTrapAnimations,
      frame_width,
      frame_height,
      attack_animation_frames_count,
      attack_animation_column * frame_width,
      attack_animation_row * frame_height);

  P::kBearTrapAttacking = CreateHorizontalFramesVector(
      P::kBearTrapAnimations,
      frame_width,
      frame_height,
      attack_animation_frames_count,
      attack_animation_column * frame_width,
      attack_animation_row * frame_height);

  P::kBearTrapRepairing = CreateHorizontalFramesVector(
      P::kBearTrapAnimations,
      frame_width,
      frame_height,
      repairing_animation_frames_count,
      repairing_animation_column * frame_width,
      repairing_animation_row * frame_height);
}

void PixmapLoader::LoadBombAnimations() {
  P::kBombIdleFrame = new QPixmap(":images/bomb0.png");
  P::kBomb0 = new QPixmap(":images/bomb0.png");
  P::kBomb1 = new QPixmap(":images/bomb1.png");
  P::kBomb2 = new QPixmap(":images/bomb2.png");
  P::kBomb3 = new QPixmap(":images/bomb3.png");
  P::kBomb4 = new QPixmap(":images/bomb4.png");
  P::kBomb5 = new QPixmap(":images/bomb5.png");
  P::kBombExplosion.push_back(P::kBomb0);
  P::kBombExplosion.push_back(P::kBomb1);
  P::kBombExplosion.push_back(P::kBomb2);
  P::kBombExplosion.push_back(P::kBomb3);
  P::kBombExplosion.push_back(P::kBomb4);
  P::kBombExplosion.push_back(P::kBomb5);
  P::kBombIdle.push_back(P::kBombIdleFrame);
}

void PixmapLoader::LoadCoinAnimations() {
  // file size - 224x16
  // 1 frame rows, 14 frame columns
  const int frame_width = 224 / 14;
  const int frame_height = 16;
  const int idle_animation_frames_count = 14;
  // row and column start from 0
  const int idle_animation_row = 0;
  const int idle_animation_column = 0;

  P::kCoinAnimations = new QPixmap(":images/coin.png");

  P::kCoinIdle = CreateHorizontalFramesVector(
      P::kCoinAnimations,
      frame_width,
      frame_height,
      idle_animation_frames_count,
      idle_animation_column * frame_width,
      idle_animation_row * frame_height);
}

void PixmapLoader::LoadMagicProjectileAnimations() {
  // file size - 48x32
  // 2 frame rows, 3 frame columns
  const int frame_width_level1 = 48 / 3;
  const int frame_height_level1 = 32 / 2;
  const int destroying_animation_frames_count_level1 = 3;
  // row and column start from 0
  const int destroying_animation_row_level1 = 1;
  const int destroying_animation_column_level1 = 0;

  P::MagicProjectile::kAnimationsLevel1 =
      new QPixmap(":images/magic_projectile_animations_level1.png");

  P::MagicProjectile::kDestroyingLevel1 = CreateHorizontalFramesVector(
      P::MagicProjectile::kAnimationsLevel1,
      frame_width_level1,
      frame_height_level1,
      destroying_animation_frames_count_level1,
      destroying_animation_column_level1 * frame_width_level1,
      destroying_animation_row_level1 * frame_height_level1);

  // file size - 48x32
  // 2 frame rows, 3 frame columns
  const int frame_width_level2 = 48 / 3;
  const int frame_height_level2 = 32 / 2;
  const int destroying_animation_frames_count_level2 = 3;
  // row and column start from 0
  const int destroying_animation_row_level2 = 1;
  const int destroying_animation_column_level2 = 0;

  P::MagicProjectile::kAnimationsLevel2 =
      new QPixmap(":images/magic_projectile_animations_level2.png");

  P::MagicProjectile::kDestroyingLevel2 = CreateHorizontalFramesVector(
      P::MagicProjectile::kAnimationsLevel2,
      frame_width_level2,
      frame_height_level2,
      destroying_animation_frames_count_level2,
      destroying_animation_column_level2 * frame_width_level2,
      destroying_animation_row_level2 * frame_height_level2);

  // file size - 48x32
  // 2 frame rows, 3 frame columns
  const int frame_width_level3 = 48 / 3;
  const int frame_height_level3 = 32 / 2;
  const int destroying_animation_frames_count_level3 = 3;
  // row and column start from 0
  const int destroying_animation_row_level3 = 1;
  const int destroying_animation_column_level3 = 0;

  P::MagicProjectile::kAnimationsLevel3 =
      new QPixmap(":images/magic_projectile_animations_level3.png");

  P::MagicProjectile::kDestroyingLevel3 = CreateHorizontalFramesVector(
      P::MagicProjectile::kAnimationsLevel3,
      frame_width_level3,
      frame_height_level3,
      destroying_animation_frames_count_level3,
      destroying_animation_column_level3 * frame_width_level3,
      destroying_animation_row_level3 * frame_height_level3);
}
