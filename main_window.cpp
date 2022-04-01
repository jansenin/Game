#include "main_window.h"

#include <iostream>

#include <QVBoxLayout>
#include <QTimer>

MainWindow::MainWindow() :
    QMainWindow(nullptr) {
  controller_ = new Controller();
  setCentralWidget(controller_->GetView());
  showFullScreen();
}
