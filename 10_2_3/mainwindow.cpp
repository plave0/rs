#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bank.h"
#include "transactionthread.h"

#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pbGenerate, &QPushButton::clicked,
            this, &MainWindow::generateResourcesAndFillBoard);
    connect(ui->pbBegin, &QPushButton::clicked,
            this, &MainWindow::startSimulation);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generateResourcesAndFillBoard()
{
    bool conversion_successful {false};
    m_total_resources =
            ui->leTotal->text().toUInt(&conversion_successful);

    if(!conversion_successful) { return; }

    m_bank.generateResources(m_total_resources);

    const auto & resources = m_bank.resources();

    ui->teNode1->setPlainText(QString::number(resources[0]));
    ui->teNode2->setPlainText(QString::number(resources[1]));
    ui->teNode3->setPlainText(QString::number(resources[2]));
    ui->teNode4->setPlainText(QString::number(resources[3]));
    ui->teNode5->setPlainText(QString::number(resources[4]));
}

void MainWindow::startSimulation()
{
    ui->groupBox->setEnabled(false);

    for(auto i = 10u; i != 20u; ++i) {

        quint16 num_threads =
                QRandomGenerator::global()->bounded(0, 5);

        QList<TransactionThread*> threads(5);
        for(auto j = 0u; j != num_threads; ++j) {

            quint16 rnd_node_idx =
                    QRandomGenerator::global()->bounded(0u, 5u);
            quint32 rnd_resource_amount =
                    QRandomGenerator::global()->bounded(1, m_total_resources / num_threads);
            threads[j] = new TransactionThread(m_bank, rnd_node_idx, rnd_resource_amount);
            connect(threads[j], &TransactionThread::finished,
                    threads[j], &QObject::deleteLater);

            threads[j]->start();
        }

        for(auto j = 0u; j != num_threads; ++j) {
            threads[j]->wait();
        }
    }

    ui->groupBox->setEnabled(true);

    const auto & resources = m_bank.resources();

    ui->teNode1->setPlainText(QString::number(resources[0]));
    ui->teNode2->setPlainText(QString::number(resources[1]));
    ui->teNode3->setPlainText(QString::number(resources[2]));
    ui->teNode4->setPlainText(QString::number(resources[3]));
    ui->teNode5->setPlainText(QString::number(resources[4]));
}

