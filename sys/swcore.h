#ifndef SWCORE_H
#define SWCORE_H

#include <QObject>
#include <QFileInfo>
#include <QDir>

#include "settings.h"

class swcore : public QObject
{
    Q_OBJECT
public:
    swcore(QObject *parent = Q_NULLPTR);


    QStringList readDir (QString dir);

private:

    settings *st;

};

#endif // SWCORE_H
