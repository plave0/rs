#ifndef DRAINTHREAD_H
#define DRAINTHREAD_H

#include "source.h"

#include <QThread>
#include <QList>
#include <QMutex>

class DrainThread : public QThread
{
    Q_OBJECT

public:
    DrainThread(QList<Source>& sources, QMutex& sources_mutex);

protected:
    void run() override;

private:
    QList<Source>& m_sources;
    QMutex& m_sources_mutex;

signals:
    void drainedFromSource(qsizetype source_idx, quint32 amount);
};

#endif // DRAINTHREAD_H
