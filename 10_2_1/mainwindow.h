#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "numberarray.h"
#include "sumarray.h"

#include <QMainWindow>
#include <QSharedPointer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void generateAndDisplayArray();
    void startThreadsAndCalculateSum();

private:
    Ui::MainWindow *ui;

    QSharedPointer<NumberArray> m_number_array;
    QSharedPointer<SumArray> m_sum_array;
};
#endif // MAINWINDOW_H
