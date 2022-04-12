#include <QApplication>

#include "main_window.h"
#include "Utilities/Resources/pixmap_loader.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  PixmapLoader::LoadPixmaps();
  MainWindow window;
  window.show();
  return QApplication::exec();
}
