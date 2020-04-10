#ifndef FILESETTINGSCOMBAIN_H
#define FILESETTINGSCOMBAIN_H

#include <QObject>
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>

class fileSettingsCombain : public QObject{
    Q_OBJECT
    Q_PROPERTY(QString fileSettings READ fileSettings WRITE setFileSettings)
    Q_PROPERTY(QString defSettings READ defSettings WRITE setDefSettings)
public:
    fileSettingsCombain(QObject *parent = Q_NULLPTR);
    ~fileSettingsCombain();
    QString fileSettings() const;
    QString defSettings() const;
public slots:
    void setFileSettings(QString fileSettings);
    void setDefSettings(QString defSettings);
    void slot_loadSettings();
    void slot_saveSettings();

signals:
    void sig_restorSettings();
    void sig_saveSettings();
    void sig_loadSettings();
private:
    QString m_fileSettings;
    QString m_defSettings;
};

#endif // FILESETTINGSCOMBAIN_H
