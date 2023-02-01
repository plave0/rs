#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "city.h"
#include "roadbuilder.h"

#include <QMainWindow>
#include <QSharedPointer>
#include <QList>

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
    void displayRoad();

    Ui::MainWindow *ui;
    QSharedPointer<QList<City>> m_cities;
    RoadBuilder m_road_builder;

private slots:
    void loadCitiesAndDisplay();
    void startSimulation();

};
#endif // MAINWINDOW_H
