#include "resource_cacher.h"

std::unordered_map<QString, QPixmap*> ResourceCacher::pixmaps;

QPixmap* ResourceCacher::Pixmap(QString resource_path) {
  if (pixmaps.count(resource_path) == 0) {
    pixmaps[resource_path] = new QPixmap(resource_path);
  }
  return pixmaps[resource_path];
}
