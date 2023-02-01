#include "recipebook.h"

RecipeBook::RecipeBook(QList<Recipe>&& recipes):
    QList<Recipe>(recipes)
{
    for(const auto & recipe : *this) {
        m_ingredients_needed.append(recipe.ingredients_needed());
    }
}

void RecipeBook::buyRandomIngredient(bool *sucess)
{
    QMutexLocker locker(&m_recipe_lock);

    if(m_ingredients_needed.length() == 0) {
        *sucess = false;
        return;
    }

    int random_ingredient_idx =
            QRandomGenerator::global()->bounded(m_ingredients_needed.length());
    QString ingr_name = m_ingredients_needed[random_ingredient_idx];

    for(auto & recipe : *this) {
        recipe.ingredientBought(ingr_name);
    }

    m_ingredients_needed.removeAll(ingr_name);

    *sucess = true;

}

QString RecipeBook::toQString() const
{
    QString display_string {};
    for(auto const & recipe : *this) {
        display_string.push_back(recipe.toQString() + "\n");
    }

    return display_string;
}
