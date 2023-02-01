#include "buyerthread.h"

BuyerThread::BuyerThread(RecipeBook& recipe_book):
    QThread(), m_recipe_book(recipe_book)
{}

void BuyerThread::run()
{

    bool thread_running {true};
    while(thread_running) {

       msleep(1000);

       bool item_bought {};
       m_recipe_book.buyRandomIngredient(&item_bought);
       if(!item_bought) {
           thread_running = false;
       }
       else {
           emit updateDisplay();
       }
    }

    emit updateDisplay();
}
