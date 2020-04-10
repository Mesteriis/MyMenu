#include "swcore.h"

swcore::swcore(QObject *parent) : QObject(parent)
{
    setObjectName("swcore");
    st = new settings;
}
