#include "guicore.h"
#include "ui_guicore.h"

guicore::guicore(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::guicore)
{
    ui->setupUi(this);
    swcore *swc = new swcore(this);
    tray = new QSystemTrayIcon(this);
    tray->setIcon(this->style()->standardIcon(QStyle::SP_DirIcon));
    tray->setToolTip("MyMenu");
    menu = new QMenu(this);
    QAction *viewWindowSettings = new QAction("Settings", this);
    QAction *quitAction = new QAction("Exit", this);
    connect(viewWindowSettings, &QAction::triggered, this, &guicore::show);
    connect(quitAction, &QAction::triggered, this, &guicore::close);
    QIcon ico(":/pic/icons_25.png");
    menu->addAction(viewWindowSettings);
    menu->addAction(quitAction);
    menu->addSeparator();

    connect(tray, &QSystemTrayIcon::activated, this, &guicore::iconActivated);
    QList <QAction*> arr;

    auto x = swc->readDir("/Users/avm/Downloads/torrents");

    for (auto i : x) {
        QAction *act = new QAction(ico,i,this);
        act->setObjectName(i);
        connect(act,&QAction::triggered,this,&guicore::myClicked);
        arr.append(act);

    }
    menu->addActions(arr);
    tray->setContextMenu(menu);
    tray->show();
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
        tray->showMessage("MyMenu",
                          "Приложение свернуто в трей. Для того чтобы, "
                          "развернуть окно приложения, щелкните по иконке приложения в трее",
                          QSystemTrayIcon::Information,
                          200);
    }
}

void guicore::myClicked()
{
    qDebug () << sender()->objectName();
    QDesktopServices *d = new QDesktopServices;
    d->openUrl(QUrl("file:/Users/avm/Downloads/")); /// dir
    d->openUrl(QUrl("file:/Users/avm/Downloads/test.txt")); /// file

}

