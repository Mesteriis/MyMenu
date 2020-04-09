#include "guicore.h"
#include "ui_guicore.h"

guicore::guicore(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::guicore)
{
//    ui->setupUi(this);
    tray = new QSystemTrayIcon(this);
    tray->setIcon(this->style()->standardIcon(QStyle::SP_ComputerIcon));
    tray->setToolTip("Tray Program" "\n"
                         "Работа со сворачиванием программы трей");
    QMenu * menu = new QMenu(this);
    QAction * viewWindow = new QAction(trUtf8("Развернуть окно"), this);
    QAction * quitAction = new QAction(trUtf8("Выход"), this);

    connect(viewWindow, SIGNAL(triggered()), this, SLOT(show()));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

    tray->setContextMenu(menu);
//    tray->show();
    tray->showMessage("test","tttteeeesssstttt");

}

guicore::~guicore()
{
    delete ui;
}

