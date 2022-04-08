#ifndef RESOURCE_CACHER_H__
#define RESOURCE_CACHER_H__

#include <unordered_map>

#include <QPixmap>

class ResourceCacher {
 public:
  static QPixmap* Pixmap(QString resource_path);

 private:
  static std::unordered_map<QString, QPixmap*> pixmaps;
};

#endif //RESOURCE_CACHER_H__
