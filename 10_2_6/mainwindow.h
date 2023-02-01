#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "jsonserializer.h"
#include "recipebook.h"

#include <QMainWindow>
#include <QSharedPointer>
#include <QMutex>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSharedPointer<RecipeBook> m_recipe_book;

private slots:
    void loadRecipesAndDisplay();
    void startSimulation();
    void updateDisplay();

};
#endif // MAINWINDOW_H
