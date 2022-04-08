#include "main_window.h"

#include <QVBoxLayout>
#include <QTimer>
#include <QResource>
#include <QFile>
#include <QDir>

MainWindow::MainWindow() :
    QMainWindow(nullptr) {
  controller_ = new Controller();
  setCentralWidget(controller_->GetView());
  showFullScreen();
}
