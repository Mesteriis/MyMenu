#include "settings.h"

settings::settings(QObject *parent)
{
    setParent(parent);
    setObjectName("sysSettings");
    sysSettings = new QSettings;
    cb = new fileSettingsCombain;
    cb->slot_saveSettings();
}

settings::~settings()
{
    deleteLater();
}
