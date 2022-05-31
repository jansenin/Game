#pragma once

#include <vector>

#include <QPixmap>

#include "Utilities/animation.h"
#include "Utilities/Resources/textured_box_pixmaps.h"

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
    class FireTotem {
     public:
      static QPixmap* kAnimations;
      static std::vector<QPixmap*> kIdle;
      static std::vector<QPixmap*> kDisappear;
      static std::vector<QPixmap*> kAppearing;
    };

    class UI {
     public:
      class DefaultTexturedBox {
       public:
        static QPixmap* kTopLeftCorner;
        static QPixmap* kTopRightCorner;
        static QPixmap* kBottomLeftCorner;
        static QPixmap* kBottomRightCorner;

        static QPixmap* kLeftSide;
        static QPixmap* kRightSide;
        static QPixmap* kTopSide;
        static QPixmap* kBottomSide;

        static QPixmap* kInside;
      };
    };
  };
  static TexturedBoxPixmaps kDefaultTexturedBoxPixmaps;

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
  static void LoadUI();
  static void LoadDefaultTextureBox();
};
