#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>



class settings : public QObject
{
    Q_OBJECT
public:
    settings(QObject *parent = Q_NULLPTR);
    ~settings();

private:

    QSettings *sysSettings;


};

#endif // SETTINGS_H
