#include "gui/guicore.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    guicore w;
//    w.show();
    return a.exec();
}
