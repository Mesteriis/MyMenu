#include "swcore.h"

swcore::swcore(QObject *parent) : QObject(parent)
{
    setObjectName("swcore");
    st = new settings;
}

QStringList swcore::readDir(QString dir)
{
    QDir d(dir);

    d.setFilter(QDir::Files | QDir::Dirs | QDir::NoSymLinks | QDir::NoDotAndDotDot);

    QStringList list = d.entryList();
//    QFileInfo fInfo;
//    for (int i = 0; i < list.size(); ++i)
//    {
        /// some code
//    }

    return list;


}
