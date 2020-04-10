#ifndef ITEMMENU_H
#define ITEMMENU_H

#include <QObject>
#include <QFileInfo>
enum __TypeItem{
    _DIR,
    _FILE
};

struct _pair{
    QString ico;
    QString Action;
};

class itemMenu : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString nameItem READ nameItem )
    Q_PROPERTY(QString pathToItem READ pathToItem )
    Q_PROPERTY(__TypeItem type READ type )
public:
    explicit itemMenu(QString name, QString path, QObject *parent = Q_NULLPTR);
    ~itemMenu();
    QString nameItem() const;

    QString pathToItem() const;

    __TypeItem type() const;

signals:

private:
    _pair term;
    _pair openDir;



    QString m_nameItem;
    QString m_pathToItem;
    __TypeItem m_type;
};

#endif // ITEMMENU_H
