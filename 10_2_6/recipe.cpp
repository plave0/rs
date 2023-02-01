#include "recipe.h"

Recipe::Recipe(const QVariant &variant)
{
    fromQVariant(variant);
}

void Recipe::fromQVariant(const QVariant &variant)
{
    QVariantMap map = variant.toMap();

    m_name = map[" title "].toString();

    QVariantList ingr_list = map[" ingredients "].toList();
    for(const auto & ingr : ingr_list) {
        m_ingredients.push_back(ingr.toString());
    }
}

QString Recipe::toQString() const
{
    QString display_string {m_name + "\n"};
    for(const auto & ingr : m_ingredients) {
        if(m_aquired_ingredinets.indexOf(ingr) != -1) {
            display_string.push_back("O");
        }
        else {
            display_string.push_back("X");
        }
    }
    display_string.push_back("\n");

    return display_string;
}

void Recipe::ingredientBought(const QString &ingredient_name)
{
    if(m_aquired_ingredinets.indexOf(ingredient_name) == -1) {
        m_aquired_ingredinets.push_back(ingredient_name);
    }
}

