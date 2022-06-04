#include "main_window.h"

#include "Controller/controller.h"

MainWindow::MainWindow() :
    QMainWindow(nullptr) {
  setCentralWidget(Controller::Instance()->GetView());
  showFullScreen();
}
