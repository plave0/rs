#ifndef RECIPEBOOK_H
#define RECIPEBOOK_H

#include "recipe.h"

#include <QList>
#include <QString>
#include <QMutex>
#include <QRandomGenerator>

class RecipeBook : public QList<Recipe>
{
public:
    RecipeBook(QList<Recipe>&& recipes);

    void buyRandomIngredient(bool* sucess);
    QString toQString() const;

    inline QMutex &getLock() { return m_recipe_lock; }

private:
    QMutex m_recipe_lock;
    QList<QString> m_ingredients_needed {};
};

#endif // RECIPEBOOK_H
