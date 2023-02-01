#ifndef BUYERTHREAD_H
#define BUYERTHREAD_H

#include "recipebook.h"

#include <QThread>

class BuyerThread : public QThread
{
    Q_OBJECT
public:
    BuyerThread(RecipeBook& recipe_book);

protected:
    void run() override;

private:
    RecipeBook& m_recipe_book;

signals:
    void updateDisplay();
};

#endif // BUYERTHREAD_H
