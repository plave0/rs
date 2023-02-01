#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "xmlserializer.h"
#include "drainthread.h"

#include <QFile>
#include <QXmlStreamReader>
#include <QMutexLocker>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pbPopuni, &QPushButton::clicked,
            this, &MainWindow::loadSources);
    connect(ui->pbZapocni, &QPushButton::clicked,
            this, &MainWindow::startDrain);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadSources()
{
    XmlSerializer serializer;
    ui->lvIzvori->clear();

    m_sources = serializer.loadSources("sources.xml");

    quint32 total_volume {};
    for (const auto & source : m_sources) {
        total_volume += source.volume();
        ui->lvIzvori->addItem(source.toQString());
    }

    ui->leZapreminaIzvora->setText(QString::number(total_volume));
}

void MainWindow::updateSource(qsizetype source_idx, quint32 amount)
{
    ui->lvIzvori->item(source_idx)->setText(m_sources[source_idx].toQString());

    quint32 amount_to_fill = qMin(amount, m_total_volume - m_drained_volume);
    quint32 amount_lost = amount - amount_to_fill;

    m_drained_volume += amount_to_fill;
    m_loss_volume += amount_lost;

    ui->leTekucaZapremina->setText(QString::number(m_drained_volume));
    ui->leGubitak->setText(QString::number(m_loss_volume));
}

void MainWindow::startDrain()
{
    bool total_volume_correct_input {};
    if(ui->leUkupnaZapremina->text().isEmpty() ||
       ui->leUkupnaZapremina->text().toInt(&total_volume_correct_input) < 0 ||
       !total_volume_correct_input ||
       ui->lvIzvori->count() == 0u
       ) {
        return;
    }

    m_total_volume = ui->leUkupnaZapremina->text().toUInt();

    for(auto i = 0u; i != m_sources.length(); ++i) {
        DrainThread* thread = new DrainThread(m_sources, m_source_mutex);
        connect(thread, &DrainThread::finished, thread, &QObject::deleteLater);
        connect(thread, &DrainThread::drainedFromSource, this, &MainWindow::updateSource);
        thread->start();
    }
}

