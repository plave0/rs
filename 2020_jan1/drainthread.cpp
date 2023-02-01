#include "drainthread.h"
#include "source.h"

#include <QList>
#include <QRandomGenerator>
#include <QMutex>
#include <QMutexLocker>

DrainThread::DrainThread(
        QList<Source>& sources,
        QMutex& sources_mutex
    ) :
    m_sources(sources),
    m_sources_mutex(sources_mutex)
{}

void DrainThread::run()
{

    bool thread_finished = false;
    while (!thread_finished) {

        msleep(QRandomGenerator::global()->bounded(5, 11) * 100);

        qsizetype random_index =
                QRandomGenerator::global()->bounded(m_sources.length());

        {
            QMutexLocker source_locker(&m_sources_mutex);

            Source& source_to_drain = m_sources[random_index];

            if(!source_to_drain.isDrained()) {
                quint32 amount_to_drain =
                        QRandomGenerator::global()->bounded(100, 201);
                quint32 amount_drained = source_to_drain.drainSource(amount_to_drain);
                emit drainedFromSource(random_index, amount_drained);

                if(source_to_drain.isDrained()) {
                    thread_finished = true;
                }
            }
        }
    }

}
