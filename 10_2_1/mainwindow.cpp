#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sumthread.h"
#include "numberarray.h"
#include "sumarray.h"

#include <QtDebug>
#include <QSharedPointer>
#include <QVector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pbGenerate, &QPushButton::clicked,
            this, &MainWindow::generateAndDisplayArray);
    connect(ui->pbCalculate, &QPushButton::clicked,
            this, &MainWindow::startThreadsAndCalculateSum);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generateAndDisplayArray()
{
    bool conversion_succes {false};
    size_t size = ui->leArraySize->text().toUInt(&conversion_succes);

    if(!conversion_succes) {
        return;
    }

    m_number_array = QSharedPointer<NumberArray>::create(size);
    m_sum_array = QSharedPointer<SumArray>::create();

    ui->teArray->setPlainText(m_number_array->toQString());
}

void MainWindow::startThreadsAndCalculateSum()
{
    bool conversion_succes {false};
    size_t num_thread = ui->leThreadCount->text().toUInt(&conversion_succes);

    if(!conversion_succes) {
        return;
    }

    size_t num_array_size = m_number_array->length();
    size_t step = num_array_size / num_thread;

    QVector<SumThread*> threads;
    for(auto i = 0u; i != num_thread; ++i) {

        threads.append(
                    new SumThread(*m_number_array, *m_sum_array,
                                  i * step,
                                  i * step + step - 1)
                    );
        connect(threads[i], &SumThread::finished,
                threads[i], &QObject::deleteLater);
        threads[i]->start();
    }
    for(auto & thread : threads) {
        thread->wait();
    }

    qint32 result = m_sum_array->calcResult();
    ui->leResult->setText(QString::number(result));
}

