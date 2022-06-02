#pragma once

#include <vector>

#include <QPixmap>

#include "Utilities/animation.h"

class PixmapLoader {
 public:
  class Pixmaps {
   public:
    // TODO(jansenin): maybe make this readonly
    static QPixmap* kBackground;
    static QPixmap* kTestBullet;
    static QPixmap* kTestMob;
    static QPixmap* kTestTower;
    static QPixmap* kTestTowerGun;
    static QPixmap* kTestTowerSlot;
    static std::vector<QPixmap*> kLevelMaps;

    // For animations test
    static QPixmap* kFireTotemAnimations;
    static std::vector<QPixmap*> kFireTotemIdle;
    static std::vector<QPixmap*> kFireTotemDisappear;
    static std::vector<QPixmap*> kFireTotemAppearing;

    static std::vector<QPixmap*> kSkeletonWalk;
    static std::vector<QPixmap*> kSkeletonDeath;

    static QPixmap* kCobraAnimations;
    static std::vector<QPixmap*> kCobraWalk;
    static std::vector<QPixmap*> kCobraDeath;

    static QPixmap* kHedgehogAnimations;
    static std::vector<QPixmap*> kHedgehogWalk;
    static std::vector<QPixmap*> kHedgehogDeath;

    static QPixmap* kDwarfAnimations;
    static std::vector<QPixmap*> kDwarfWalk;
    static std::vector<QPixmap*> kDwarfDeath;
  };

  static void LoadPixmaps();

 private:
  static std::vector<QPixmap*> CreateHorizontalFramesVector(
      QPixmap* source,
      int frame_width,
      int frame_height,
      int frames_count,
      int start_x,
      int y);

  static void LoadFireTotemAnimations();
  static void LoadSkeletonAnimations();
  static void LoadCobraAnimations();
  static void LoadHedgehogAnimations();
  static void LoadDwarfAnimations();
};
