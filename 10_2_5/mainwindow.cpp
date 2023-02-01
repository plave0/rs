#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "city.h"
#include "jsonserializer.h"
#include "builderthread.h"
#include "road.h"

#include <QList>
#include <QString>
#include <QSharedPointer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pbLoad, &QPushButton::clicked,
            this, &MainWindow::loadCitiesAndDisplay);
    connect(ui->pbBuild, &QPushButton::clicked,
            this, &MainWindow::startSimulation);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadCitiesAndDisplay()
{
    JsonSerializer serializer;
    m_cities = QSharedPointer<QList<City>>(
                new QList<City>(serializer.loadCities("cities.json"))
    );

    for(const auto & city : *m_cities) {
        ui->lvCities->addItem(city.toQString());
    }
}

void MainWindow::startSimulation()
{
    if(m_cities.isNull()) { return; }

    auto next_city_idx = 0u;
    for(auto i = 0u; i != m_cities->length() - 1; ++i) {
        (*m_cities)[next_city_idx].visited();
        BuilderThread* thread = new BuilderThread(*m_cities, m_road_builder, next_city_idx);
        connect(thread, &BuilderThread::finished,
                thread, &QObject::deleteLater);

        thread->start();

        thread->wait();

        displayRoad();

        next_city_idx = m_cities->indexOf(m_road_builder.getLastRoad().destination());
    }
}

void MainWindow::displayRoad()
{
    const Road& road = m_road_builder.getLastRoad();
    ui->lvRoads->addItem(QString(
        "Added a new road form " + road.toQString()
    ));
}

