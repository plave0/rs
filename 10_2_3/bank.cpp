#include "bank.h"

#include <QRandomGenerator>
#include <QDebug>

Bank::Bank()
{
    m_resources.resize(5, 0);
}

void Bank::generateResources(quint32 resources_to_alocate)
{
    quint32 left_to_alocate = resources_to_alocate;

    for(auto i = 0; i < 4; ++i) {
        m_resources[i] =
                QRandomGenerator::global()->bounded(
                    1u,
                    std::min(resources_to_alocate / 2 + 1, left_to_alocate + 1)
                    );
        left_to_alocate -= m_resources[i];
    }
    m_resources[4] = left_to_alocate;

    assert(m_resources[0] +
           m_resources[1] +
           m_resources[2] +
           m_resources[3] +
           m_resources[4]
           == resources_to_alocate
           );
}

void Bank::makeTransaction(size_t destination_node, qint32 amount)
{
    QMutexLocker resource_locker(&m_resources_lock);
    for(auto i = 0u; i < 5u; ++i) {
        if(i == destination_node) {
            m_resources[i] += 4 * amount;
        }
        else {
            m_resources[i] -= amount;
        }
    }
}
