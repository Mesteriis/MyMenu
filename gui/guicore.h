/// https://evileg.com/ru/post/60/

#ifndef GUICORE_H
#define GUICORE_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include <QSystemTrayIcon>
#include <QAction>
#include <QStyle>
#include <QDebug>
#include <QDialog>
#include <QHBoxLayout>
#include <QDesktopServices>
#include <QLabel>


#include "guiitem.h"

#include "sys/swcore.h"

QT_BEGIN_NAMESPACE
namespace Ui { class guicore; }
QT_END_NAMESPACE

class guicore : public QMainWindow
{
    Q_OBJECT

public:
    guicore(QWidget *parent = nullptr);
    ~guicore();

    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void closeEvent(QCloseEvent * event);

    void myClicked();

private:
    Ui::guicore *ui;
    QSystemTrayIcon *tray;
    QMenu *menu;

};
#endif // GUICORE_H
