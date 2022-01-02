#include <QApplication>
#include "ui/launcher.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    std::shared_ptr<Launcher> launcher = std::make_shared<Launcher>();
    launcher->show();

    return QApplication::exec();
}
