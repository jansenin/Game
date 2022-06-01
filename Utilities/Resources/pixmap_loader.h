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

    // For animations test
    static QPixmap* kFireTotemAnimations;
    static std::vector<QPixmap*> kFireTotemIdle;
    static std::vector<QPixmap*> kFireTotemDisappear;
    static std::vector<QPixmap*> kFireTotemAppearing;
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
};
