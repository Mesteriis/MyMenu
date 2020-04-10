#include "guicore.h"
#include "ui_guicore.h"

guicore::guicore(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::guicore)
{
    ui->setupUi(this);
    tray = new QSystemTrayIcon(this);
    tray->setIcon(this->style()->standardIcon(QStyle::SP_DirIcon));
    tray->setToolTip("MyMenu");
    menu = new QMenu(this);
    QAction * viewWindow = new QAction("Развернуть окно", this);
    QAction * quitAction = new QAction("Выход", this);

    connect(viewWindow, &QAction::triggered, this, &guicore::show);
    connect(quitAction, &QAction::triggered, this, &guicore::close);
    QIcon ico(":/pic/icons_25.png");
    menu->addMenu(ico,"test");
    menu->addSection("tset");
    menu->setAsDockMenu();
    menu->addAction(viewWindow);
    menu->addAction(quitAction);

    tray->setContextMenu(menu);


    tray->show();


    connect(tray, &QSystemTrayIcon::activated, this, &guicore::iconActivated);
//    swcore *swc = new swcore;
}

guicore::~guicore()
{
    delete tray;
    delete menu;
    delete ui;
}

void guicore::iconActivated(QSystemTrayIcon::ActivationReason reason)
{

    switch (reason){
    case QSystemTrayIcon::Unknown:{
        qDebug () << "Unknown";
        break;
    }
    case QSystemTrayIcon::Context:{
        qDebug () << "context";
        break;
    }
    case QSystemTrayIcon::DoubleClick:{
        qDebug () << "DoubleClick";
        break;
    }
    case QSystemTrayIcon::MiddleClick:{
        qDebug () << "MiddleClick";
        break;
    }
    case QSystemTrayIcon::Trigger:{
        qDebug () << "Trigger";
        }
        break;
    }
}

void guicore::closeEvent(QCloseEvent *event)
{
    if(this->isVisible()){
        event->ignore();
        this->hide();
        QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);

        tray->showMessage("Tray Program",
                              trUtf8("Приложение свернуто в трей. Для того чтобы, "
                                     "развернуть окно приложения, щелкните по иконке приложения в трее"),
                              icon,
                              200);
    }
}

