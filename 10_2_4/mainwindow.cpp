#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "donationthread.h"

#include <QString>

/*
 Klasa Streets:
 - Streets()
 - void donateToStreet(street_idx, amount)
 - bool hasGoodStandard(street_idx)

 Klasa DonationThread:
 - DonationThread()
 - signal donationFinished(street_idx, donation_amount)

 Klasa MainWindow:
 - slot updateStreetDisplay(street_idx, donation_amount)
  */

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_street_data()
{
    ui->setupUi(this);
    initTable();
    updateDisplay();

    connect(ui->pbStart,&QPushButton::clicked,
            this, &MainWindow::startSimulation);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initTable()
{
    for(auto i = 0u; i != 5; ++i) {
        for(auto j = 0u; j != 5; ++j) {
            ui->tvStreets->setItem(i, j, new QTableWidgetItem());
        }
    }
}

void MainWindow::updateDisplay()
{
    for(auto i = 0u; i != 5; ++i) {
        for(auto j = 0u; j != 5; ++j) {
            ui->tvStreets->item(i, j)->setText(QString::number(m_street_data[i][j]));
        }
    }
}

void MainWindow::startSimulation()
{
    for (auto i = 0u; i != 5u; ++i) {
        DonationThread* thread = new DonationThread(m_street_data, i);
        connect(thread, &DonationThread::finished,
                thread, &QObject::deleteLater);
        connect(thread, &DonationThread::donationFinished,
                this, &MainWindow::displayDonation);
        thread->start();
    }
}

void MainWindow::displayDonation(int street_idx, int donation_amount)
{
    for (auto famili_idx = 0u; famili_idx != 5; ++famili_idx) {
        ui->tvStreets->
                item(street_idx, famili_idx)->
                setText(QString::number(m_street_data[street_idx][famili_idx]));
    }

    ui->lvDonations->addItem(
                "Donaciji u ulici " +
                QString::number(street_idx) +
                " od " +
                QString::number(donation_amount)
                );

    if(!m_street_data.hasGoodStandard(street_idx)) {
        DonationThread* thread = new DonationThread(m_street_data, street_idx);
        connect(thread, &DonationThread::finished,
                thread, &QObject::deleteLater);
        connect(thread, &DonationThread::donationFinished,
                this, &MainWindow::displayDonation);
        thread->start();
    }
}

