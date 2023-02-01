#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "source.h"

#include <QMainWindow>
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

    QList<Source>& sources() { return m_sources; }
    QMutex& sourcesMutex() { return m_source_mutex; }

private:
    Ui::MainWindow *ui;
    QList<Source> m_sources;
    QMutex m_source_mutex;
    quint32 m_total_volume {};
    quint32 m_drained_volume {};
    quint32 m_loss_volume {};

private slots:
    void loadSources();
    void startDrain();
    void updateSource(qsizetype source_idx, quint32 amount);

};
#endif // MAINWINDOW_H
