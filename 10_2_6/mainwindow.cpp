#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "buyerthread.h"

/*
Klase:
    Recipe(name(QString),
            ingredients(QList<QString>),
            aquired_ingredients(QList<QString>),
            void fromQVarinat(variant),
            QString toQStirng()

    RecipeBook(
        m_recipes(QList<Recipe>),
        m_recipe_mutex(QMutex),
        QString toQString(),
        QString buyRandomIngredient()

    BuyerThread(
        RecipeBook& m_recipe_book,
        signal ingredientBought()
        )

    MainWindow(
        RecipeBook
        void updateDisplay()
        )

*/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pbLoad, &QPushButton::clicked,
            this, &MainWindow::loadRecipesAndDisplay);
    connect(ui->pbStart, &QPushButton::clicked,
            this, &MainWindow::startSimulation);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadRecipesAndDisplay()
{
    JsonSerializer serializer;
    m_recipe_book = QSharedPointer<RecipeBook>::create(serializer.loadRecipes());

    updateDisplay();
}

void MainWindow::startSimulation()
{
    bool conversion_sucessful {false};
    unsigned int num_buyers = ui->leBuyers->text().toUInt(&conversion_sucessful);

    if(!conversion_sucessful) { return; }

    for(auto i = 0u; i != num_buyers; ++i) {
        BuyerThread* thread = new BuyerThread(*m_recipe_book);
        connect(thread, &BuyerThread::finished,
                thread, &BuyerThread::deleteLater);
        connect(thread, &BuyerThread::updateDisplay,
                this, &MainWindow::updateDisplay);
        thread->start();
    }
}

void MainWindow::updateDisplay()
{
    QMutex& recipe_lock {m_recipe_book->getLock()};
    QMutexLocker locker(&recipe_lock);
    ui->teDisplay->setText(m_recipe_book->toQString());
}

