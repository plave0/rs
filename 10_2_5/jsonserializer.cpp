#include "jsonserializer.h"
#include "city.h"

#include <QString>
#include <QVariant>
#include <QList>
#include <QFile>
#include <QJsonDocument>

QList<City> JsonSerializer::loadCities(const QString& file_path)
{
    QFile source {file_path};
    source.open(QFile::ReadOnly);
    QJsonDocument doc = QJsonDocument::fromJson(source.readAll());
    source.close();

    QVariantList variant_list = doc.toVariant().toList();
    QList<City> cities {};

    for(const auto & variant : variant_list) {
        cities.append(City{variant});
    }

    return cities;
}
