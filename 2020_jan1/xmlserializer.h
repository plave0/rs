#ifndef XMLSERIALIZER_H
#define XMLSERIALIZER_H

#include "source.h"

#include <QObject>
#include <QXmlStreamReader>

class XmlSerializer : public QObject
{
    Q_OBJECT
public:
    explicit XmlSerializer(QObject *parent = nullptr);
    QList<Source> loadSources(const QString file_path);

private:
    QVariant readVariant(QXmlStreamReader& stream);

signals:

};

#endif // XMLSERIALIZER_H
