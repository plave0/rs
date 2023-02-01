#ifndef JSONSERIALIZER_H
#define JSONSERIALIZER_H

#include "recipe.h"

#include <QVariant>
#include <QList>
#include <QFile>
#include <QJsonDocument>

class JsonSerializer
{
public:
    JsonSerializer() {}

    QList<Recipe> loadRecipes();
};

#endif // JSONSERIALIZER_H
