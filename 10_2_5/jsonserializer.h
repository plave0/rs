#ifndef JSONSERIALIZER_H
#define JSONSERIALIZER_H

#include "city.h"

#include <QList>
#include <QString>


class JsonSerializer
{
public:
    JsonSerializer() {}

    QList<City> loadCities(const QString& file_path);
};

#endif // JSONSERIALIZER_H
