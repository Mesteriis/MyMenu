#include "itemmenu.h"



itemMenu::itemMenu(QString name, QString path, QObject *parent) : QObject(parent)
{
    m_nameItem = name;
    m_pathToItem = path;

    QFileInfo it;
    it.setFile(m_pathToItem);
    m_type =  (it.isDir()) ? _DIR : _FILE;

    switch (m_type) {
        case _FILE:{
            break;
        }
        case _DIR:{
            term.ico = ":/pic/Terminal.icns";
            term.Action = ""; // TODO Подумать как лучше открыть терминал
            break;
        }
    }
}

itemMenu::~itemMenu(){
    deleteLater();
}

QString itemMenu::nameItem() const
{
    return m_nameItem;
}

QString itemMenu::pathToItem() const
{
    return m_pathToItem;
}

__TypeItem itemMenu::type() const
{
    return m_type;
}
