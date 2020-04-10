#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>

#include "filesettingscombain.h"

class settings : public QObject
{
    Q_OBJECT
public:
    settings(QObject *parent = Q_NULLPTR);
    ~settings();

private:

    QSettings *sysSettings;
    fileSettingsCombain *cb;

};

#endif // SETTINGS_H
