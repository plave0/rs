#include "xmlserializer.h"

#include <QXmlStreamReader>
#include <QVariantMap>
#include <QFile>

XmlSerializer::XmlSerializer(QObject *parent)
    : QObject{parent}
{

}

QList<Source> XmlSerializer::loadSources(const QString file_path)
{
    QList<Source> result {};

    QFile source_file(file_path);
    source_file.open(QFile::ReadOnly);

    QXmlStreamReader stream(&source_file);
    stream.readNextStartElement();

    while(stream.readNextStartElement()) {
        result.append(Source{readVariant(stream)});
    }

    source_file.close();

    return result;
}

QVariant XmlSerializer::readVariant(QXmlStreamReader &stream)
{
    QVariantMap map {};

    stream.readNextStartElement();
    map.insert("volume", stream.readElementText().toUInt());

    stream.readNextStartElement();
    map.insert("name", stream.readElementText());

    stream.readNextStartElement();

    return map;
}
