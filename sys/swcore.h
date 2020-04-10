#ifndef SWCORE_H
#define SWCORE_H

#include <QObject>
#include "settings.h"

class swcore : public QObject
{
    Q_OBJECT
public:
    swcore(QObject *parent = Q_NULLPTR);

private:

    settings *st;

};

#endif // SWCORE_H
