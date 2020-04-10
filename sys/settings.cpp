#include "settings.h"

settings::settings(QObject *parent)
{
    setParent(parent);
    setObjectName("sysSettings");
    sysSettings = new QSettings;

}

settings::~settings()
{
    deleteLater();
}
