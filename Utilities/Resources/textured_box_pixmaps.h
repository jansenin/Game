#pragma once

#include <QPixmap>

struct TexturedBoxPixmaps {
  QPixmap* top_left_corner;
  QPixmap* top_right_corner;
  QPixmap* bottom_left_corner;
  QPixmap* bottom_right_corner;

  QPixmap* left_side;
  QPixmap* right_side;
  QPixmap* top_side;
  QPixmap* bottom_side;

  QPixmap* inside;
};
