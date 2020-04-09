#ifndef GUICORE_H
#define GUICORE_H

#include <QMainWindow>

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
};
#endif // GUICORE_H
