#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "bank.h"

#include <QMainWindow>

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
    Bank m_bank {};
    qint32 m_total_resources;

private slots:
    void generateResourcesAndFillBoard();
    void startSimulation();
};
#endif // MAINWINDOW_H
