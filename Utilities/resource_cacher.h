#ifndef UTILITIES_RESOURCE_CACHER_H_
#define UTILITIES_RESOURCE_CACHER_H_

#include <unordered_map>

#include <QPixmap>

class ResourceCacher {
 public:
  static QPixmap* Pixmap(const QString& resource_path);

 private:
  static std::unordered_map<QString, QPixmap*> pixmaps;
};

#endif  // UTILITIES_RESOURCE_CACHER_H_
