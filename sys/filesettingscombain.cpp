#include "filesettingscombain.h"

fileSettingsCombain::fileSettingsCombain(QObject *parent) : QObject(parent)
{

}

fileSettingsCombain::~fileSettingsCombain()
{
    deleteLater();
}

QString fileSettingsCombain::fileSettings() const
{
    return m_fileSettings;
}

QString fileSettingsCombain::defSettings() const
{
    return m_defSettings;
}

void fileSettingsCombain::setFileSettings(QString fileSettings){
    m_fileSettings = fileSettings;
}

void fileSettingsCombain::setDefSettings(QString defSettings){
    m_defSettings = defSettings;
}

void fileSettingsCombain::slot_loadSettings(){

}

void fileSettingsCombain::slot_saveSettings(){
    /* Открываем файл для Записи с помощью пути, указанного в lineEditWrite */
    QFile file("../Resources/Settings.xml");
    file.open(QIODevice::WriteOnly);

    /* Создаем объект, с помощью которого осуществляется запись в файл */
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);  // Устанавливаем автоформатирование текста
    xmlWriter.writeStartDocument();     // Запускаем запись в документ
        xmlWriter.writeStartElement("settings");
            xmlWriter.writeStartElement("plane");
                xmlWriter.writeStartElement("cB_1");
                    xmlWriter.writeAttribute("boolean", "0");
                    xmlWriter.writeCharacters("NAME=namePlane;");
                    xmlWriter.writeCharacters("PATH=pathPlane;");
                xmlWriter.writeEndElement(); // cB_1
                xmlWriter.writeStartElement("cB_2");
                    xmlWriter.writeAttribute("boolean", "0");
                    xmlWriter.writeCharacters("NAME=namePlane;");
                    xmlWriter.writeCharacters("PATH=pathPlane;");
                xmlWriter.writeEndElement(); // cB_2
            xmlWriter.writeEndElement(); // plane

            xmlWriter.writeStartElement("icons");
            xmlWriter.writeEndElement(); // icons

            xmlWriter.writeStartElement("menuTitle");
            xmlWriter.writeEndElement(); // menuTitle

            xmlWriter.writeStartElement("systems");
            xmlWriter.writeEndElement(); // systems

        xmlWriter.writeEndElement(); // settings
    xmlWriter.writeEndDocument();
    file.close();   // Закрываем файл
}
