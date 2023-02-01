#ifndef RECIPE_H
#define RECIPE_H

#include <QList>
#include <QString>
#include <QVariant>

class Recipe
{
public:
    Recipe() {}
    Recipe(const QVariant &variant);

    void fromQVariant(const QVariant &variant);
    QString toQString() const;
    void ingredientBought(const QString& ingredient_name);

    inline const QList<QString>& ingredients_needed() const { return m_ingredients; }

private:
    QString m_name {};
    QList<QString> m_ingredients {};
    QList<QString> m_aquired_ingredinets {};
};

#endif // RECIPE_H
