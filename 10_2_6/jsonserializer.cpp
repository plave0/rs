#include "jsonserializer.h"

QList<Recipe> JsonSerializer::loadRecipes()
{
    QFile source("recipes.json");
    source.open(QFile::ReadOnly);
    QJsonDocument doc = QJsonDocument::fromJson(source.readAll());
    source.close();

    QVariantList list = doc.toVariant().toList();
    QList<Recipe> recipe_list {};

    for(auto const & recipe_var : list) {
        recipe_list.push_back(Recipe{recipe_var});
    }

    return recipe_list;
}
