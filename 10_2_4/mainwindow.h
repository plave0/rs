#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "streetdata.h"

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
    void initTable();
    void updateDisplay();

    Ui::MainWindow *ui;
    StreetData m_street_data;

private slots:
    void startSimulation();
    void displayDonation(int street_idx, int donation_amount);
};
#endif // MAINWINDOW_H
