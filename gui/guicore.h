/// https://evileg.com/ru/post/60/

#ifndef GUICORE_H
#define GUICORE_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include <QSystemTrayIcon>
#include <QAction>
#include <QStyle>

QT_BEGIN_NAMESPACE
namespace Ui { class guicore; }
QT_END_NAMESPACE

class guicore : public QMainWindow
{
    Q_OBJECT

public:
    guicore(QWidget *parent = nullptr);
    ~guicore();

private:
    Ui::guicore *ui;
    QSystemTrayIcon *tray;

};
#endif // GUICORE_H
